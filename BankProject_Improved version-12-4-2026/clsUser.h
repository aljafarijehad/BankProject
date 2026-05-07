#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "C:/Users/User/source/repos/StringLibraryProject/StringLibraryProject/clsString.h"
#include "clsPerson.h"
const string FileName = "Users.txt";
class clsUser : public clsPerson
{

private:
	enum  enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3
	};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUser;
		vUser = clsString::Split(Line, Seperator);
		return clsUser
		(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
	}

	static string _ConvertUserObjectToLine(clsUser& User, string Seperator = "#//#")
	{
		return User.FirstName + Seperator + User.LastName + Seperator + User.Email + Seperator + User.Phone
			+ Seperator + User._UserName + Seperator + User._Password + Seperator +
			to_string(User._Permissions);
	}

	

	static void _SaveUserDataToFile(vector <clsUser>& vUsers)
	{
		fstream file;
		file.open(FileName, ios::out); // rewrite mode


		if (file.is_open())
		{
			for (clsUser& user : vUsers)
			{
				if (user._MarkForDelete == false)
				{
					file << _ConvertUserObjectToLine(user) << endl;
				}
			}
		}
		file.close();
	}

	static vector <clsUser> _LoadUserDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open(FileName, ios::in); // read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vUsers.push_back(_ConvertLineToUserObject(Line));
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _AddDataLineToFile(string sLine)
	{
		fstream file;
		file.open(FileName, ios::app); // append mode
		if (file.is_open())
		{
			file << sLine << endl;
		}
		file.close();
	}


	void _Update()
	{
		vector <clsUser> vUsers;
		vUsers = _LoadUserDataFromFile();
		for (clsUser& user : vUsers)
		{
			if (user._UserName == this->_UserName)
			{
				user = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _Delete()
	{
		this->_MarkForDelete = true;
		_Update();
	}

public:

	enum  enPermissions
	{
		eAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactionMenu = 32, pManageUsers = 64
	};
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		this->_Mode = Mode;
		this->_UserName = UserName;
		this->_Password = Password;
		this->_Permissions = Permissions;
		this->_MarkForDelete = false;
	}

	bool IsEmpty()
	{
		return (this->_Mode == enMode::EmptyMode);
	}


	void SetUserName(string Username) { this->_UserName = Username; }
	string GetUserName() { return _UserName; }
	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password) { this->_Password = Password; }
	string GetPassword() { return _Password; }
	_declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions) { this->_Permissions = Permissions; }
	int GetPermissions() { return _Permissions; }
	_declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;



	static clsUser Find(string UserName)
	{
		vector <clsUser> vUsers = _LoadUserDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (UserName == User.UserName)
			{
				return User;
			}
		}
		return GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Password)	
	{
		vector <clsUser> vUsers = _LoadUserDataFromFile();
		for (clsUser& User : vUsers)
		{
			if (UserName == User.UserName && Password == User.Password)
			{
				return User;
			}
		}
		return GetEmptyUserObject();
	}


	enum enSaveResults
	{
		svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberNotExists = 2
	};

	enSaveResults Save()
	{
		switch (this->_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			// this will add new record to file or database 
			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFaildEmptyObject;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		case enMode::DeleteMode:
		{
			if (!clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFaildEmptyObject;
			}
			else
			{
				this->_Delete();
				//We need to set the mode to update after add new
				return enSaveResults::svSucceeded;
			}
		}
		}/// end switch case
	} ///end of save function

	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static void GetDeleteUserObject (string UserName)
	{
		clsUser User = Find(UserName);
		if (User.IsEmpty())
		{
			return;
		}
		User._Mode = enMode::DeleteMode;
		User.Save();
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}
	static clsUser GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;
		if ((this->Permissions & Permission) == Permission)
			return true;
		else 
			return false;
	}

};

#pragma once
#include <iostream>
#include <string>
#include <iomanip>  // Required for setw
#include "clsDate.h"
#include "clsUtil.h";
#include "clsInputValidate.h"
#include "C:/Users/User/source/repos/StringLibraryProject/StringLibraryProject/clsString.h"
#include "clsPerson.h"
#include <fstream>

using namespace std;
const string ClientFile = "Clients.txt";
class clsBankClient : public clsPerson
{
private:

	enum  enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 ,DeleteMode = 3 
	};
	
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete;

	static clsBankClient _ConvertLineToClientObject(string Line)
	{
		vector <string> vClients;
		vClients = clsString::Split(Line, "#//#");
		return clsBankClient(enMode::UpdateMode, vClients[0], vClients[1], vClients[2], vClients[3], vClients[4], vClients[5], stod(vClients[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient& Client, string Seperator = "#//#")
	{
		return Client.FirstName + Seperator + Client.LastName + Seperator
			+ Client.Email + Seperator + Client.Phone + Seperator + Client.AccountNumber() +
			Seperator + Client.PinCode + Seperator + to_string(Client.AccountBalance);
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(clsBankClient::EmptyMode, "", "", "", "", "", "", 0.000);
	}

	static void _SaveClientDataToFile(vector <clsBankClient>& vClients)
	{
		fstream file;
		file.open(ClientFile, ios::out); // rewrite mode

		string DataLine;
		if (file.is_open())
		{
			for (clsBankClient& client : vClients)
			{
				if (client._MarkForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(client);
					file << DataLine << endl;
				}
			}
			file.close();
		}
	}

	static vector <clsBankClient> _LoadClientDateFromFile()
	{
		fstream file;
		file.open(ClientFile, ios::in); // read mode
		vector <clsBankClient> vClientsRecords;

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				vClientsRecords.push_back(_ConvertLineToClientObject(line));
			}
			file.close();
		}
		return vClientsRecords;
	}
	
	static void _AddDataLineToFile(const string& sLine)
	{
		fstream file;
		file.open(ClientFile, ios::app); // append mode 

		if (file.is_open())
		{
			file << sLine << endl;
		}
		file.close();
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientDateFromFile();

		for (clsBankClient& client : _vClients)
		{
			if (client.AccountNumber() == this->AccountNumber())
			{
				client = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}

	void _AddNew() {
		_AddDataLineToFile (_ConvertClientObjectToLine(*this));
	}

	bool _Delete() 
	{
		vector <clsBankClient> _vClinets;
		_vClinets = _LoadClientDateFromFile();

		bool Founded = false;
		for (clsBankClient& client : _vClinets)
		{
			if (client.AccountNumber() == this->AccountNumber())
			{
				client._MarkForDelete = true;
				Founded = true;
				break;
			}
		}

		if (Founded == false)
		{
			return false;
		}

		_SaveClientDataToFile(_vClinets);
		*this = _GetEmptyClientObject();

		return true;
	}
public:

	clsBankClient (enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance , bool MarkForDelete  = false) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_MarkForDelete = MarkForDelete;
	}

	bool IsEmpty()
	{
		return (this->_Mode == enMode::EmptyMode);
	}

	string AccountNumber() { return _AccountNumber; }

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	/**
	 *
	 */
	 __declspec(property (get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property (get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	// NO UI Related Code inside object 
	void Print()
	{
		cout << "\nClient Card : ";
		cout << "\n_________________________________________";
		cout << "\n\tFirst Name :" << FirstName;
		cout << "\n\tLast Name  :" << LastName;
		cout << "\n\tFull Name  :" << FullName();
		cout << "\n\tEmail      :" << Email;
		cout << "\n\tPhone      :" << Phone;
		cout << "\n\tAcc. Number:" << AccountNumber();
		cout << "\n\tPassword   :" << PinCode;
		cout << "\n\tBalance    :" << to_string(AccountBalance);
		cout << "\n_________________________________________";
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);// read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	enum enSaveResults 
	{
		svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberNotExists = 2 
	};
	
	/*
	* return if the data saved to file successfully neither no
	because the object it's mode is enMode::EmptyMode .
	*/
	enSaveResults Save()
	{
		switch (this->_Mode)
		{

			case enMode::EmptyMode :
			{
				return enSaveResults::svFaildEmptyObject;
			}
			case enMode::UpdateMode :
			{
				_Update ();
				return enSaveResults::svSucceeded;
			}
			case enMode::AddNewMode :
			{
				// this will add new record to file or database 
				if (clsBankClient::IsClientExist(AccountNumber()))
				{
					return enSaveResults::svFaildEmptyObject;
				}
				else
				{
					_AddNew();
					//We need to set the mode to update after add new
					this->_Mode = enMode::UpdateMode;
					return enSaveResults::svSucceeded;
				}
			}
			case enMode::DeleteMode:
			{
				if (!clsBankClient::IsClientExist(AccountNumber()))
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
		}
	} 
	
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	// Move this proseger to clsAddNewClientScreen.h , cause NO UI Related Code inside object . 

	static clsBankClient GetAddNewClientObject (string AccountNumber) 
	{
		return clsBankClient(enMode::AddNewMode, "", "", "","", AccountNumber,"", 0.00);
	}
	
	void GetDeleteClientObject() 
	{
		_Mode = enMode::DeleteMode;
	}


	// NO UI Related Code inside object 


	static vector<clsBankClient> GetClientsList() {

		return _LoadClientDateFromFile();
	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		_Update();
	}

	void Withdraw(double Amount)
	{
		AccountBalance -= Amount;
		_Update();
	}

	static void PrintClientRecord(clsBankClient client)
	{
		cout << "| " << left << setw(15) << client.AccountNumber();
		cout << "| " << left << setw(20) << client.FullName();
		cout << "| " << left << setw(12) <<client.Phone;
		cout << "| " << left << setw(20) << client.Email;
		cout << "| " << left << setw(10) << client.PinCode;
		cout << "| " << left << setw(12) << client.AccountBalance;
		cout << "\n";
	}

	static void ShowClientList()
	{
		vector <clsBankClient> vClients = GetClientsList();
		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s) . " << endl;
		cout << endl << std::string(100, '-') << endl;
		cout << "| " << left << setw(15) << "Account Number ";
		cout << "| " << left << setw(20) << "Client Name ";
		cout << "| " << left << setw(12) << "Phone ";
		cout << "| " << left << setw(20) << "Email ";
		cout << "| " << left << setw(10) << "Pin Code ";
		cout << "| " << left << setw(12) << "Balance ";
		cout << "\n";
		cout << endl << std::string(100, '-') << endl;


		if (vClients.size() == 0) { cout << "\t\t\t\t\t NO CLIENT ARE A AVALIBLE IN THE LIST !\n"; }

		
		for (const clsBankClient& C : vClients)
		{
			PrintClientRecord(C);
		}

		cout << endl << std::string(100, '-') << endl;

	}

	static double GetTotalBalance()
	{
		vector <clsBankClient> vClients = GetClientsList();

		double TotalBalance = 0;
		for (clsBankClient& C : vClients)
		{
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	static void PrintClientTotalBalance(clsBankClient client) 
	{
		cout << "| " << left << setw(35) << client.AccountNumber();
		cout << "| " << left << setw(35) << client.FullName();
		cout << "| " << left << setw(30) << client.AccountBalance;
		cout << "\n";
	}

	static void  ShowTotalBalance() 
	{
		vector <clsBankClient> vClients = GetClientsList();
		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s) . " << endl;
		cout << endl << std::string(100, '-') << endl;
		cout << "| " << left << setw(35) << "Account Number ";
		cout << "| " << left << setw(35) << "Client Name ";
		cout << "| " << left << setw(30) << "Balance ";
		cout << "\n";
		cout << endl << std::string(100, '-') << endl;

		if (vClients.size() == 0) { cout << "\t\t\t\t\t NO CLIENT ARE A AVALIBLE IN THE LIST !\n"; }

		double TotalBalance = GetTotalBalance();


		for (const clsBankClient& client : vClients)
		{
			PrintClientTotalBalance(client);
		}
		cout << "\n\t\tTotal Balance : " << TotalBalance << "(" << clsUtil::NumberToText(TotalBalance) << " ) " << endl;
	}


};

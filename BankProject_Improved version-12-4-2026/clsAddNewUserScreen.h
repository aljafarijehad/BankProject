#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsAddNewUserScreen : protected clsScreen
{

	private :

		static void _ReadUserInfo(clsUser &User)
		{
			cout << "\nFirst Name :";
			User.FirstName = clsInputValidate::ReadString();
		
			cout << "\nLast Name :";
			User.LastName = clsInputValidate::ReadString();

			cout << "\nEmail :";
			User.Email = clsInputValidate::ReadString();

			cout << "\nPhone :";
			User.Phone = clsInputValidate::ReadString();

			cout << "\nPassword :";
			User.Password = clsInputValidate::ReadString();

			cout << "\nPermissions :";
			User.Permissions = _ReadUserPermissions();
		}

		static void _PrintUserRecord(clsUser C)
		{
			cout << "\nThe following Added Client Card Info : ";
			cout << "\n_________________________________________";
			cout << "\n\tFirst Name :" << C.FirstName;
			cout << "\n\tLast Name  :" << C.LastName;
			cout << "\n\tFull Name  :" << C.FullName();
			cout << "\n\tEmail      :" << C.Email;
			cout << "\n\tPhone      :" << C.Phone;
			cout << "\n\tUser Name  :" << C.UserName;
			cout << "\n\tPassword   :" << C.Password;
			cout << "\n\tPermissions:" << C.Permissions;
			cout << "\n_________________________________________";
		}

		static int _ReadUserPermissions()
		{
			int Permissions = 0;
			char Choice = 'n';
			cout << "\nDo you want to give this user full access on permissions (Y/N) : ";
			cin >> Choice;
			if (Choice == 'Y' || Choice == 'y')
			{
				return clsUser::enPermissions::eAll;
			}
			else
			{
				cout << "\nDo you want to give this user permission to list clients (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pListClient;

				cout << "\nDo you want to give this user permission to add new clients (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pAddNewClient;

				cout << "\nDo you want to give this user permission to delete clients (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pDeleteClient;

				cout << "\nDo you want to give this user permission to update clients (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pUpdateClient;
				
				cout << "\nDo you want to give this user permission to find clients (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pFindClient;

				cout << "\nDo you want to give this user permission to access transaction menu (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pTransactionMenu;

				cout << "\nDo you want to give this user permission to manage users (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pManageUsers;

				cout << "\nDo you want to give this user permission to show login history (Y/N) : ";
				cin >> Choice;
				if (Choice == 'Y' || Choice == 'y')
					Permissions |= clsUser::enPermissions::pShowLoginHistory;
			}

			return Permissions;
		}

	public :


		static void ShowAddNewUserScreen()
		{
			_DrawScreenHeader("\t   Add New User Screen ");
			
			string Username = "";
			cout << "Enter Username : ";
			Username = clsInputValidate::ReadString();

			while (clsUser::IsUserExist(Username))
			{
				cout << "\nUsername Is Already Used , Choose another one :";
				Username = clsInputValidate::ReadString();
			}
			
			clsUser NewUser = clsUser::GetAddNewUserObject(Username);

			_ReadUserInfo(NewUser);

			clsUser::enSaveResults SaveResult = NewUser.Save();

			switch (SaveResult)
			{
				case clsUser::enSaveResults::svFaildEmptyObject:
				{
					cout << "\nFailed to add new user because the user object is empty " << endl;
					break;
				}
				case clsUser::enSaveResults::svSucceeded:
				{
					cout << "\nUser added successfully " << endl;
					_PrintUserRecord(NewUser);
					break;
				}
				case clsUser::enSaveResults::svFaildAccountNumberNotExists:
				{
					cout << "\nFailed to add new user because the user name is already exist in the system " << endl;
					break;
				}
			}

		}


};


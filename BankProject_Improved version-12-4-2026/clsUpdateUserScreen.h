#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsUpdateUserScreen : protected clsScreen
{

	private :
		static void _ReadUserInfo(clsUser& User)
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
			}

			return Permissions;
		}

	public :
		static void ShowUpdateUserScreen() {
		
			clsScreen::_DrawScreenHeader("\t  Update User Screen ");
			string Username = "";
			cout << "\nPlease Enter User Name :";
			Username = clsInputValidate::ReadString();

			while (!clsUser::IsUserExist(Username))
			{
				cout << "\nUsername Is Not Found , Choose another one :";
				Username = clsInputValidate::ReadString();
			}

			clsUser UserToUpdate = clsUser::Find(Username);
			_PrintUserRecord(UserToUpdate);
			char answer = 'n';	
			cout << "\nAre you sure that you want to update this user ?y/n? ";
			cin >> answer;

			if (tolower(answer) == 'y')
			{
				cout << "\nPlease enter new data for this user : \n";
				_ReadUserInfo(UserToUpdate);
				clsUser::enSaveResults SaveResult = UserToUpdate.Save();

				switch (SaveResult)
				{	
					case clsUser::svFaildEmptyObject:
					{
						cout << "\nFailed to update user because the user data is empty !\n\n";
						break;
					}
					case clsUser::svSucceeded:
					{
						cout << "\nAccount Updated Successfully :-) \n";
						_PrintUserRecord(UserToUpdate);
						break;
					}
					case clsUser::svFaildAccountNumberNotExists:
					{
						cout << "\nFailed to update user because the user does not exists !\n\n";
						break;
					}
				}
			}
			else
			{
				cout << "\n\nThe Process Canceled ! " << endl;
			}



		}


};


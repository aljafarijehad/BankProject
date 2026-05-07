#pragma once
#include "clsScreen.h"
#include "clsUser.h" 
#include "clsInputValidate.h"
class clsDeleteUserScreen :protected clsScreen
{

	private :
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


	public :

		static void ShowDeleteUserScreen()
		{
			clsScreen::_DrawScreenHeader("\t  Delete User Screen ");
			string UserName = "";
			cout << "\nPlease Enter User Name :";
			UserName = clsInputValidate::ReadString();
			
			while (!clsUser::IsUserExist(UserName))
			{
				cout << "User with User Name not founded , please enter another : ";
				UserName = clsInputValidate::ReadString();
			}

			clsUser UserToDelete = clsUser::Find(UserName);

			// Print Client Record before deleted 
			_PrintUserRecord(UserToDelete);

			cout << "\nAre you sure that you want to delete this user ?y/n? ";
			char Answer = 'n';
			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				UserToDelete.GetDeleteUserObject(UserName);

				clsUser::enSaveResults SaveResult = UserToDelete.Save();
				
				switch (SaveResult)
				{
					case clsUser::enSaveResults::svSucceeded:
					{
						printf("User %s Deleted Successfully :-) \n\n", UserName.c_str());
						UserToDelete = clsUser::GetEmptyUserObject();
						_PrintUserRecord(UserToDelete);
						break;
					}
					case clsUser::enSaveResults::svFaildEmptyObject:
					{
						cout << "\nFailed to delete user because the user data is empty !\n\n";
						break;
					}
					case clsUser::enSaveResults::svFaildAccountNumberNotExists:
					{
						cout << "\nFailed to delete user because user name does not exist !\n\n";
						break;
					}
					default:
						break;
					}
			}
		}

};


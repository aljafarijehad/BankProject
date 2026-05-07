#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
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
		static void ShowFindUserScreen()
		{
			clsScreen::_DrawScreenHeader("\t  Find User Screen ");
			string UserName = "";
			cout << "\nPlease Enter User Name : ";
			UserName = clsInputValidate::ReadString();
			while (!clsUser::IsUserExist(UserName))
			{
				cout << clsColor::GetColor(clsColor::enRed) 
					<<"User Name "<< UserName<< " is not found, try again : " 
					<< clsColor::GetColor(clsColor::enReset);
				UserName = clsInputValidate::ReadString();
			}

			clsUser user = clsUser::Find(UserName);


			if (!user.IsEmpty())
			{
				cout << clsColor::GetColor(clsColor::enGreen)
					<< "\nUser found :-) " 
					<< clsColor::GetColor(clsColor::enReset) 
					<< endl;
			}
			else 
			{
				cout << clsColor::GetColor(clsColor::enRed) 
					<< "User not found :-( " 
					<< clsColor::GetColor(clsColor::enReset) 
					<< endl;
			}

			_PrintUserRecord(user);

		
		}
};


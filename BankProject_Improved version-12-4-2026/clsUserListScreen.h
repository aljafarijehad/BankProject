#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
class clsUserListScreen : protected clsScreen
{
	private :
		
		static void _PrintUserRecordLine(clsUser User)
		{
			cout << setw(8) << left << ""
				<< "| " << setw(20) << left << User.FullName()
				<< "| " << setw(20) << left << User.Email
				<< "| " << setw(12) << left << User.Phone
				<< "| " << setw(10) << left << User.UserName 
				<< "| " << setw(10) << left << User.Password 
				<< "| " << setw(10) << left << to_string(User.Permissions)
				 << "| "<< endl;
		}
	
	public:

		static void ShowUserListScreen()
		{
			string Title = "\t  User List Screen ";
			string SubTitle = "\t     (" + to_string(clsUser::GetUsersList().size()) + ") User(s)";

			clsScreen::_DrawScreenHeader(Title, SubTitle);

			cout << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

			cout << setw(8) << left << "" << "| " << left << setw(20) << "Full Name ";
			cout << "| " << setw(20) << left << "Email";
			cout << "| " << setw(12) << left << "Phone";
			cout << "| " << setw(10) << left << "User Name";
			cout << "| " << setw(10) << left << "Password";
			cout << "| " << setw(10) << left << "Permissions";
			cout << "| ";

			cout << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

			if (clsUser::GetUsersList().size() == 0)
				cout << "\t\t\t\t No Available User in the system " << endl;
			else
			{
				for (const clsUser& v : clsUser::GetUsersList())
				{
					_PrintUserRecordLine(v);
				}
			}

			cout << "\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}
};


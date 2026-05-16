#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsLogInScreen.h"
//#include "Global.h"
class clsManageUsersScreen : protected clsScreen
{
private :

	enum  enManageUserMenueOption 
	{
		enListUsers = 1, enAddNewUser = 2, enUpdateUser = 3, enDeleteUser = 4, enFindUser = 5 ,
		enBackToMainMenue = 6
	};

	static void _ShowListUsersScreen()
	{
		 // cout << "List Users Screen will be here ... " << endl;
			clsUserListScreen::ShowUserListScreen();
	}
	
	static void _ShowAddNewUserScreen()
	{
	 //	cout << "Add New User Screen will be here ... " << endl;
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		 //	cout << "Delete User Screen will be here ... " << endl;
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "Update User Screen will be here ... " << endl;
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	
	static void _ShowFindUserScreen()
	{
		//cout << "Find User Screen will be here ... " << endl;
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToTransactionMenue ()
	{
		cout << "\nPress any key to go back to Manage Users Menue ... " << endl;
		system("pause>0");
		system("cls");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(short ManageUsersMenueOption) 
	{
		if (ManageUsersMenueOption == enManageUserMenueOption::enBackToMainMenue)
		{
			return;
		}
		switch (ManageUsersMenueOption)
		{
			case enManageUserMenueOption::enListUsers :
			{
				system("cls");
				_ShowListUsersScreen();
				_GoBackToTransactionMenue();
				break;

			}
			case enManageUserMenueOption::enAddNewUser :
			{
				system("cls");
				_ShowAddNewUserScreen();
				_GoBackToTransactionMenue();
				break;

			}
			case enManageUserMenueOption::enDeleteUser :
			{
				system("cls");
				_ShowDeleteUserScreen();
				_GoBackToTransactionMenue();
				break;

			}
			case enManageUserMenueOption::enUpdateUser :
			{
				system("cls");
				_ShowUpdateUserScreen();
				_GoBackToTransactionMenue();
				break;

			}
			case enManageUserMenueOption::enFindUser :
			{
				system("cls");
				_ShowFindUserScreen();
				_GoBackToTransactionMenue();
				break;
			}
			case enManageUserMenueOption::enBackToMainMenue :
			{
				break;
			}
		}

	}

	static short ReadManageUsersMenueOption()
	{
		cout << setw(37) <<left << "" << "Choose what do you want to do? [1 to 6] ?";
		short ManageUsersMenueOption = clsInputValidate::ReadIntNumberBetween(1, 6);
		return ManageUsersMenueOption;
	}

public :

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\tManage Users Menue Screen ");

		_FormatString("===========================================", clsScreen::enAlign::eCenter);
		_FormatString("\t\t\  Manage User Screen", clsScreen::enAlign::eCenter);
		_FormatString("===========================================", clsScreen::enAlign::eCenter);

		_FormatString("\t[1] List User Screen ", clsScreen::enAlign::eCenter);
		_FormatString("\t[2] Add New User Screen ", clsScreen::enAlign::eCenter);
		_FormatString("\t[3] Update User Screen  ", clsScreen::enAlign::eCenter);
		_FormatString("\t[4] Delete User Screen", clsScreen::enAlign::eCenter);
		_FormatString("\t[5] Find User Screen ", clsScreen::enAlign::eCenter);
		_FormatString("\t[6] Back To Main Menue ", clsScreen::enAlign::eCenter);
		_FormatString("===========================================", clsScreen::enAlign::eCenter);


		int ManageUsersMenueOption = ReadManageUsersMenueOption();

		_PerformManageUsersMenueOption(ManageUsersMenueOption);
	}


};


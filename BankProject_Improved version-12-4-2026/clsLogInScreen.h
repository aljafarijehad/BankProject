#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
class clsLogInScreen : protected clsScreen
{
private:
	static void _LogIn()
	{
		bool LoginFaild = false;
		string UserName = "", Password = "";

		do
		{
			if (LoginFaild)
				cout << setw(37) << left << clsColor::GetColor(clsColor::enRed)
				<< "\tIncorrect User Name or Password , try again : "
				<< clsColor::GetColor(clsColor::enReset) << endl;

			cout << setw(37) << left << "" << "\tEnter User Name :";
			cin >> UserName;

			cout << setw(37) << left << "" << "\tEnter Password :";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		cout << "\nWelcome "
			<< clsColor::GetColor(clsColor::enGreen)
			<< CurrentUser.FullName()
			<< clsColor::GetColor(clsColor::enReset)
			<< " :-)\n\n";

		system("pause");

		system("cls");

		clsMainScreen::ShowMainMenuScreen();

	}


public:

	static void ShowLogInScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Log In Screen ");
		_LogIn();
	}
};


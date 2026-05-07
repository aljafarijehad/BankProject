#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsLoginLogger.h" // for logging login attempts
class clsLogInScreen : protected clsScreen
{
private:
	static bool _LogIn()
	{
		bool LoginFaild = false;
		string UserName = "", Password = "";
		int counter = 0;
		do
		{
			counter++;

		
			cout << setw(37) << left << "" << "\tEnter User Name :";
			cin >> UserName;

			cout << setw(37) << left << "" << "\tEnter Password :";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

			if (LoginFaild)
				cout << setw(37) << left << clsColor::GetColor(clsColor::enRed)
				<< "\tIncorrect User Name/Password , you have " << 3 - counter << " attempts left : "
				<< clsColor::GetColor(clsColor::enReset) << endl;

		} while (LoginFaild && (counter < 3));
		
		if (LoginFaild)
		{
			cout << clsColor::GetColor(clsColor::enRed)
				<< "\nToo many failed login attempts. Exiting...\n"
				<< clsColor::GetColor(clsColor::enReset);
			return false;
		}

		cout << "\nWelcome "
			<< clsColor::GetColor(clsColor::enGreen)
			<< CurrentUser.FullName()
			<< clsColor::GetColor(clsColor::enReset)
			<< " :-)\n\n";

		system("pause");

		system("cls");

		clsLoginLogger::SaveLoginToLog(CurrentUser);

		clsMainScreen::ShowMainMenuScreen();

	}



public:

	static bool ShowLogInScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Log In Screen ");
		return _LogIn();
	}
};


#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
class clsLoginLogerScreen : protected clsScreen
{
private :

	static void _PrintLoginLogerRecord(const string &Line)
	{
		vector <string> vLoginRecord;
		vLoginRecord = clsString::Split(Line, "#//#");

		cout << setw(8) << left << "" << "| " << setw(35) << left << vLoginRecord[0];
		cout << "| " << setw(20) << left << vLoginRecord[1];
		cout << "| " << setw(10) << left << vLoginRecord[2];
	}


public :
	static void ShowLoginLogerScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pShowLoginHistory))
		{
			return;
		}

		vector <string> vLoginLoger = clsUser::GetLoginLoggerList();
		string Title = "\t  Login Logger Screen ";
		string SunbTitle = "\t    "+to_string(vLoginLoger.size())  + " Record(s) .";
		clsScreen::_DrawScreenHeader(Title, SunbTitle);

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(35) << left << "Date And Time";
		cout << "| " << setw(20) << left << "Username";
		cout << "| " << setw(10) << left << "Permissions";


		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		for (const string& record : vLoginLoger)
		{
			_PrintLoginLogerRecord(record);
			cout << "\n";
		}

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		


	}

};


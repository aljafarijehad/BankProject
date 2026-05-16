#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
	private :
		static void _PrintClientRecordLine (clsBankClient Client)
		{
			cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
			cout << "| " << setw(20) << left << Client.FullName();
			cout << "| " << setw(12) << left << Client.Phone;
			cout << "| " << setw(20) << left << Client.Email;
			cout << "| " << setw(10) << left << Client.PinCode;
			cout << "| " << setw(12) << left << Client.AccountBalance;
			cout << endl;
		}
	
	public:

		static void ShowClientList()
		{
			if (!CheckAccessRights(clsUser::enPermissions::pListClient))
			{
				return;
			}
			vector <clsBankClient> vClients = clsBankClient::GetClientsList();
			string Title = "\t  Client List Screen ";
			string SubTitle = "\t     (" + to_string(vClients.size()) + ") Client(s)";
			
			clsScreen::_DrawScreenHeader(Title, SubTitle);

	
			cout  << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

			cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number ";
			cout << "| " << setw(20) << left << "Client Name";
			cout << "| " << setw(12) << left << "Phone";
			cout << "| " << setw(20) << left << "Email";
			cout << "| " << setw(10) << left << "Pin Code";
			cout << "| " << setw(12) << left << "Balance";


			cout << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;


			if (vClients.size() == 0)
				cout << "\t\t\t\t No Available Client in the system " << endl;
			else 
			{
				for (const clsBankClient& v : vClients)
				{
					_PrintClientRecordLine(v);
				}
			}

			cout << "\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}

};
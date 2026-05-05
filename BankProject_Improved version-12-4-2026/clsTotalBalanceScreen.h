#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTotalBalanceScreen : protected clsScreen
{

		private :

			static void _PrintClientRecord(clsBankClient client)
			{
				cout << setw(8) << left << "" << "| " << left << setw(35) << client.AccountNumber();
				cout << "| " << left << setw(35) << client.FullName();
				cout << "| " << left << setw(30) << client.AccountBalance;
				cout << "\n";
			}


		public :

			static void ShowTotalBalanceScreen()
			{
					vector <clsBankClient> vClients = clsBankClient::GetClientsList();

					string Title = "\t  Total Balance Screen ";
					string SubTitle = "\t     (" + to_string(vClients.size()) + ") Client(s)";

					clsScreen::_DrawScreenHeader(Title, SubTitle);
			
					cout << "\n" << setw(8) << left << "" << "_______________________________________________________";
					cout << "_________________________________________\n" << endl;


					cout << setw(8) << left << "" << "| " << left << setw(35) << "Account Number ";
					cout << "| " << left << setw(35) << "Client  ";
					cout << "| " << left << setw(30) << "Balance ";

					cout << "\n" << setw(8) << left << "" << "_______________________________________________________";
					cout << "_________________________________________\n" << endl;



					if (vClients.size() == 0) { cout << "\t\t\t\t\t NO CLIENT ARE A AVALIBLE IN THE LIST !\n"; }

				  	double TotalBalance = clsBankClient::GetTotalBalance();


					for (const clsBankClient& client : vClients)
					{
						_PrintClientRecord(client);
					}

					cout <<  setw(8) << left << "" << "_______________________________________________________";
					cout << "_________________________________________\n" << endl;


					cout << "\n\t\tTotal Balance : " << TotalBalance 
						<< "  (" << clsUtil::NumberToText(TotalBalance) << ")  ." << endl;
			}

};


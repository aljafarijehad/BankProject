#pragma once
#include <iostream>
//#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include"clsBGBankSystem.h"
#include "clsTransactionMenuScreen.h"
#include "clsManageUsersScreen.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
	private:

		enum enMainMenuOptions {

			eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eFindClient = 4,
			eUpdateClient = 5, eTransactionMenu = 6, eManageUser = 7, eLogOut = 8
		};

		static void _ShowListClientsScreen ()
		{
			// cout << "Client List Screen  , will be here " << endl;
			clsClientListScreen::ShowClientList();
			system("pause>0");
		}

		static void _ShowAddNewClientScreen()
		{
			// cout << "Add New Client Screen , will be here " << endl;
			clsAddNewClientScreen::ShowAddNewClientScreen();
		}

		static void _ShowDeleteClientScreen()
		{
			 // cout << "Delete Client Screen , will be here " << endl;
			clsDeleteClientScreen::ShowdDeleteClientScreen();
		}

		static void _ShowFindClientScreen()
		{
		 // 	cout << "Find Client Screen , will be here " << endl;
			clsFindClientScreen::ShowFindClientScreen();
		}

		static void _UpdateNewClientScreen()
		{
			//cout << "Update Client Screen , will be here " << endl;
			clsUpdateClientScreen::ShowUpdateClientScreen();
		}

		static void _ShowTransactionMenuScreen()
		{
			//cout << "Transaction Menu Screen , will be here" << endl;
			clsTransactionMenuScreen::ShowTransactionMainMenueScreen();
		}

		static void _ShowManageUserMenuScreen() 
		{
			 // cout << "Manage User Menu Screen , will be here " << endl;
			clsManageUsersScreen::ShowManageUsersMenue();
		}

		static int _ReadMenuOption()
		{
			cout << setw(37) << left << "" << "Choose what do you want to do [1 to 8]? ";
			int Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
			return Choice;
		}

		static void _GoBackToMainMenu ()
		{
			cout << "\nPress Any Key to go back to Main Menu ...";
			system("pause>0");
			ShowMainMenuScreen();
		}

		static void _PerfromMainMenuOption (enMainMenuOptions MainMenuOption)
		{
			switch (MainMenuOption)
			{
				case enMainMenuOptions::eListClients:
				{
					system("cls");
					_ShowListClientsScreen();
					_GoBackToMainMenu();
				}
				case enMainMenuOptions::eAddNewClient:
				{
					system("cls");
					_ShowAddNewClientScreen();
					_GoBackToMainMenu();
				}
				case enMainMenuOptions::eDeleteClient:
				{
					system("cls");
					_ShowDeleteClientScreen();
					_GoBackToMainMenu();
				}
				case enMainMenuOptions::eFindClient:
				{
					system("cls");
					_ShowFindClientScreen();
					_GoBackToMainMenu();
				}
				case enMainMenuOptions::eUpdateClient:
				{
					system("cls");
					_UpdateNewClientScreen();
					_GoBackToMainMenu();
				}
				case enMainMenuOptions::eTransactionMenu:
				{
					system("cls");
					_ShowTransactionMenuScreen();
					_GoBackToMainMenu();
				}
				case enMainMenuOptions::eManageUser:
				{
					system("cls");
					_ShowManageUserMenuScreen();
					_GoBackToMainMenu();
				}

				case enMainMenuOptions::eLogOut:
				{
					system("cls");
					//LogIn()l
				}

			} // end switch case 

		}


	public :

		static void ShowMainMenuScreen()
		{ 
			 system("cls");
			_DrawScreenHeader("\t\tMain Screen");

			_FormatString("===========================================", clsScreen::enAlign::eCenter);
			_FormatString("\t\t\tMain Menu", clsScreen::enAlign::eCenter);
			_FormatString("===========================================", clsScreen::enAlign::eCenter);

			_FormatString("\t[1] Show Client List ", clsScreen::enAlign::eCenter);
			_FormatString("\t[2] Add New Client ", clsScreen::enAlign::eCenter);
			_FormatString("\t[3] Delete Client ", clsScreen::enAlign::eCenter);
			_FormatString("\t[4] Find Client ", clsScreen::enAlign::eCenter);
			_FormatString("\t[5] Update Client ", clsScreen::enAlign::eCenter);

			_FormatString("\t[6] Transactions ", clsScreen::enAlign::eCenter);
			_FormatString("\t[7] Manage User", clsScreen::enAlign::eCenter);
			_FormatString("===========================================", clsScreen::enAlign::eCenter);

			_PerfromMainMenuOption(enMainMenuOptions(_ReadMenuOption()));

		}

};
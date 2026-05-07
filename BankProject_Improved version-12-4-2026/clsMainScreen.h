#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenuScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include"clsColor.h"
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

		static void _LogOut()
		{
			//cout << "Log Out , will be here " << endl;
			CurrentUser = clsUser::Find("", "");
		}

		static int _ReadMenuOption()
		{
			cout << setw(37) << left << "" << "Choose what do you want to do [1 to 8]? ";

			int Choice = clsInputValidate::ReadIntNumberBetween
			(1, 8, "Enter Number between 1 to 8? ");

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
					break;

				}
				case enMainMenuOptions::eAddNewClient:
				{
					system("cls");
					_ShowAddNewClientScreen();
					_GoBackToMainMenu();
					break;

				}
				case enMainMenuOptions::eDeleteClient:
				{
					system("cls");
					_ShowDeleteClientScreen();
					_GoBackToMainMenu();
					break;

				}
				case enMainMenuOptions::eFindClient:
				{
					system("cls");
					_ShowFindClientScreen();
					_GoBackToMainMenu();
					break;

				}
				case enMainMenuOptions::eUpdateClient:
				{
					system("cls");
					_UpdateNewClientScreen();
					_GoBackToMainMenu();
					break;

				}
				case enMainMenuOptions::eTransactionMenu:
				{
					system("cls");
					_ShowTransactionMenuScreen();
					_GoBackToMainMenu();
					break;

				}
				case enMainMenuOptions::eManageUser:
				{
					system("cls");
					_ShowManageUserMenuScreen();
					_GoBackToMainMenu();
					break;

				}

				case enMainMenuOptions::eLogOut:
				{
					system("cls");
					_LogOut();
					break;
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
			_FormatString("\t[8] Log Out", clsScreen::enAlign::eCenter);
			_FormatString("===========================================", clsScreen::enAlign::eCenter);

			_PerfromMainMenuOption(enMainMenuOptions(_ReadMenuOption()));

		}

};
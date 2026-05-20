#pragma once
#include <iomanip>	
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
using namespace std;

class clsTransactionMenuScreen : protected clsScreen 
{

	private :

		enum enManageUserMenueOption {
			enDeposit = 1 , enWithdraw = 2 , enTotalBalance = 3 , enTransfer = 4 , enBackToMainMenue = 5
		};

		static void _ShowDepositScreen()
		{
			/*cout << "Deposit Screen will be here ..." << endl;*/
			clsDepositScreen::ShowDepositScreen();
		}
		
		static void _ShowWithdrawScreen() 
		{
			 // cout << "Withdraw Screen will be here ..." << endl;
			clsWithdrawScreen::ShowWithdrawScreen();
		}
		
		static void _ShowTotalBalanceScreen () 
		{
		//	cout << "Total Balance Screen will be here ..." << endl;
			clsTotalBalanceScreen::ShowTotalBalanceScreen();
		}

		static void _ShowTransferScreen() 
		{
			//cout << "Transfer Screen will be here ..." << endl;
			clsTransferScreen::ShowTransferScreen();
		}
		
		static short ReadTransactionMenuOption () {
	
			cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
			short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
			return Choice;

		}

		static void _GoBackToTransactionMenueScreen() 
		{
			cout << "\n Press Any Key to go back to Transaction Menue ... ";
			system("pause>0");
			ShowTransactionMainMenueScreen();
		}

		static void _PerfromTransactionMenue(enManageUserMenueOption Option)
		{
			switch (Option)
			{
				case enManageUserMenueOption::enDeposit:
				{
					system("cls");
					_ShowDepositScreen();
					_GoBackToTransactionMenueScreen();
					break;
				}
				case enManageUserMenueOption::enWithdraw:
				{
					system("cls");
					_ShowWithdrawScreen();
					_GoBackToTransactionMenueScreen();
					break;
				}
				case enManageUserMenueOption::enTotalBalance:
				{
					system("cls");
					_ShowTotalBalanceScreen();
					_GoBackToTransactionMenueScreen();
					break;
				}
				case enManageUserMenueOption::enTransfer :
				{
					system("cls");
					_ShowTransferScreen();
					_GoBackToTransactionMenueScreen();
					break;
				}
				case enManageUserMenueOption::enBackToMainMenue:
				{
					break;
				}
			}
		}
	
	public :

		static void ShowTransactionMainMenueScreen() 
		{
			if (!CheckAccessRights(clsUser::enPermissions::pTransactionMenu))
			{
				return;
			}

			system("cls");
			clsScreen::_DrawScreenHeader("\t Transaction Menue Screen ");
		

			_FormatString("===========================================", clsScreen::enAlign::eCenter);
			_FormatString("\t\t\  Transaction Menu", clsScreen::enAlign::eCenter);
			_FormatString("===========================================", clsScreen::enAlign::eCenter);

			_FormatString("\t[1] Deposit Screen  ", clsScreen::enAlign::eCenter);
			_FormatString("\t[2] Withdraw Screen ", clsScreen::enAlign::eCenter);
			_FormatString("\t[3] Total Balance Screen ", clsScreen::enAlign::eCenter);
			_FormatString("\t[4] Transfer Screen ", clsScreen::enAlign::eCenter);
			_FormatString("\t[5] Back To Main Menue", clsScreen::eCenter);
			_FormatString("===========================================",clsScreen::enAlign::eCenter);

			_PerfromTransactionMenue(enManageUserMenueOption(ReadTransactionMenuOption()));
		}

};


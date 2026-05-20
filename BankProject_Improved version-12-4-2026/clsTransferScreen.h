#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsColor.h"
class clsTransferScreen : protected clsScreen
{
	private :

		static void _ShowClientTotalBalance1(clsBankClient Client)
		{
			cout << "______________________________________\n\n";
			cout << "Client: " << Client.FullName() << endl;
			cout << "Account Number: " << Client.AccountNumber()<< endl;
			cout << "Total Balance: " << Client.AccountBalance << endl;
			cout << "______________________________________\n\n";
		}

		static clsBankClient _ReadAccountNumber(string msg)
		{
			cout <<"\n" << msg << "\n";
			string AccountNumber  = clsInputValidate::ReadString();

			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << clsColor::GetColor(clsColor::enRed) << "\nAccount Number is not founded , please enter another one :" << clsColor::GetColor(clsColor::enReset);
				AccountNumber = clsInputValidate::ReadString();
			}
			clsBankClient client = clsBankClient::Find(AccountNumber);
			return client;
		}

	public :
		 
		static void ShowTransferScreen()
		{

			_DrawScreenHeader("Transfer Screen");
	
			 clsBankClient ClientFrom = _ReadAccountNumber("Enter From Account Number : ");
			_ShowClientTotalBalance1(ClientFrom);
			

			 clsBankClient ClientTo = _ReadAccountNumber("Enter To Account Number : ");
			 _ShowClientTotalBalance1(ClientTo);
			 

			cout << "\nEnter Amount To Transfer : ";
			
			double Amount = 
				clsInputValidate::ReadDoubleNumberBetween(1, 1000, "Number is'nt withn the range : ", clsInputValidate::enNumbreType::PositiveNumber);
			
			if (ClientTo.Transfer(ClientFrom, Amount) )
			{
				cout << "\t\t\t\t\t______________________________________\n\n";
				cout << "\t\t\t\t\t "<< clsColor::GetColor(clsColor::enGreen)<<"Transfer Done Successfully!\n" << clsColor::GetColor(clsColor::enReset);
				cout << "\t\t\t\t\t______________________________________\n\n";


				ClientTo.SaveTransferLog(ClientFrom, Amount);
			}
			else 
			{
				system("cls");
				cout << "\n\nOperation Failed Please Try Again ...\n\n";
			}
		

			cout << "\nFrom Client: \n";

			_ShowClientTotalBalance1(ClientFrom);

			cout << "\nTo Client: \n";

			_ShowClientTotalBalance1(ClientTo);

		}
};
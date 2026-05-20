#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
class clsWithdrawScreen : clsScreen
{

	private :
		
		static void _PrintClientRecord(clsBankClient C)
		{
			cout << "\nThe following Client Card Info : ";
			cout << "\n_________________________________________";
			cout << "\n\tFirst Name :" << C.FirstName;
			cout << "\n\tLast Name  :" << C.LastName;
			cout << "\n\tFull Name  :" << C.FullName();
			cout << "\n\tEmail      :" << C.Email;
			cout << "\n\tPhone      :" << C.Phone;
			cout << "\n\tAcc. Number:" << C.AccountNumber();
			cout << "\n\tPassword   :" << C.PinCode;
			cout << "\n\tBalance    :" << to_string(C.AccountBalance);
			cout << "\n_________________________________________";
		}
		static string ReadaAccountNumber()
		{
			string AccountNumber = "";
			cout << "\nPlease Enter Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "Client with Account Numbre is not found , choose another one :";
				AccountNumber = clsInputValidate::ReadString();
			}

			return AccountNumber;
		}

	public :

			static void ShowWithdrawScreen()
			{
				clsScreen::_DrawScreenHeader("\t  Withdraw Screen ");
				string AccountNumber = "";
				cout << "\nPlease Enter Account Number : ";
				AccountNumber = clsInputValidate::ReadString();

				clsBankClient Client = clsBankClient::Find(AccountNumber);

				_PrintClientRecord(Client);
		
				cout << "\nEnter Amount To Withdraw : ";

				double Amount = clsInputValidate::ReadDoubleNumber
				("Invalid Amount, Enter again :", clsInputValidate::enNumbreType::PositiveNumber);


				cout << "\nAre you sure that you want to withdraw " << Amount << " from this account ?y/n? ";
				char Answer = 'n';
				cin >> Answer;
				if (tolower(Answer) == 'y')
				{
					if (Client.Withdraw(Amount))
					{
						cout << "\nAmount Withdrawn Successfully :-)\n\n";
						cout << "New Balance is : " << Client.AccountBalance << endl;
					}
					else
					{
						cout << "\nInsufficient Balance!" << endl;
					}
				}
				else
				{
					cout << "\nOperation Cancelled :-)\n\n";
					return;
				}
			}

};	


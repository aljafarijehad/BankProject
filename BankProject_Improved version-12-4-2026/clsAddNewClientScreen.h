#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsAddNewClientScreen :protected clsScreen
{


		private :
			static void _PrintClientRecord (clsBankClient C)
			{
				cout << "\nThe following Added Client Card Info : ";
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

			static void _ReadClientInfo (clsBankClient& Client)
			{
				cout << "\nFirst Name :";
				Client.FirstName = clsInputValidate::ReadString();

				cout << "Last  Name :";
				Client.SetLastName(clsInputValidate::ReadString());

				cout << "Enter Email :";
				Client.Email = clsInputValidate::ReadString();

				cout << "Enter Phone :";
				Client.Phone = clsInputValidate::ReadString();

				cout << "Entre PinCode : ";
				Client.PinCode = clsInputValidate::ReadString();

				cout << "Enter Account Balance :";
				Client.AccountBalance = stod(clsInputValidate::ReadString());
			}

		public :

			static void ShowAddNewClientScreen() 
			{

				_DrawScreenHeader("\t   Add New Client Screen ");

				string AccountNumber = "";
				cout << "\nPlease Enter Account Number : ";
				AccountNumber = clsInputValidate::ReadString();

				while (clsBankClient::IsClientExist(AccountNumber))
				{
					cout << "\nAccount Number Is Already Used , Choose another one :";
					AccountNumber = clsInputValidate::ReadString();
				}

				clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

				_ReadClientInfo(NewClient);

				clsBankClient::enSaveResults SaveResult = NewClient.Save();

				switch (SaveResult)
				{
					case clsBankClient::enSaveResults::svSucceeded:
					{
						cout << "\nAccount Added Successfully :-) \n\n";
						_PrintClientRecord(NewClient);
						break;
					}
					case clsBankClient::enSaveResults::svFaildEmptyObject:
					{
					cout << "\nError account was not saved because it's Empty ,An unexpected error has occurred.";
						break;
					}
					case clsBankClient::enSaveResults::svFaildAccountNumberNotExists:
					{
						cout << "Error account already in used !!" << endl;
					}
				}
			}

};


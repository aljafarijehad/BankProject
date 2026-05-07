#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen  : protected clsScreen
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


		public :
			static void ShowdDeleteClientScreen()
			{

				if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
				{
					return;
				}
				clsScreen::_DrawScreenHeader("\t  Delete Client Screen ");
				
				string AccountNumber = "";
				cout << "\nPlease Enter Account Number :";
				AccountNumber = clsInputValidate::ReadString();

				while (!clsBankClient::IsClientExist(AccountNumber))
				{
					cout << "Client with Account Number not founded , please enter another : ";
					AccountNumber = clsInputValidate::ReadString();
				}

				clsBankClient ClientToDelete = clsBankClient::Find(AccountNumber);

				// Print Client Record before deleted 
				_PrintClientRecord(ClientToDelete);

				cout << "\nAre you sure that you want to delete this client ?y/n? ";
				char Answer = 'n';
				cin >> Answer;

				if (tolower(Answer) == 'y')
				{
					ClientToDelete.GetDeleteClientObject();

					clsBankClient::enSaveResults SaveResult = ClientToDelete.Save();

					switch (SaveResult)
					{
						case clsBankClient::enSaveResults::svSucceeded:
						{
							cout << "\nAccount Deleted Successfully :-) \n\n";
							_PrintClientRecord(ClientToDelete);
							break;
						}
						case clsBankClient::enSaveResults::svFaildEmptyObject:
						{
							system("cls");
							cout << "The Process not Completed , ERROR 404  !!" << endl << "\nThe Client not founded or something wrong :-(   .\n" << endl;;
							system("pause>0");
							break;
						}
						case clsBankClient::enSaveResults::svFaildAccountNumberNotExists:
						{
							cout << "Error account already in used !!" << endl;
						}
					}
				}
				else
				{
					system("cls");
					cout << "\nThe Process not completed , an Error Occurred\n";
					system("pause>0");
				}
			}

};


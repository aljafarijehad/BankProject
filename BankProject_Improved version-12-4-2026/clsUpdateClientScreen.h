#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
class clsUpdateClientScreen : protected clsScreen
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

	static void _ReadClientInfo(clsBankClient &Client)
	{
		cout << "\nFirst Name :";
		Client.FirstName = clsInputValidate::ReadString();

		cout << " Last  Name :";
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

		static void ShowUpdateClientScreen ()
		{
			if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
			{
				return;
			}

			clsScreen::_DrawScreenHeader("\t  Update Client Screen ");
			string AccountNumber = "";
			cout << "\n Please Enter Account Number : ";
			AccountNumber = clsInputValidate::ReadString();

			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "Client with Account Numbre is not found , choose another one :";
				AccountNumber = clsInputValidate::ReadString();
			}

			clsBankClient client = clsBankClient::Find(AccountNumber);

			_PrintClientRecord(client);
			cout << "\n";
			_FormatString("Update Client Info : \n", clsScreen::eCenter);
			_ReadClientInfo(client);

			 // need to refresh the file 
			clsBankClient::enSaveResults SaveResult = client.Save();

			switch (SaveResult)
			{
				case clsBankClient::enSaveResults::svSucceeded:
				{
					cout << "\nAccount Updated Successfully :-) \n";
					_PrintClientRecord(client);
					break;
				}
				case clsBankClient::enSaveResults::svFaildEmptyObject:
				{
					cout << "\nError account was not saved because it's Empty ";
					break;
				}
			} // end switch

		} // end function 

};


#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
class clsFindClientScreen : protected clsScreen
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

	public:

		static void ShowFindClientScreen() 
		{
			if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
			{
				return;
			}
			clsScreen::_DrawScreenHeader("\t  Find Client Screen ");
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
		}
};


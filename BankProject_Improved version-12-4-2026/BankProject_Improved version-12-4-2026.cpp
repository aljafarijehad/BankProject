
#include"clsLogInScreen.h"
int main() {



	////clsBankClient::ShowClientList();


	// clsBankClient::DeleteClient();

	 //clsBankClient::ShowTotalBalance();

	//clsBankClient::UpdateClient();
	
	//clsBankClient New = clsBankClient::AddNewClient();

	//clsBGBankSystem::BGBankSystem();

	 //clsMainScreen:: ShowMainMenuScreen();
	
	while (true){

		if (!clsLogInScreen::ShowLogInScreen())
			break;
	}

	// Client1.Print();

	return 0;
}
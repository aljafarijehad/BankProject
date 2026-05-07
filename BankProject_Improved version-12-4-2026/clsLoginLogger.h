#pragma once
#include "clsDate.h"
#include "clsUser.h"
#include <fstream>
class clsLoginLogger 
{
private :


	static string _GetCurrentDateTime()
	{
		return   clsDate::DateToString(clsDate::GetSystemDate()) + " - " + clsDate::GetSystemTime();
	}

	static string _ConvertLoginRecordToString(clsUser User ,string Delimiter = "#//#")
	{
		return _GetCurrentDateTime() + Delimiter + User.UserName + Delimiter + to_string(User.Permissions);

	}

	static void _SaveLoginDataToFile(clsUser User)
		{
			fstream file;
			file.open("LoginLog.txt", ios::out | ios::app); // append mode
			if (file.is_open())
			{
				file << _ConvertLoginRecordToString(User) << endl;
			}
			file.close();
	}


public :

	static void SaveLoginToLog(clsUser User)
	{
		_SaveLoginDataToFile(User);
	}

};


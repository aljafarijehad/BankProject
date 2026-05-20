
#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static int ReadNumber(string msg)
	{
		cout << msg;
		while (true)
		{
			string input;
			cin >> input;
			bool flag = true;
			for (char c : input)
			{
				if (c < '0' || c > '9')
				{
					flag = false;
					break;
				}
			}
			if (flag)
				return stoi(input);

			cout << "Wrong , Please Enter a Number : ";
		}

	}

	//static bool IsNumberBetween(short Number, short From, short To)
	//{
	//	if (Number >= From || Number <= To)
	//		return true;
	//	return false;
	//}

	static bool IsNumberBetween(int Number, int From, int To)	
	{
		if (Number >= From && Number <= To)
			return true;
		return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From || Number <= To)
			return true;
		return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From || Number <= To)
			return true;
		return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (!clsDate::IsDate1BeforeDate2(From, To))
		{
			clsDate::SwapDates(From, To);
		}
		// Date>=From && Date<=To
		return  (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&& (clsDate::IsDate1BeforeDate2(Date, To)) || (clsDate::IsDate1EqualDate2(Date, To)));

	}

	static string ReadString() 
	{
		string Text;
		getline(cin >> ws, Text);
		return Text;
	} 
	
	static int ReadIntNumber(string ErrorMessage = "Invalid Number , Enter again :")
	{
		int number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not withn the range :")
	{
		int number = ReadIntNumber();
		while (!IsNumberBetween(number, From, To))
		{
			cout << ErrorMessage;
			number = ReadIntNumber();
		}
		return number;
	}

	enum enNumbreType
	{
		PositiveNumber, NigativeNumber, All 
	};
	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number , Enter again :" , enNumbreType enType = All)
	{
		double number;
		while (!(cin >> number) || 
			(enType == PositiveNumber && number < 0) || 
			(enType == NigativeNumber  && number > 0) )
		{
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return (number);
	}

	static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage = "Number is not withn the range :" , enNumbreType enType = All)
	{
		double number = ReadDoubleNumber("Invalid Number , Enter again :", enType);

		while (!IsNumberBetween(number, From, To))
		{
			cout << ErrorMessage;
			number = ReadIntNumber();
		}
		return number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	

};


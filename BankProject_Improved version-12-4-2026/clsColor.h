#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsColor
{

public:
	enum enColor
	{
		enBlack = 1, enRed = 2, enGreen = 3, enYellow = 4,

		enBlue = 5, enMagenta = 6, enCyan = 7, enWhite = 8,

		enBrightBlack_Gray = 9, enBrightRed = 10, enBrightGreen = 11,

		enBrightYellow = 12, enBrightBlue = 13, enBrightMagenta = 14,

		enBrightCyan = 15, enBrightWhite = 16, enReset = 17,

		enBlink = 18, enUnderline = 19, enBrightWhiteBackground = 20,

		enBrightYellowBackground = 21
	};

	static string GetColor(enColor Color)
	{
		switch (Color)
		{
		case enColor::enBlack:
			return "\033[30m";

		case enColor::enRed:
			return "\033[31m";

		case enColor::enGreen:
			return "\033[32m";

		case enColor::enYellow:
			return "\033[33m";

		case enColor::enBlue:
			return "\033[34m";

		case enColor::enMagenta:
			return "\033[35m";

		case enColor::enCyan:
			return "\033[36m";

		case enColor::enWhite:
			return "\033[37m";

		case enColor::enBrightBlack_Gray:
			return "\033[90m";

		case enColor::enBrightRed:
			return "\033[91m";

		case enColor::enBrightGreen:
			return "\033[92m";

		case enColor::enBrightYellow:
			return "\033[93m";

		case enColor::enBrightBlue:
			return "\033[94m";

		case enColor::enBrightMagenta:
			return "\033[95m";

		case enColor::enBrightCyan:
			return "\033[96m";

		case enColor::enBrightWhite:
			return "\033[97m";

		case enColor::enReset:
			return "\033[0m";

		case enColor::enBlink:
			return "\033[5m";

		case enColor::enUnderline:
			return "\033[4m";

		case enColor::enBrightWhiteBackground:
			return "\033[107m";

		case enColor::enBrightYellowBackground:
			return "\033[103m";
		}
	}

	static string Text(int Code)
	{
		return "\033[38;5;" + to_string(Code) + "m";
	}

	static string BG(int Code)
	{
		return "\033[48;5;" + to_string(Code) + "m";
	}

	static string Reset()
	{
		return "\033[0m";
	}

	static string Blink()
	{
		return "\033[5m";
	}

};
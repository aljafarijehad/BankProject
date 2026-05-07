#pragma once
#include <iostream>
#include <iomanip>
#include "clsColor.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsScreen
{
    public  :

    enum enAlign {
        eLeft , eRight , eCenter
    };

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << clsColor::GetColor(clsColor::enBlue)
            <<"\n\n\t\t\t\t\t  " << Title << clsColor::GetColor(clsColor::enReset);
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    static void _FormatString(string Text , enAlign Direction = enAlign::eCenter , short spaces = 0)
    {
        if (Direction == enAlign::eCenter)
        {
            cout << setw(37) << left <<"" << Text << endl;
        }
        else if (Direction == enAlign::eRight)
        {
            cout << setw(spaces) << left << Text << endl;
        }
        else if (Direction == enAlign::eLeft)
        {
            cout << setw(spaces) << Text << endl;
        }

    }

    static bool CheckAccessRights(clsUser::enPermissions RequiredPermissions)
    {
        if (!CurrentUser.CheckAccessPermission(RequiredPermissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << clsColor::GetColor(clsColor::enRed) << "\n\n\t\t\t\t\t Access Denied! Contact your Admin." << clsColor::GetColor(clsColor::enReset);
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
	}

};


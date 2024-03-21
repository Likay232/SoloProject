#include "Header.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

bool NumIsCorrect(string roman_num, map <string, int>)
{
    bool rules = true;
    
    if (roman_num.size() >= 4)
    {
        for (int i = 0; i <= (roman_num.size() - 4); i++)
        {
            if ((roman_num[i] == roman_num[i + 1]) && roman_num[i + 1] == roman_num[i + 2] &&
                roman_num[i + 2] == roman_num[i + 3])
                rules = false;
        }
    }

    for (int i = 0; i <= (roman_num.size() - 1); i++)
    {
        if ((roman_num[i] == roman_num[i + 1] && (roman_num[i] == 'V' || roman_num[i] == 'L' || roman_num[i] == 'D')))
            rules = false;
        
    }
    
    return rules;
}

string RomToNum(string roman_num)
{
    int number = 0;
    string error_msg = "ERROR";
    map <string, int> liter;

    liter["I"] = 1;
    liter["V"] = 5;
    liter["X"] = 10;
    liter["L"] = 50;
    liter["C"] = 100;
    liter["D"] = 500;
    liter["M"] = 1000;
    
    string curr = "";
    string incoming = "";
    int result = 0;

    if (roman_num.length() == 1) return to_string(liter[roman_num]);
    
    if (NumIsCorrect(roman_num, liter))
    {
        if (roman_num.size() >= 2)
        {
            for (int i = 0; i <= roman_num.size() - 1; i++)
            {
                curr = roman_num[i];
                incoming = roman_num[i + 1];
                
                if (liter[curr] < liter[incoming])
                {
                    if (curr == "V" || curr == "L" || curr == "D")
                    {
                        return error_msg;
                    }
                    result += liter[incoming] - liter[curr];
                    i++;
                }
                else
                {
                    result += liter[curr];
                }
            }
        }
        else
        {
            curr = roman_num[0];
            cout << liter[curr];
            return error_msg;
        }
    }
    else
    {
        return error_msg;
    }
    
    string returnable_result = to_string(result);
    
    return returnable_result;
}

#include <iostream>
#include <map>
#include <locale.h>
#include <string>

using namespace std;

// 1 - I, 5 - V, 10 - X, 50 - L, 100 - C, 500 - D, 1000 - M.
// 1/5 = 0, 5/5 = 1, 10/5 = 2, 50/5 = 10, 100/5 = 20, 500/5 = 100, 1000/5 = 200 -- 2 option

string NumToRom(int num)
{
    
    string rom_num;
    map<int, string> liter;

    liter[1] = "I";
    liter[5] = "V";
    liter[10] = "X";
    liter[50] = "L";
    liter[100] = "C";
    liter[500] = "D";
    liter[1000] = "M";
    
    if (num >= 4000)
    {
        for (int i = 0; num >= 1000; i++)
        {
            rom_num += "-";
            num /= 1000;
        }
    }
    
    for (int j = 0; num > 0; j++)
    {
        int highest_digit;
        
        for (int i = 1; (num / i) >= 1; i *= 10)
            highest_digit = i;

        int digit_count = num / highest_digit;
        const int del_num = highest_digit * digit_count;

        if (digit_count == 4)
        {
            rom_num += liter[highest_digit] + liter[5 * highest_digit];
            num = num - del_num;
            continue;
        }

        if (digit_count == 9)
        {
            rom_num += liter[highest_digit] + liter[highest_digit * 10];
            num = num - del_num;
            continue;
        }
            
        if (digit_count >= 5)
        {
            digit_count = digit_count - 5;
            rom_num += liter[5 * highest_digit];
        }
        
        for (int i = 0; i < digit_count; i++)
            rom_num += liter[highest_digit];
        
        num = num - del_num;
    }
    
    return rom_num;
}

bool CorrectNumber(string roman_num, map <string, int>)
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
    string third_letter = "";
    int result = 0;
    int times = 1;
        
    if (CorrectNumber(roman_num, liter))
    {
        if (roman_num.size() >= 2)
        {
            for (int i = 0; i <= roman_num.size() - 1; i++)
            {
                curr = roman_num[i];
                incoming = roman_num[i + 1];

                if (curr == "-") times *= 1000;
                
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
    
    result *= times;

    string returnable_result = to_string(result);
    
    //if (roman_num == NumToRom(result))
    //    return  returnable_result;
    //else return error_msg;
    return returnable_result;
}

void main()
{
    int lever;
    do
    {
        cout << "Choose a mode:";
        cout << "\n1 - Roman number to arabic";
        cout << "\n2 - Arabic number to roman\n";
        cin >> lever;
    }
    while (lever != 1 && lever != 2 && lever != 0);
    if (lever == 2)
    {
        int num;
        cout << "Enter a number: "; cin >> num;
        cout << NumToRom(num);
    }
    if (lever == 1)
    {
        string roman_num, converted;
        
        cout << "Enter roman number: "; cin >> roman_num;

        converted = RomToNum(roman_num);

        if (roman_num == NumToRom(stoi(converted)))
            cout << converted;
        else
        {
            if (converted == RomToNum(NumToRom(stoi(converted))))
                cout << converted;
            else
                cout << "ERROR";
        }
    }
}
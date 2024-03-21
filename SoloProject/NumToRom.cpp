#include "Header.h"
#include <string>
#include <map>

using namespace std;

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

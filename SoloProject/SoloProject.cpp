#include <iostream>
#include <map>
#include <locale.h>
#include <string>
#include <conio.h>
#include "Windows.h"
#include "Header.h"
#include <vcruntime_startup.h>


using namespace std;

// 1 - I, 5 - V, 10 - X, 50 - L, 100 - C, 500 - D, 1000 - M.
// 1/5 = 0, 5/5 = 1, 10/5 = 2, 50/5 = 10, 100/5 = 20, 500/5 = 100, 1000/5 = 200 -- 2 option

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    char mode;
    char question;
    
    do
    {
        cout << "Mode selector:";
        cout << "\n1 - Римское число в десятичное";
        cout << "\n2 - Десятичное число в римское\n";
        cout << "\n0 - Exit\n";
        
        mode = _getch();
        
        system("cls");

        if (mode == '2')
        {
            int num;
            
            cout << "!Выбранный режим - Десятичное в Римское!\n";
            cout << "Введите десятичное число: "; cin >> num;
        
            if (num >= 1 && num <= 3999)
            {
                cout << num << " в римском виде -- " << NumToRom(num) << endl;
                cout << "Продолжить? (1/0) "; question = _getch();
                if (question == '0')
                {
                    system("cls");
                    cout << "Сессия завершена";
                    return 0;
                }
                else system("cls");
            }
            else
                cout << "error\n";
        }
        else if (mode == '1')
        {
            string roman_num, converted;
            
            cout << "!Выбранный режим - Римское в Десятичное!\n";
            cout << "Введите римское число: "; cin >> roman_num;

            converted = RomToNum(roman_num);
        
            if (converted == "ERROR")
            {
                cout << "error1\n";
                return 1;
            }
            else if (roman_num == NumToRom(stoi(converted)))
            {
                cout << roman_num << " в десятичном представлении -- " << converted << endl;
                cout << "Продолжить? (1/0) "; question = _getch();
                if (question == '0') 
                {
                    system("cls");
                    cout << "Сессия завершена";
                    return 0;
                }
                else system("cls");
            }
            else
            {
                cout << "error\n";
            }
        }
    }
    while (mode != '0');

    cout << "Сессия завершена";
    
    return 0;
}
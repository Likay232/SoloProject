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
        cout << "\n1 - ������� ����� � ����������";
        cout << "\n2 - ���������� ����� � �������\n";
        cout << "\n0 - Exit\n";
        
        mode = _getch();
        
        system("cls");

        if (mode == '2')
        {
            int num;
            
            cout << "!��������� ����� - ���������� � �������!\n";
            cout << "������� ���������� �����: "; cin >> num;
        
            if (num >= 1 && num <= 3999)
            {
                cout << num << " � ������� ���� -- " << NumToRom(num) << endl;
                cout << "����������? (1/0) "; question = _getch();
                if (question == '0')
                {
                    system("cls");
                    cout << "������ ���������";
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
            
            cout << "!��������� ����� - ������� � ����������!\n";
            cout << "������� ������� �����: "; cin >> roman_num;

            converted = RomToNum(roman_num);
        
            if (converted == "ERROR")
            {
                cout << "error1\n";
                return 1;
            }
            else if (roman_num == NumToRom(stoi(converted)))
            {
                cout << roman_num << " � ���������� ������������� -- " << converted << endl;
                cout << "����������? (1/0) "; question = _getch();
                if (question == '0') 
                {
                    system("cls");
                    cout << "������ ���������";
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

    cout << "������ ���������";
    
    return 0;
}
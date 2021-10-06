// Integer to Roman..
/* 
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000 
*/
#include <iostream>
using namespace std;

void intToRoman(int number);

int main()
{
    int Input;

    cout << "Enter integer num from range (1 - 3999) : ";
    cin >> Input;

    intToRoman(Input);

    return 0;
}

void intToRoman(int number)
{
    if (number == 0)
    {
        cout << "There is no 0 in Roman";
        return;
    }
    else if (number >= 4000)
    {
        cout << "There are no Roman symbols that greater than 3999";
        return;
    }
    else if (number < 1)
    {
        cout << "Error";
        return;
    }

    int num[13] = {1, 4, 5, 9, 10, 40, 50, 90,
                   100, 400, 500, 900, 1000};
    string symbols[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC",
                          "C", "CD", "D", "CM", "M"};
    int i = 12;
    cout << "Your conversion to Roman is : ";
    while (number > 0)
    {
        int divisor = number / num[i];
        number = number % num[i];
        while (divisor--)
        {
            cout << symbols[i];
        }
        i--;
    }
}
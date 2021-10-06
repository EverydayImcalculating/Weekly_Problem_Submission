// Integer to Roman.
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
#include <map>
using namespace std;
string intToRoman(int number);

int main()
{
    int Input;
    cout << "Enter integer num (1 - 3999) : ";
    cin >> Input;
    string sol = intToRoman(Input);
    cout << sol;

    return 0;
}

string intToRoman(int number)
{
    if (number == 0)
    {
        cout << "There is no 0 in Roman";
        exit(0);
    }
    else if (number >= 4000)
    {
        cout << "There are no Roman symbols that greater than 3999";
        exit(0);
    }
    else if (number < 1)
    {
        cout << "Error";
        exit(0);
    }

    map<int, string> R;
    R[1] = "I";
    R[2] = "II";
    R[3] = "III";
    R[4] = "IV";
    R[5] = "V";
    R[6] = "VI";
    R[7] = "VII";
    R[8] = "VIII";
    R[9] = "IX";
    R[10] = "X";
    R[20] = "XX";
    R[30] = "XXX";
    R[40] = "XL";
    R[50] = "L";
    R[60] = "LX";
    R[70] = "LXX";
    R[80] = "LXXX";
    R[90] = "XC";
    R[100] = "C";
    R[200] = "CC";
    R[300] = "CCC";
    R[400] = "CD";
    R[500] = "D";
    R[600] = "DC";
    R[700] = "DCC";
    R[800] = "DCCC";
    R[900] = "CM";
    R[1000] = "M";
    R[2000] = "MM";
    R[3000] = "MMM";
    string ans = " ";
    int i = 1;
    cout << "Your conversion to Roman is : ";
    while (number > 0)
    {
        i = i * 10;
        int div = number % i;
        ans = R[div] + ans;
        number = number - div;
    }
    return ans;
}
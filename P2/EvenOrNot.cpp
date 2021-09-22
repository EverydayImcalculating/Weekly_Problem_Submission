//จงเขียนโปรแกรมเพื่อรับค่าตัวเลข 4 จำนวน แล้วหาว่ามีเลขคู่กี่จำนวน  (Level 1)
#include <iostream>
using namespace std;
int main () 
{
    int a,b,c,d;
    cout << "Enter four Numbers : \n";
    cin >> a >> b >> c >> d;
    cout << "\n";
    if (a%2==0) {
        cout << a << " is Even.\n";
    } else 
    {
        cout << a << " is Odd.\n";
    }
    if (b%2==0) {
        cout << b << " is Even.\n";
    } else 
    {
        cout << b << " is Odd.\n";
    }
    if (c%2==0) {
        cout << c << " is Even.\n";
    } else 
    {
        cout << c << " is Odd.\n";
    }
    if (d%2==0) {
        cout << d << " is Even.\n";
    } else 
    {
        cout << d << " is Odd.\n";
    }
}
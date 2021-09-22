//จงเขียนโปรแกรมเพื่อรับค่าตัวเลข 4 จำนวน แล้วหาว่ามีเลขคู่กี่จำนวน  (Level 1)
#include <iostream>
using namespace std;
int main () 
{
    int a[4];
    cout << "Enter four Numbers : \n";
    for (int i= 0; i<4; i++) 
    {
        cin >> a[i];   
    }
    cout << "\n";
    for (int i=0; i<4; i++) 
    {
        if (a[i]%2==0) {
            cout << a[i] << " is Even.\n";
        } else 
        {
            cout << a[i] << " is Odd.\n";
        }
    }
}
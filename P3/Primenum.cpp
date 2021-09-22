//จงเขียนโปรแกรมรับตัวเลข 1 ตัว แล้วแสดงค่าจำนวนเฉพาะที่น้อยกว่าตัวเลขตัวนั้นทั้งหมด (Level 3)
#include <iostream>
#include <cmath>
using namespace std;
int main () 
{
    int n,check=0 ;
    cin >> n;
    for (int i=1; i<=n; i++) 
    {
        for (int j=2; j<i; j++) 
        {
            if (i%j==0) 
            {
                check++;
                break;
            } 
        }
        if (check == 0 && i!= 1)
            cout << i << " ";
            check = 0;
    }    
    return 0;
}
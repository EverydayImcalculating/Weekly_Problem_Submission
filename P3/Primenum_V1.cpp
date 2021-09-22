//จงเขียนโปรแกรมรับตัวเลข 1 ตัว แล้วแสดงค่าจำนวนเฉพาะที่น้อยกว่าตัวเลขตัวนั้นทั้งหมด (Level 3)
#include <iostream>
using namespace std;

int isPrimeNum(int);

int main()
{
    bool isPrime;
    int num;
    cin >> num;
    for (int i = 2; i < num; i++)
    {
        isPrime = isPrimeNum(i);
        if (isPrime == true)
        {
            cout << i << " ";
        }
    }
    return 0;
}

int isPrimeNum(int n)
{
    bool isPrime = true;
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
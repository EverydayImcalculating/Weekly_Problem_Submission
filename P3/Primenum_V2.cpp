//จงเขียนโปรแกรมรับตัวเลข 1 ตัว แล้วแสดงค่าจำนวนเฉพาะที่น้อยกว่าตัวเลขตัวนั้นทั้งหมด (Level 3)
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> Primes;
    Primes.push_back(2);
    bool isPrime;
    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        isPrime = true;
        for (int s = 0; s < Primes.size() && Primes[s] <= i / 2; s++)
        {
            if (i % Primes[s] == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            Primes.push_back(i);
            cout << i << " ";
        }
    }
}
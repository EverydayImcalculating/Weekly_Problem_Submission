/* จงเขียนฟังก์ชัน sqrt โดยไม่ใช้ไลบรารี math.h (Level 5) */
#include <iostream>
using namespace std;

void findSqrt(int number);

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    findSqrt(num);

    return 0;
}

void findSqrt(int number)
{

    double temp, sqrt;
    sqrt = number / 2;
    temp = 0;

    if (number < 0)
    {
        cout << "Enter a positive number to find square Root";
    }
    else if (number == 1)
    {
        cout << "The square Root of the given num is : 1 ";
    }
    else
    {
        while (sqrt != temp)
        {
            temp = sqrt;
            sqrt = (number / temp + temp) / 2;
        }
        cout << "The square Root of the given num is : " << sqrt;
    }
}
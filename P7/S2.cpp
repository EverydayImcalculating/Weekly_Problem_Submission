/* จงเขียนฟังก์ชัน sqrt โดยไม่ใช้ไลบรารี math.h (Level 5) */
#include <iostream>
using namespace std;

void findSqrt(double number);

int main()
{
    double num;
    cin >> num;
    findSqrt(num);

    return 0;
}

void findSqrt(double number) // Babylonian method.
{
    double Xn = number;
    double y = 1;
    double error = 0.0000001;

    if (number < 0)
    {
        cout << "Enter a positive number to find square Root";
    }
    else
    {
        while (Xn - y > error)
        {
            Xn = (Xn + y) / 2;
            y = number / Xn;
        }
        cout << "The square Root of the given num is : " << Xn;
    }
}
//จงเขียนโปรแกรมเพื่อรับค่าตัวเลข 2 ตัว แล้วแสดงผลบวก 
//ลบ คูณ หาร ของตัวเลขทั้งสองตัวนั้น โดยใช้ตัวแปรน้อยที่สุด  (Level 1)
#include <iostream>
using namespace std;
int main (){
    double A[2]; 
    cin >> A[0] >> A[1]; 
    cout << A[0]+A[1] << endl << A[0]-A[1] << endl << A[0]*A[1] << endl << A[0]/A[1] << endl; //แสดงผล operation
    return 0;
}
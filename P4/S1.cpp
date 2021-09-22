/*76.บวกเมทริกซ์ 2 เมทริกซ์ มิติ m × n (Level 4)
ข้อมูลนำเข้า 
บรรทัดแรก จำนวนเต็มบวก m, n (1 ≤ m, n ≤ 3) แสดงมิติของเมทริกซ์ 
บรรทัดที่ 2 ถึงบรรทัดที่ m + 1 จำนวนเต็ม n จำนวนในแต่ละบรรทัด 
แสดงสมาชิกของเมทริกซ์ที่หนึ่ง บรรทัดที่ m + 2 ถึงบรรทัดที่ 2 · m + 1 
จำนวนเต็ม n จำนวนในแต่ละบรรทัด แสดงสมาชิกของเมทริกซ์ที่สอง 
ข้อมูลส่งออก 
จำนวนบรรทัดทั้งสิ้น m บรรทัด แต่ละบรรทัดแสดงสมาชิกของเมทริกซ์ผลลัพธ์ 
ในรูปแบบตามข้อมูลนำเข้า 
*/

/* input                output                            
    3 3                 2 3 4                     
    1 2 3               4 3 2   
    3 2 1               2 4 3
    1 3 2 
    1 1 1 
    1 1 1 
    1 1 1 
*/
#include <iostream>
using namespace std;

int main()
{
    int NarrSize = 0;
    int MarrSize = 0;

    cout << "Enter Matrix Row : ";
    cin >> MarrSize; 
    cout << "Enter Matrix Column : ";
    cin >> NarrSize;

    int** Matrix1 = new int*[MarrSize];
    int** Matrix2 = new int*[MarrSize];
    int** ResultMatrix = new int*[MarrSize];
    for(int i = 0; i < MarrSize; i++)
    {
        Matrix1[i] = new int[NarrSize];
        Matrix2[i] = new int[NarrSize];
        ResultMatrix[i] = new int[NarrSize];
    }

    cout << "Enter First Matrix Elements : \n";

    for(int i = 0; i < MarrSize; i++ )
    {
        cout << "\t";
        for(int j = 0; j < NarrSize; j++)
        {
            cin >> Matrix1[i][j];
        }
    }

    cout << "Enter Second Matrix Elements : \n";

    for(int i = 0; i < MarrSize; i++ )
    {
        cout << "\t";
        for(int j = 0; j < NarrSize; j++)
        {
            
            cin >> Matrix2[i][j];
        }
    }

    cout << "Resulting Matrix : \n";

    for(int i = 0; i < MarrSize; i++ )
    {
        cout << "\t";
        for(int j = 0; j < NarrSize; j++)
        {
            ResultMatrix[i][j] = Matrix1[i][j] + Matrix2[i][j]; 
            cout << ResultMatrix[i][j] << " ";
        }
        cout << endl;
    }


    for(int i = 0; i < NarrSize; i++)
    {   
        delete Matrix1[i];   
        delete Matrix2[i];   
        delete ResultMatrix[i];
    }
    delete Matrix1;
    delete Matrix2;
    delete ResultMatrix; 
    
    return 0;
}

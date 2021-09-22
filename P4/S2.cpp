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
#include <vector>
using namespace std;

int main()
{
    int m, n;
    vector<vector<int>> matrix1(m, vector<int>(n));

    vector<vector<int>> matrix2(m, vector<int>(n));

    vector<vector<int>> ResultMatrix(m, vector<int>(n));

    cout << "Enter Matrix Row : ";
    cin >> m;
    cout << "Enter Matrix Column : ";
    cin >> n;

    cout << "Enter First Matrix Elements : \n";
    for (int i = 0; i < m; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter Second Matrix Elements : \n";
    for (int i = 0; i < m; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            cin >> matrix2[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ResultMatrix[i].push_back(0);
        }
    }

    cout << "Resulting Matrix : \n";
    for (int i = 0; i < m; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            ResultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << ResultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

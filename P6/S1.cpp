/* จงเขียนโปรแกรมคำนวณเมตริก โดยโปรแกรมจะรับค่าเมตริก A และ B ซึ่งเป็นเมตริกขนาด 3x3 
แล้วโปรแกรมจะแสดงผลลัพธ์ต่อไปนี้ Det A , Det B , Inverse A , Inverse B , A+B , 
A-B , A x B (Level 5) */

#include <iostream>
#include <cmath>
using namespace std;

int DetCalculate(int **Matrix);
void InverseCalculate(int **Matrix, int **MatrixHelper, int **Matrixreturn);
void OperationCalculate(int **Matrix1, int **Matrix2, int **MatrixResult);

int main() 
{
    int M_SIZE = 3, N_SIZE = 3; 

    int **MatrixA = new int *[M_SIZE];
    int **MatrixB = new int *[M_SIZE];
    int **MatrixHelper = new int *[M_SIZE];
    int **MatrixHelper2 = new int *[M_SIZE];

    for (int i = 0; i < M_SIZE; i++)
    {
        MatrixA[i] = new int[N_SIZE];
        MatrixB[i] = new int[N_SIZE];
        MatrixHelper[i] = new int[N_SIZE];
        MatrixHelper2[i] = new int[N_SIZE];
    }
    cout << "Enter MatrixA Element : \n";
    for (int i = 0; i < M_SIZE; i++)
    {
        cout << "\t";
        for (int j = 0; j < N_SIZE; j++)
        {
            cin >> MatrixA[i][j];
        }
    }
cout << "Enter MatrixB Element : \n";
    for (int i = 0; i < M_SIZE; i++)
    {
        cout << "\t";
        for (int j = 0; j < N_SIZE; j++)
        {
            cin >> MatrixB[i][j];
        }
    }

    cout << "Determinant of MatrixA is : ";
    cout << DetCalculate(MatrixA) << endl;
    cout << "Determinant of MatrixB is : ";
    cout << DetCalculate(MatrixB);
    cout << "\nInverse of MatrixA ";
    InverseCalculate(MatrixA, MatrixHelper, MatrixHelper2);
    cout << "Inverse of MatrixB ";
    InverseCalculate(MatrixB, MatrixHelper, MatrixHelper2);
    OperationCalculate(MatrixA, MatrixB, MatrixHelper);

    return 0;
}

int DetCalculate(int **Matrix)
{
    int Result;
    Result =
        ((Matrix[0][0] * ((Matrix[1][1] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][1]))) - (Matrix[0][1] * ((Matrix[1][0] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][0]))) + (Matrix[0][2] * ((Matrix[1][0] * Matrix[2][1]) - (Matrix[1][1] * Matrix[2][0]))));

    return Result;
}

void InverseCalculate(int **Matrix, int **MatrixHelper, int **Matrixreturn)
{

    int Result;
    int numerator, denominator;
    int Det = DetCalculate(Matrix);
    denominator = Det;
    if (Det == 0)
    {
        cout << "doesn't exist (Det = 0)\n";
    }
    else
    {
        cout << "is : \n";
        MatrixHelper[0][0] = (Matrix[1][1] * Matrix[2][2] - Matrix[1][2] * Matrix[2][1]);
        MatrixHelper[0][1] = (Matrix[1][2] * Matrix[2][0] - Matrix[1][0] * Matrix[2][2]);
        MatrixHelper[0][2] = (Matrix[1][0] * Matrix[2][1] - Matrix[1][1] * Matrix[2][0]);
        MatrixHelper[1][0] = (Matrix[0][2] * Matrix[2][1] - Matrix[0][1] * Matrix[2][2]);
        MatrixHelper[1][1] = (Matrix[0][0] * Matrix[2][2] - Matrix[0][2] * Matrix[2][0]);
        MatrixHelper[1][2] = (Matrix[0][1] * Matrix[2][0] - Matrix[0][0] * Matrix[2][1]);
        MatrixHelper[2][0] = (Matrix[0][1] * Matrix[1][2] - Matrix[0][2] * Matrix[1][1]);
        MatrixHelper[2][1] = (Matrix[0][2] * Matrix[1][0] - Matrix[0][0] * Matrix[1][2]);
        MatrixHelper[2][2] = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
        for (int i = 0; i < 3; i++)
        {
            cout << "\t";
            for (int j = 0; j < 3; j++)
            {
                Matrixreturn[i][j] = MatrixHelper[j][i];
                numerator = Matrixreturn[i][j];
                for (int i = denominator * numerator; i > 1; i--)
                {
                    if ((denominator % i == 0) && (numerator % i == 0))
                    {
                        denominator /= i;
                        numerator /= i;
                    }
                }
                cout << numerator << "/" << denominator << " ";
            }
            cout << endl;
        }
    }
}

void OperationCalculate(int **Matrix1, int **Matrix2, int **MatrixResult)
{
    cout << "MatrixA - MatrixB is : \n";
    for (int i = 0; i < 3; i++) // Addition.
    {
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            MatrixResult[i][j] = Matrix1[i][j] + Matrix2[i][j];
            cout << MatrixResult[i][j] << " ";
        }
        cout << endl;
    }
    cout << "MatrixA + MatrixB is : " << endl;
    for (int i = 0; i < 3; i++) // Subtraction.
    {
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            MatrixResult[i][j] = Matrix1[i][j] - Matrix2[i][j];
            cout << MatrixResult[i][j] << " ";
        }
        cout << endl;
    }
    cout << "MatrixA x MatrixB is : \n";
    for (int i = 0; i < 3; i++) // Multiplication.
    {
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
            cout << MatrixResult[i][j] << " ";
        }
        cout << endl;
    }
}

/* จงเขียนโปรแกรมคำนวณเมตริก โดยโปรแกรมจะรับค่าเมตริก A และ B ซึ่งเป็นเมตริกขนาด 3x3 
แล้วโปรแกรมจะแสดงผลลัพธ์ต่อไปนี้ Det A , Det B , Inverse A , Inverse B , A+B , 
A-B , A x B (Level 5) */
#include <iostream>
#include <cmath>
#include <iomanip>
#define N 3
using namespace std;

void getCofactor(int M1[N][N], int M2[N][N], int p, int q, int x);
int findDeterminant(int M[N][N], int x);
void adjoint(int M[N][N], int adj[N][N], int x);
void inverseConvert(int M[N][N], double inverse[N][N], int x);
void findInverse(int M[N][N], int x);
void simpleObp(int M1[N][N], int M2[N][N], int x);

int main()
{
    int mA[N][N], mB[N][N];
    cout << "Enter MatrixA Elements : \n";
    for (int i = 0; i < N; i++)
    {
        cout << "\t";
        for (int j = 0; j < N; j++)
        {

            cin >> mA[i][j];
        }
    }
    cout << "Enter MatrixB Elements : \n";
    for (int i = 0; i < N; i++)
    {
        cout << "\t";
        for (int j = 0; j < N; j++)
        {

            cin >> mB[i][j];
        }
    }
    cout << "Determinant of MatrixA is : ";
    cout << findDeterminant(mA, N) << endl;
    cout << "Determinant of MatrixB is : ";
    cout << findDeterminant(mB, N);
    cout << "\nInverse of MatrixA ";
    findInverse(mA, N);
    cout << "Inverse of MatrixB ";
    findInverse(mB, N);
    simpleObp(mA, mB, N);

    return 0;
}

void getCofactor(int M1[N][N], int M2[N][N], int p, int q, int x)
{
    int i, j, m, n;

    m = 0;
    n = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            M2[i][j] = 0;
            if (i != p && j != q)
            {
                M2[m][n] = M1[i][j];

                if (n < x - 2)
                    n++;
                else
                {
                    n = 0;
                    m++;
                }
            }
        }
    }
}

int findDeterminant(int M[N][N], int x)
{
    int det;
    if (x == 1)
        return M[0][0];

    else
    {
        int c, s = 1, temp[N][N], i, j, m, n;
        det = 0;
        for (c = 0; c < x; c++)
        {
            getCofactor(M, temp, 0, c, x);
            det = det + s * (M[0][c] * findDeterminant(temp, x - 1));
            s = (-1) * s;
        }
    }
    return det;
}

void adjoint(int M[N][N], int adj[N][N], int x)
{

    int sign = 1;
    int co_fact[N][N];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {

            getCofactor(M, co_fact, i, j, x);

            sign = pow(-1, (i + j));
            adj[j][i] = sign * findDeterminant(co_fact, x - 1);
        }
    }
}

void inverseConvert(int M[N][N], double inverse[N][N], int x)
{
    int det = findDeterminant(M, N);

    int adj[N][N];
    adjoint(M, adj, x);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            inverse[i][j] = adj[i][j] / (double)det;
        }
    }
}

void findInverse(int M[N][N], int x)
{
    double inverse[N][N];
    inverseConvert(M, inverse, N);

    int det = findDeterminant(M, N);
    if (det == 0)
    {
        cout << "does not exist.(Determinant = 0)" << endl;
    }
    else
    {
        cout << "is : \n";
        for (int i = 0; i < N; i++)
        {
            cout << "\t";
            for (int j = 0; j < N; j++)
            {
                cout << fixed << showpoint;
                cout << setprecision(2);
                cout << inverse[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void simpleObp(int M1[N][N], int M2[N][N], int x)
{
    int mResult[N][N];

    cout << "MatrixA - MatrixB is : \n";
    for (int i = 0; i < x; i++) // Addition.
    {
        cout << "\t";
        for (int j = 0; j < x; j++)
        {
            mResult[i][j] = M1[i][j] + M2[i][j];
            cout << mResult[i][j] << " ";
        }
        cout << endl;
    }
    cout << "MatrixA + MatrixB is : \n";
    for (int i = 0; i < x; i++) // Subtraction.
    {
        cout << "\t";
        for (int j = 0; j < x; j++)
        {
            mResult[i][j] = M1[i][j] - M2[i][j];
            cout << mResult[i][j] << " ";
        }
        cout << endl;
    }
    cout << "MatrixA x MatrixB is : \n";
    for (int i = 0; i < x; i++) // Multiplication.
    {
        cout << "\t";
        for (int j = 0; j < x; j++)
        {
            mResult[i][j] = M1[i][j] * M2[i][j];
            cout << mResult[i][j] << " ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <cmath>
using namespace std;

int **getCofactor(int **matrix, unsigned int size, unsigned int x, unsigned int y);
int findDeterminant(int **matrix, unsigned int size);
void adjoint(int** matrix, int** temp, unsigned int size);
void findInverse(int** matrix, int** temp, unsigned int size);


int main()
{
    int size = 3;
 
    int **matrixA = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        cout << "\t";
        matrixA[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            cin >> matrixA[i][j];
        }
    }

    int **matrixB = new int *[size];
    for (int i = 0; i < size; ++i)
    {   
        cout << "\t";
        matrixB[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            cin >> matrixB[i][j];
        }
    }

    int **tempmatrix = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        tempmatrix[i] = new int [size];
    }

    cout << findDeterminant(matrixA, size) << endl;
    //cout << findDeterminant(matrixB, size);

    findInverse(matrixA, tempmatrix, size);
    findInverse(matrixB, tempmatrix, size);

    return 0;
}

int **getCofactor(int **matrix, unsigned int size, unsigned int x, unsigned int y)
{
    int **Cofactor = new int *[size - 1];
    int minor_m = 0;
    for (int i = 0; i < size; i++)
    {
        Cofactor[minor_m] = new int[size - 1];
        int minor_n = 0;
        if (i == y)
        {
            continue;
        }
        for (int j = 0; j < size; j++)
        {
            if (j == x)
            {
                continue;
            }
            Cofactor[minor_m][minor_n] = matrix[i][j];
            minor_n++;
        }
        minor_m++;
    }
    return Cofactor;
}

int findDeterminant(int **matrix, unsigned int size)
{
    int det = 0;
    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int i = 0; i < size; ++i)
    {
        det += (((i % 2 == 0 ? 1 : -1) * matrix[0][i]) 
            * (findDeterminant(getCofactor(matrix, size, i, 0), size - 1)));
    }
    return det;
}

void adjoint(int** matrix, int** temp, unsigned int size)
{
    int sign;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sign = pow(-1,(i+j));
            temp[i][j] = sign*(findDeterminant(getCofactor(matrix, size, i, 0),size - 1));
        }
    }
    // Transpose
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[i][j] = temp[j][i];
        }
    } 
}

void findInverse(int** matrix, int** temp, unsigned int size)
{
    int det = findDeterminant(matrix, size);
    int numerator, denominator;
    denominator = det;
    if (det == 0)
    {
        cout << "doesn't exist (Det = 0)\n";
    } else
    {
      adjoint(matrix, temp, size);
      for (int i = 0; i < size; i++)
        {
            cout << "\t";
            for (int j = 0; j < size; j++)
            {
                numerator = temp[i][j];
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

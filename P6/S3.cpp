#include <iostream>
using namespace std;

int **getCofactor(int **matrix, unsigned int n, unsigned int x, unsigned int y) {
    int **Cofactor = new int *[n - 1];
    int minor_m = 0;
    for (int i = 0; i < n; i++) {
        Cofactor[minor_m] = new int[n - 1];
        int minor_n = 0;
        if (i == y) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j == x) {
                continue;
            }
            Cofactor[minor_m][minor_n] = matrix[i][j];
            minor_n++;
        }
        minor_m++;
    }
    return Cofactor;
}

int findDeterminant(int **matrix, unsigned int n) {
    int det = 0;
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int i = 0; i < n; ++i) {
        det += ((i % 2 == 0 ? 1 : -1) * matrix[0][i] * findDeterminant(getCofactor(matrix, n, i, 0), n - 1));
    }

    return det;
}

int main() 
{
    int n = 3;
    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << findDeterminant(matrix, n);

    return 0;
}

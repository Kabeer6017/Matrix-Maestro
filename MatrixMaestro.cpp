#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
     int rows1, cols1, rows2, cols2;
    int a[10][10], b[10][10], result[10][10];
     int cofactor[10][10], adjoint[10][10];
     double inverse[10][10];

    int choice;   
     cout<<"-------------------\n";
    cout << "Matrix  Calculator\n";
     cout<<"-------------------\n\n";
    cout << "Select the operation you want to perform:\n";
     cout<<"-----------------------------------------\n";
    cout << "1. Matrix Addition\n";
    cout << "2. Matrix Subtraction\n";
    cout << "3. Matrix Multiplication\n";
    cout << "4. Matrix Transpose\n";
    cout << "5. Determinant\n";
    cout << "6. Matrix Inverse\n";
     cout<<"\n\n";
    cout << "Enter your choice: ";
    cin >> choice;

   

   if(choice>0&&choice<7){
    cout << "Enter rows and columns for first matrix:\n";
    cout << "Rows: ";
    cin >> rows1;
    cout << "Columns: ";
    cin >> cols1;
    cout << "Enter elements of matrix 1:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
        cout << "Enter element a" << i + 1 << j + 1 << " : ";
        cin >> a[i][j];
        }
    }}

    if (choice>0&&choice<4) {
        cout << "Enter rows and columns for second matrix:\n";
        cout << "Rows: ";
        cin >> rows2;
        cout << "Columns: ";
        cin >> cols2;

        cout << "Enter elements of matrix 2:\n";
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
            }
        }
    }

    switch (choice) {
        case 1: 
            if (rows1 == rows2 && cols1 == cols2) {
            cout << "Result of Matrix Addition:\n";
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols1; j++) {
                    result[i][j] = a[i][j] + b[i][j];
                    cout << result[i][j] << " ";
                    }
                    cout << endl;
                }
            } else {
            cout << "Matrix dimensions must be the same for addition\n";
            }
            break;

        case 2: 
            if (rows1 == rows2 && cols1 == cols2) {
            cout << "Result of Matrix Subtraction:\n";
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols1; j++) {
                    result[i][j] = a[i][j] - b[i][j];
                    cout << result[i][j] << " ";
                    }
                    cout << endl;
                }
            } else {
            cout << "Matrix dimensions must be the same for subtraction\n";
            }
            break;

        case 3:
            if (cols1 == rows2) {
            cout << "Result of Matrix Multiplication:\n";
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < cols2; j++) {
                    result[i][j] = 0;
                        for (int k = 0; k < cols1; k++) {
                        result[i][j] += a[i][k] * b[k][j];
                        }
                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }
            } else {
            cout << "Matrix multiplication is not possible. Number of columns of first matrix must equal number of rows of second matrix\n";
            }
            break;

        case 4:
            cout << "Transpose of Matrix 1:\n";
            for (int i = 0; i < cols1; i++) {
                for (int j = 0; j < rows1; j++) {
                cout << a[j][i] << " ";
                }
                cout << endl;
            }
            break;

        case 5: // Determinant
{
    if (rows1 == cols1) { // Ensure the matrix is square
        int det = 0; // Initialize determinant
        int submatrix[10][10]; // Submatrix for cofactors

        if (rows1 == 2) {
            // Base case for 2x2 matrix
            det = ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));
        } else {
            // Recursive determinant calculation for larger matrices
            for (int x = 0; x < rows1; x++) { 
                int subi = 0; // Row index for submatrix
                for (int i = 1; i < rows1; i++) { // Skip the first row
                    int subj = 0; // Column index for submatrix
                    for (int j = 0; j < rows1; j++) {
                        if (j == x) continue; // Skip the current column
                        submatrix[subi][subj] = a[i][j];
                        subj++;
                    }
                    subi++;
                }

                // Recursive call to compute determinant of the submatrix
                int subdet = 0;
                if (rows1 - 1 == 2) { // For 2x2 submatrices
                    subdet = (submatrix[0][0] * submatrix[1][1]) - 
                             (submatrix[0][1] * submatrix[1][0]);
                } else {
                    // Extendable logic for larger submatrices if necessary
                    for (int y = 0; y < rows1 - 1; y++) {
                        int subi2 = 0;
                        int submatrix2[10][10];
                        for (int i2 = 1; i2 < rows1 - 1; i2++) {
                            int subj2 = 0;
                            for (int j2 = 0; j2 < rows1 - 1; j2++) {
                                if (j2 == y) continue;
                                submatrix2[subi2][subj2] = submatrix[i2][j2];
                                subj2++;
                            }
                            subi2++;
                        }
                        subdet += pow(-1, y) * submatrix[0][y] *
                                  ((submatrix2[0][0] * submatrix2[1][1]) -
                                   (submatrix2[0][1] * submatrix2[1][0]));
                    }
                }

                // Add the cofactor expansion term
                det += pow(-1, x) * a[0][x] * subdet;
            }
        }
        cout << "Determinant of Matrix 1 is: " << det << endl;
    } else {
        cout << "Determinant can only be calculated for square matrices\n";
    }
    break;
}


        case 6: // Inverse
{
    if (rows1 == cols1) { // Ensure the matrix is square
        int det = 0;

        // Determinant calculation for a square matrix (handle n > 2)
        if (rows1 == 2) {
            det = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]); // For 2x2 matrix
        } else {
            for (int x = 0; x < rows1; x++) {
                int submatrix[10][10];
                int subi = 0;
                for (int i = 1; i < rows1; i++) { // Exclude the first row
                    int subj = 0;
                    for (int j = 0; j < rows1; j++) {
                        if (j == x) continue; // Exclude the current column
                        submatrix[subi][subj] = a[i][j];
                        subj++;
                    }
                    subi++;
                }
                det += pow(-1, x) * a[0][x] * 
                       ((submatrix[0][0] * submatrix[1][1]) - (submatrix[0][1] * submatrix[1][0]));
            }
        }

        if (det == 0) {
            cout << "Inverse cannot be calculated because determinant is 0\n";
            break;
        }

        // Calculate the cofactor matrix
        for (int row = 0; row < rows1; row++) {
            for (int col = 0; col < rows1; col++) {
                int submatrix[10][10];
                int subi = 0;
                for (int i = 0; i < rows1; i++) {
                    if (i == row) continue; // Skip the current row
                    int subj = 0;
                    for (int j = 0; j < rows1; j++) {
                        if (j == col) continue; // Skip the current column
                        submatrix[subi][subj] = a[i][j];
                        subj++;
                    }
                    subi++;
                }
                cofactor[row][col] = pow(-1, row + col) * 
                                     ((submatrix[0][0] * submatrix[1][1]) - 
                                      (submatrix[0][1] * submatrix[1][0])); // Determinant of submatrix
            }
        }

        // Calculate the adjoint matrix (transpose of cofactor matrix)
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < rows1; j++) {
                adjoint[j][i] = cofactor[i][j];
            }
        }

        // Calculate the inverse matrix
        cout << "Inverse of the matrix is:\n";
        cout << fixed << setprecision(2);
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < rows1; j++) {
                inverse[i][j] = adjoint[i][j] / static_cast<double>(det);
                cout << inverse[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Inverse can only be calculated for square matrices\n";
    }
    break;
}

        default:
            cout << "\nInvalid choice\n";
            break;
    }
cout<<endl;
return 0;
}

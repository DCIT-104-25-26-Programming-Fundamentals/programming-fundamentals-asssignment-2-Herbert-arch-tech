// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);

void transposeMatrix();
void addMatrices();
void multiplyMatrices();


int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        MATRIX OPERATIONS MENU\n";
        cout << "=====================================\n";
        cout << "1. Transpose a Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                transposeMatrix();
                break;

            case 2:
                addMatrices();
                break;

            case 3:
                multiplyMatrices();
                break;

            case 4:
                cout << "\nThank you for using the program.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}


void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}



void displayMatrix(int matrix[10][10], int rows, int cols)
{
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << matrix[i][j];
        }

        cout << endl;
    }
}


void transposeMatrix()
{
    int matrix[10][10];
    int transpose[10][10];

    int rows;
    int cols;

    cout << "\nEnter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << endl;
    readMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}


void addMatrices()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int sum[10][10];

    int rows;
    int cols;

    cout << "\nEnter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter elements for Matrix A\n";
    readMatrix(matrixA, rows, cols);

    cout << "\nEnter elements for Matrix B\n";
    readMatrix(matrixB, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(matrixA, rows, cols);

    cout << "\nMatrix B:\n";
    displayMatrix(matrixB, rows, cols);

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}


void multiplyMatrices()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int product[10][10];

    int rowsA;
    int colsA;
    int rowsB;
    int colsB;

    cout << "\nEnter number of rows for Matrix A: ";
    cin >> rowsA;

    cout << "Enter number of columns for Matrix A: ";
    cin >> colsA;

    cout << "\nEnter number of rows for Matrix B: ";
    cin >> rowsB;

    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "\nMatrix multiplication is not possible.\n";
        cout << "Number of columns in Matrix A must equal";
        cout << " the number of rows in Matrix B.\n";

        return;
    }

    cout << "\nEnter elements for Matrix A\n";
    readMatrix(matrixA, rowsA, colsA);

    cout << "\nEnter elements for Matrix B\n";
    readMatrix(matrixB, rowsB, colsB);

    

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;
        }
    }


    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(matrixA, rowsA, colsA);

    cout << "\nMatrix B:\n";
    displayMatrix(matrixB, rowsB, colsB);

    cout << "\nProduct Matrix:\n";
    displayMatrix(product, rowsA, colsB);
}

#include <stdio.h>

// Function to accept matrix elements from the user
void accept(int matrix[][10], int row, int col)
{
    printf("Enter the elements of matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void display(int result[][10], int row, int col)
{
    printf("Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }
}

// Function for addition
void addition(int matrix1[][10], int matrix2[][10], int result[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function for subtraction
void subtraction(int matrix1[][10], int matrix2[][10], int result[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function for multiplication
void multiplication(int matrix1[][10], int matrix2[][10], int result[][10], int row1, int col1, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += matrix1[i][j] * matrix2[i][j];
            }
        }
    }
}

// Function for transpose
void transpose(int matrix[][10], int result[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}
int main()
{
    int row1, col1, row2, col2, choice, choice1;
    int matrix1[10][10], matrix2[10][10], result[10][10];

    printf("Enter the number of rows and columns of matrix 1:- \n");
    scanf("%d%d", &row1, &col1);
    accept(matrix1, row1, col1);
    display(matrix1, row1, col1);

    printf("Enter the number of rows and columns of matrix 2:-\n");
    scanf("%d%d", &row2, &col2);
    accept(matrix2, row2, col2);
    display(matrix2, row2, col2);

    // Menu
    printf("Choose any of the following operations :- \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Transpose \n");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
        if (row1 == row2 && col1 == col2)
        {
            addition(matrix1, matrix2, result, row1, col1);
            display(result, row1, col1);
        }
        else
        {
            printf("Matrix addition cannot be done\n");
        }
        break;

    case 2:
        if (row1 == row2 && col1 == col2)
        {
            subtraction(matrix1, matrix2, result, row1, col1);
            display(result, row1, col1);
        }
        else
        {
            printf("Matrix subtraction cannot be done\n");
        }
        break;

    case 3:
        if (col1 == row2)
        {
            multiplication(matrix1, matrix2, result, row1, col1, col2);
            display(result, row1, col2);
        }
        else
        {
            printf("Matrix multiplication cannot be done\n");
        }
        break;

    case 4:
        printf("Enter which matrix to transpose 1 or 2 :-\n");
        scanf("%d", &choice1);
        if (choice1 == 1)
        {
            transpose(matrix1, result, row1, col1);
            display(result, col1, row1);
        }
        else if (choice1 == 2)
        {
            transpose(matrix2, result, row2, col2);
            display(result, col2, row2);
        }

        else
        {
            printf("Invalid input\n");
        }
        break;

    default:
        printf("Invalid input\n");
        break;
    }

    return 0;
}
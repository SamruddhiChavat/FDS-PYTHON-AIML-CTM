#include <stdio.h>

// Function to accept matrix elements from the user
void accept(int A[][20], int m, int n)
{
    printf("Enter the elements of matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
}

// Function to display the matrix
void display(int result[][20], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of zeroes in the original matrix
int countzero(int A[][20], int m, int n)
{
    int i, j;
    int count = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}

// Function to form the compact matrix
int compact(int m, int n, int A[][20], int B[][3])
{
    B[0][0] = m;
    B[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }
    B[0][2] = k - 1;
    return k;
}

// Function to display the compact matrix, transpose and addition matrix
void compact_display(int result1[][3], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", result1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to form simple transpose
int simple_transpose(int B[][3], int transpose[][3])
{
    int m, n, t, q;

    m = B[0][0];
    n = B[0][1];
    t = B[0][2];
    q = 1;
    transpose[0][0] = n;
    transpose[0][1] = m;
    transpose[0][2] = t;

    if (t <= 0)
    {
        return 0;
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            for (int p = 1; p <= t; p++)
            {
                if (B[p][1] == col)
                {

                    transpose[q][0] = B[p][1];
                    transpose[q][1] = B[p][0];
                    transpose[q][2] = B[p][2];

                    q++;
                }
            }
        }
    }
}

// Function to form fast transpose
int fast_transpose(int B[][3], int transpose[][3])
{
    int S[20];
    int T[20];
    int m, n, t, q;

    m = B[0][0];
    n = B[0][1];
    t = B[0][2];
    transpose[0][0] = n;
    transpose[0][1] = m;
    transpose[0][2] = t;
    int L;
    if (t <= 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            S[i] = 0;
        }
        for (int j = 1; j <= t; j++)
        {
            int ele = *B[j, 1];
            S[ele] = S[ele] + 1;
        }
        T[0] = 1;
        for (int i = 1; i < n; i++)
        {
            T[i] = T[i - 1] + S[i - 1];
        }
        for (int j = 1; j <= t; j++)
        {
            L = B[j][1];
            transpose[T[L]][0] = B[j][1];
            transpose[T[L]][1] = B[j][0];
            transpose[T[L]][2] = B[j][2];
            T[L] = T[L] + 1;
        }
    }
}

// Function to add two compact matrices
int sparse_addition(int B[][3], int B1[][3], int S[][3])
{
    int i, j, k, l1, l2;
    i = j = k = 1;

    l1 = B[0][2];
    l2 = B1[0][2];

    S[0][0] = B[0][0];
    S[0][1] = B[0][1];

    while (i <= l1 && j <= l2)
    {
        if (B[i][0] == B1[j][0])
        {
            if (B[i][1] == B1[j][1])
            {
                S[k][0] = B[i][0];
                S[k][1] = B[i][1];
                S[k][2] = B[i][2] + B1[j][2];
                i++;
                j++;
                k++;
            }

            else if (B[i][1] < B1[j][1])
            {
                S[k][0] = B[i][0];
                S[k][1] = B[i][1];
                S[k][2] = B[i][2];
                i++;
                k++;
            }

            else if (B[i][1] > B1[j][1])
            {
                S[k][0] = B1[j][0];
                S[k][1] = B1[j][1];
                S[k][2] = B1[j][2];
                j++;
                k++;
            }
        }
        else if (B[i][0] > B1[j][0])
        {
            S[k][0] = B1[j][0];
            S[k][1] = B1[j][1];
            S[k][2] = B1[j][2];
            j++;
            k++;
        }

        else if (B[i][0] < B1[j][0])
        {
            S[k][0] = B[i][0];
            S[k][1] = B[i][1];
            S[k][2] = B[i][2];
            i++;
            k++;
        }
    }

    while ((j <= l2) && (i >= l1))
    {
        S[k][0] = B1[j][0];
        S[k][1] = B1[j][1];
        S[k][2] = B1[j][2];
        j++;
        k++;
    }

    while ((i <= l1) && (j >= l2))
    {
        S[k][0] = B[i][0];
        S[k][1] = B[i][1];
        S[k][2] = B[i][2];
        i++;
        k++;
    }

    S[0][2] = k - 1;
    return k;
}

int main()
{
    int m, n, m1, n1, k, k1, k2, c0, c1;
    int A[20][20], A1[20][20], result[20][20], B[20][3], B1[20][3], transpose[20][3], S[100][3];

    // Taking input from the user for the number of rows and columns of the matrix
    printf("Enter the number of rows and columns of matrix: \n");
    scanf("%d%d", &m, &n);
    printf("\n");

    accept(A, m, n); // Accepting the first matrix elements
    printf("First Matrix:\n");
    display(A, m, n); // Displaying the first matrix

    c0 = countzero(A, m, n); // Storing the value of number of zeros in c0

    if (c0 >= (m * n) / 2) // If the number of zeros is greater than non-zeros then it will display the compact matrix and its transpose else it will display that it is not a sparse matrix
    {
        k = compact(m, n, A, B);

        printf("Compact Matrix:\n");
        compact(m, n, A, B);      // Forming the compact matrix
        compact_display(B, k, 3); // Displaying the compact matrix

        printf("Simple Transpose:\n");
        simple_transpose(B, transpose);   // Forming the simple transpose
        compact_display(transpose, k, 3); // Displaying the simple transpose

        printf("Fast Transpose:\n");
        fast_transpose(B, transpose);     // Forming the fast transpose
        compact_display(transpose, k, 3); // Displaying the fast transpose

        // Taking input from the user for the number of rows and columns of the second matrix
        printf("Enter the number of rows and columns of second matrix : ");
        scanf("%d%d", &m1, &n1);
        printf("\n");

        if (m != m1 || n != n1) // If the number of rows and columns of the two matrices is not equal it will display an error message and terminate
        {
            printf("The matrices are not compatible for addition");
            return -1;
        }

        accept(A1, m1, n1); // Accepting the second matrix elements
        printf("Second Matrix:\n");
        display(A1, m1, n1); // Displaying the second matrix

        c1 = countzero(A1, m1, n1); // Storing the value of number of zeros in c1

        if (c1 >= (m1 * n1) / 2) // If the number of zeros is greater than non-zeros then it will display the compact matrix and further display its addition matrix else it will display that it is not a sparse matrix
        {
            k1 = compact(m1, n1, A1, B1);
            printf("Second Compact Matrix:\n");
            compact(m1, n1, A1, B1);    // Forming the second compact matrix
            compact_display(B1, k1, 3); // Displaying the second compact matrix

            k2 = sparse_addition(B, B1, S);
            printf("Addition matrix : \n");
            sparse_addition(B, B1, S); // Forming the addition compact matrix
            compact_display(S, k2, 3); // Displaying the addition compact matrix
        }
        else
        {
            printf("It is not a sparse matrix");
        }
    }
    else
    {
        printf("It is not a sparse matrix");
    }

    return 0;
}
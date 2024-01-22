#include <stdio.h>

// Function to find the maximum element in the input array
int Max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Bucket sort function to sort the elements in ascending order
void bucket(int arr[], int n)
{
    int max = Max(arr, n);
    int bucket[max + 1];
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[index++] = i;
            bucket[i]--;
        }
    }
}

// Radix sort function to sort the elements in ascending order
void radix(int arr[], int n)
{
    int max = Max(arr, n);
    int div = 1;
    int output[n];

    while (max / div > 0)
    {
        int count[10] = {0};

        for (int i = 0; i < n; i++)
        {
            count[(arr[i] / div) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / div) % 10] - 1] = arr[i];
            count[(arr[i] / div) % 10]--;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }

        div *= 10;
    }
}

int main()
{
    int n, choice;
    // Input the number of first year students
    printf("Enter the number of first-year students : ");
    scanf("%d", &n);

    int marks[n];
    // Input the marks of the students
    printf("Enter the marks of the students:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
    }

    // Select the sorting method to apply
    printf("Enter the type of sorting algorithm to apply :\n 1.Bucket Sort\n 2.Radix Sort\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bucket(marks, n); // Bucket sort function call to sort the scores in ascending order

        printf("\nTop five scores :\n"); // Displaying the top five scores by using 'for' loop by setting the index to the last element of the array
        for (int i = n - 1; i >= n - 5; i--)
        {
            printf("%d\n", marks[i]);
        }
        break;

    case 2:
        radix(marks, n); // Radix sort function call to sort the scores in ascending order

        printf("\nTop five scores :\n"); // Displaying the top five scores by using 'for' loop by setting the index to the last element of the array
        for (int i = n - 1; i >= n - 5; i--)
        {
            printf("%d\n", marks[i]);
        }
        break;
    }
    return 0;
}
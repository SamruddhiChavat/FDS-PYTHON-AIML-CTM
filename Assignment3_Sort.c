#include <stdio.h>
#include <stdlib.h>

// Creating a struct of students
struct student
{
    int roll;
    char name[20];
    float marks;
};

// Function to accept student details
void accept(int n, struct student s[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the student %d details : \n", i + 1);
        printf("Roll No. : ");
        scanf("%d", &s[i].roll);
        printf("Name : ");
        scanf("%s", &s[i].name);
        printf("Marks : ");
        scanf("%f", &s[i].marks);
    }
}

// Function to display sorted student details
void sort_display(int n, struct student s[])
{
    printf("\n----------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------\n");
    printf("Roll No.\tName\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
    printf("----------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------\n\n");
}

// Function to display the details of the searched student
void search_display(int n, struct student s[], int key, int result)
{
    printf("\n----------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------\n");
    printf("Roll No.\tName\t\tMarks\n");
    printf("%d\t\t%s\t\t%.2f\n", s[result].roll, s[result].name, s[result].marks);
    printf("----------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------\n");
}

// Function to perform selection sort
void selection(int n, struct student s[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int minpos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j].roll < s[minpos].roll)
            {
                minpos = j;
            }
        }
        if (minpos != i)
        {
            struct student temp = s[i];
            s[i] = s[minpos];
            s[minpos] = temp;
        }
    }
}

// Function to perform insertion sort
void insertion(int n, struct student s[])
{
    for (int i = 1; i < n; i++)
    {
        struct student temp = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll > temp.roll)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

// Function to perform shell sort
void shell(int n, struct student s[])
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            struct student temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap].roll > temp.roll; j -= gap)
            {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
}

// Function to perform linear search
int linear(int n, struct student s[], int key)
{

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == key)
        {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binary(int n, struct student s[], int low, int high, int key)
{
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (s[mid].roll == key)
        {
            return mid;
        }
        else if (s[mid].roll < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, choice1, choice2, low, high, key, result;
    // Input the number of records to create
    printf("Enter the number of records that you want to create : ");
    scanf("%d", &n);
    // Creating an array of student structs
    struct student s[n];
    accept(n, s); // Input the student data
    // Select the sorting method to apply
    printf("\nEnter the type of sorting method you want to apply : \n 1. Selection Sort\n 2. Insertion Sort\n 3. Shell Sort\n");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        selection(n, s);
        break;

    case 2:
        insertion(n, s);
        break;

    case 3:
        shell(n, s);
        break;
    }

    sort_display(n, s); // Displaying the sorted student data
    // Input the roll number to search
    printf("Enter the roll number to search : ");
    scanf("%d", &key);
    // Select the searching method to apply
    printf("\nEnter the type of search you want to apply : \n 1. Linear \n 2. Binary \n");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1:
        result = linear(n, s, key);
        if (result != -1)
        {
            search_display(n, s, key, result); // Display the student details if Roll Number is found else display "Student not found"
        }
        else
        {
            printf("Student not found\n");
        }
        break;

    case 2:
        result = binary(n, s, low, high, key);
        if (result != -1)
        {
            search_display(n, s, key, result); // Display the student details if Roll Number is found else display "Student not found"
        }
        else
        {
            printf("Student not found\n");
        }
        break;
    }

    return 0;
}
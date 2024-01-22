#include <stdio.h>

#define size 20

int front = -1, rear = -1, elem;

int isfull() // Function to check if the queue is full
{
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

int isempty() // Function to check if the queue is empty 
{
    if (rear == front)
        return 1;
    else
        return 0;
}

int AddQ(int q[], int elem) // Function to add an element to the queue
{
    if (isfull())
    {
        printf("Queue is full");
        return -1;
    }
    else
    {
        rear += 1;
        q[rear] = elem;
        printf("Element %d has been added to the queue\n", elem);
    }
}

int DelQ(int q[]) // Function to delete elements from the queue
{
    if (isempty())
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        front += 1;
        elem = q[front];
        printf("\nElement %d has been deleted from the queue\n", elem);
        return elem;
    }
}

void display(int q[]) // Function to display the elements of the queue
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d\t", q[i]);
    }
    printf("\n");
}

int main()
{
    int ch;
    int queue[size];

    while (1) 
    {
    printf("\nEnter the operation to be performed : \n1.Add element\n2.Delete element\n3.Display Queue\n4.Exit\n"); // Taking input of the operation to be performed
    scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be added to the queue : ");
            scanf("%d", &elem);
            AddQ(queue, elem);
            break;
        case 2:
            DelQ(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            printf("Exiting!!!\n");
            return 0;
            break;
        default:
            printf("Invalid Choice!!!");
        }
    }
    return 0;
}
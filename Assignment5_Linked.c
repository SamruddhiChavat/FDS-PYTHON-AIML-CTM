#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to represent the club members
struct club_mem
{
    char PRN[20];
    char name[50];
    char year[10];
    char position[20];
    struct club_mem *next;
};

// Function to create the list of club members
struct club_mem *createMembers()
{
    struct club_mem *head = (struct club_mem *)malloc(sizeof(struct club_mem));
    head->next = NULL;

    struct club_mem *temp = head;
    char ch = 'y';

    while (1)
    {
        struct club_mem *current = (struct club_mem *)malloc(sizeof(struct club_mem));
        printf("Enter PRN: ");
        scanf("%s", current->PRN);
        printf("Enter Name: ");
        scanf("%s", current->name);
        printf("Enter Year: ");
        scanf("%s", current->year);
        printf("Enter Position: ");
        scanf("%s", current->position);
        current->next = NULL;

        temp->next = current;
        temp = current;

        printf("Do you want to continue adding club members (y/n): ");
        scanf(" %c", &ch);

        if (ch == 'n')
        {
            break;
        }
    }

    return head;
}

// Function to display the list of club members
void display_members(struct club_mem *head)
{
    struct club_mem *current = head->next;

    while (current != NULL)
    {
        printf("%s\t%s\t%s\t%s\n", current->PRN, current->name, current->year, current->position);
        current = current->next;
    }
}

// Function to count the total number of members in the club
int member_count(struct club_mem *head)
{
    int count = 0;
    struct club_mem *current = head->next;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Function to insert a member at a specified position in the list. This function is used for adding the president at the first node and the secretary at the last node
struct club_mem *insertByPos(struct club_mem *head, struct club_mem *nodeToInsert, int pos)
{
    int i = 1;
    struct club_mem *current = head;

    if (pos > member_count(head) + 1)
    {
        printf("Data can't be inserted.\n");
    }
    else
    {
        while (current != NULL && i < pos)
        {
            i++;
            current = current->next;
        }

        nodeToInsert->next = current->next;
        current->next = nodeToInsert;
    }

    return head;
}

// Function to delete a member with a specific PRN
struct club_mem *deleteMember(struct club_mem *head, char prn[])
{
    struct club_mem *current = head;
    struct club_mem *previous = NULL;

    while (current != NULL && strcmp(current->PRN, prn) != 0)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Member with PRN %s not found.\n", prn);
        return head;
    }

    if (previous != NULL)
    {
        previous->next = current->next;
    }

    free(current);
    printf("Member with PRN %s deleted.\n", prn);
    return head;
}

// Function to merge two lists of the club members
void mergeLists(struct club_mem *list1, struct club_mem *list2)
{
    struct club_mem *current1 = list1->next;
    struct club_mem *current2 = list2->next;
    struct club_mem *temp;

    int flag;

    if (strcmp(current1->PRN, current2->PRN) < 0)
    {
        temp = list1;
        flag = 1;
    }
    else
    {
        temp = list2;
        flag = 0;
    }

    while (current1 != NULL && current2 != NULL)
    {
        if (strcmp(current1->PRN, current2->PRN) < 0)
        {
            temp->next = current1;
            temp = current1;
            current1 = current1->next;
        }
        else
        {
            temp->next = current2;
            temp = current2;
            current2 = current2->next;
        }
    }

    if (current1 == NULL)
    {
        temp->next = current2;
    }

    if (current2 == NULL)
    {
        temp->next = current1;
    }

    if (flag == 1)
    {
        display_members(list1);
    }
    else
    {
        display_members(list2);
    }
}

// Function to sort the list of club members by PRN
void sortList(struct club_mem *head)
{
    int len = member_count(head);

    for (int i = 1; i < len; i++)
    {
        struct club_mem *prev = head;
        struct club_mem *current = head->next;

        for (int j = 0; j < len - i; j++)
        {
            struct club_mem *temp = current->next;

            if (strcmp(current->PRN, temp->PRN) > 0)
            {
                prev->next = temp;
                current->next = temp->next;
                temp->next = current;
                prev = temp;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
}

// Function to reverse the order of club members in the list by PRN
struct club_mem *reverseList(struct club_mem *head)
{
    struct club_mem *prev = NULL;
    struct club_mem *current = head->next;
    struct club_mem *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head->next = prev;
    return head;
}

int main()
{
    int choice;
    struct club_mem *club_memlist = (struct club_mem *)malloc(sizeof(struct club_mem)); // Allocating memory using malloc()
    club_memlist->next = NULL;

    do
    {
        printf("1. Create List\n2. Display List\n3. Count of club members\n4. Add president\n5. Add Secretary\n6. Delete Member\n7. Sort List\n8. Merge Lists\n9. Reverse List\n10. Exit\n");
        printf("Enter your choice: "); // Asking the user for the operation to be performed
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            if (club_memlist->next == NULL)
                club_memlist = createMembers();
            else
                printf("The list already exists.\n");
            break;

        case 2:
            if (club_memlist->next != NULL)
            {
                printf("\n-----------Club Members List---------\nPRN\tName\tYear\tPosition\n");
                display_members(club_memlist);
            }
            else
                printf("\nNo List was found\n");
            break;

        case 3:
            if (club_memlist->next != NULL)
            {
                int length = member_count(club_memlist);
                printf("Club member count: %d\n", length);
            }
            else
                printf("No list was found\n");
            break;

        case 4:
            if (club_memlist->next != NULL)
            {
                struct club_mem *president = (struct club_mem *)malloc(sizeof(struct club_mem));
                printf("Enter PRN: ");
                scanf("%s", president->PRN);
                printf("Enter Name: ");
                scanf("%s", president->name);
                printf("Enter Year: ");
                scanf("%s", president->year);
                printf("Enter Position: ");
                scanf("%s", president->position);
                president->next = NULL;

                club_memlist = insertByPos(club_memlist, president, 1);
                printf("President added successfully.\n");
            }
            else
            {
                printf("No list was found. Create a list first.\n");
            }
            break;

        case 5:
            if (club_memlist->next != NULL)
            {
                struct club_mem *secretary = (struct club_mem *)malloc(sizeof(struct club_mem));
                printf("Enter PRN: ");
                scanf("%s", secretary->PRN);
                printf("Enter Name: ");
                scanf("%s", secretary->name);
                printf("Enter Year: ");
                scanf("%s", secretary->year);
                printf("Enter Position: ");
                scanf("%s", secretary->position);
                secretary->next = NULL;

                int length = member_count(club_memlist);
                club_memlist = insertByPos(club_memlist, secretary, length + 1);
                printf("Secretary added successfully.\n");
            }
            else
            {
                printf("No list was found. Create a list first.\n");
            }
            break;

        case 6:
            if (club_memlist->next != NULL)
            {
                char prn[20];
                printf("Enter the PRN to delete: ");
                scanf("%s", prn);
                club_memlist = deleteMember(club_memlist, prn);
            }
            else
                printf("No list was found. Create a list first.\n");
            break;

        case 7:
            if (club_memlist->next != NULL)
            {
                sortList(club_memlist);
                printf("List sorted successfully.\n");
            }
            else
                printf("No list was found. Create a list first.\n");
            break;

        case 8:
            if (club_memlist->next != NULL)
            {
                struct club_mem *club_memlist2 = createMembers();
                mergeLists(club_memlist, club_memlist2);
                printf("Lists merged successfully.\n");
            }
            else
                printf("No list was found. Create a list first.\n");
            break;

        case 9:
            if (club_memlist->next != NULL)
            {
                club_memlist = reverseList(club_memlist);
                printf("List reversed successfully.\n");
            }
            else
                printf("No list was found. Create a list first.\n");
            break;

        case 10:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!!!\n");
        }
    } while (choice != 10);

    // Free the allocated memory
    struct club_mem *current = club_memlist->next;
    while (current != NULL)
    {
        struct club_mem *temp = current;
        current = current->next;
        free(temp);
    }
    free(club_memlist);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 20

int top = -1;
char stack[MAX];
char str_stack[MAX][20]; // String stack for operands

int isFull(char stack[]) // Function for checking if the stack is full
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty(char stack[]) // Function for checking if the stack is empty
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int str_isFull(char str_stack[][20]) // Function to check if the string stack is full
{
    if (top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int str_isEmpty(char str_stack[][20]) // Function to check if the string stack is empty
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(char stack[], char item) // Function to push items into the stack
{
    if (!isFull(stack))
    {
        top += 1;
        stack[top] = item;
    }
    else
    {
        printf("Stack is full. Cannot push.\n");
    }
}

char pop(char stack[]) // Function to pop items from the stack
{
    char temp;
    if (!isEmpty(stack))
    {
        temp = stack[top];
        top -= 1;
        return temp;
    }
    else
    {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
}

void str_push(char str_stack[][20], char str[]) // Function to push strings into the string stack
{
    if (!isFull(stack))
    {
        top++;
        strcpy(str_stack[top], str);
    }
    else
    {
        printf("Stack is full. Cannot push.\n");
    }
}

void str_pop(char str_stack[][20], char str[]) // Function to pop strings from the string stack
{

    if (!str_isEmpty(str_stack))
    {
        strcpy(str, str_stack[top]);
        top--;
    }
    else
    {
        printf("Stack is empty. Cannot pop.\n");
    }
}

int ICP(char ch) // Function to get Incoming Precedence for operators
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 4;
    if (ch == '(')
        return 5;
    return 0;
}

int ISP(char ch) // Function to get In-Stack Precedence for operators
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

void display(char stack[]) // Function to display the contents of the stack
{
    if (!isEmpty(stack))
    {
        printf("The contents of the stack are:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
}

void in_to_post(char in_exp[], char post_exp[]) // Function to convert infix to postfix
{
    int i = 0;
    int j = 0;

    char tkn = in_exp[i];

    while (tkn != '\0')
    {
        if (isalnum(tkn))
        {
            post_exp[j++] = tkn;
        }
        else
        {
            if (tkn == '(')
            {
                push(stack, tkn);
            }
            else if (tkn == ')')
            {

                while (!isEmpty(stack) && stack[top] != '(')
                {
                    post_exp[j++] = pop(stack);
                }
                if (!isEmpty(stack) && stack[top] == '(')
                {
                    pop(stack);
                }
            }
            else
            {

                while (!isEmpty(stack) && ISP(stack[top]) >= ICP(tkn))
                {
                    post_exp[j++] = pop(stack);
                }
                push(stack, tkn);
            }
        }

        i++;
        tkn = in_exp[i];
    }

    while (!isEmpty(stack))
    {
        post_exp[j++] = pop(stack);
    }

    post_exp[j] = '\0';
}

void post_to_in(char post_exp[], int size) // Function to convert postfix to infix
{
    int i = 0;
    int j = 0;

    top = -1;

    char temp[2];

    char string1[size];
    char string2[size];

    char infix[size + 1];

    for (j = 0; j <= size; j++)
    {
        infix[j] = '\0';
    }

    while (post_exp[i] != '\0')
    {
        if (isalnum(post_exp[i]))
        {
            temp[0] = post_exp[i];
            temp[1] = '\0';

            str_push(str_stack, temp);
        }
        else
        {
            temp[0] = post_exp[i];
            temp[1] = '\0';

            str_pop(str_stack, string1);
            str_pop(str_stack, string2);

            strcpy(infix, "(");
            strcat(infix, string2);
            strcat(infix, temp);
            strcat(infix, string1);
            strcat(infix, ")");

            str_push(str_stack, infix);
        }
        i++;
    }

    str_pop(str_stack, infix);
    printf("The infix expression is : %s\n", infix);
}

void pre_to_in(char prefix[], int size) // Function to convert prefix to infix
{
    int i = 0;
    int j = 0;

    top = -1;

    char temp[2];

    char string1[size];
    char string2[size];

    char infix[size + 1];

    char rev_prefix[strlen(prefix)];
    strrev(prefix);

    for (j = 0; j <= size; j++)
    {
        infix[j] = '\0';
    }

    while (prefix[i] != '\0')
    {
        if (isalnum(prefix[i]))
        {
            temp[0] = prefix[i];
            temp[1] = '\0';

            str_push(str_stack, temp);
        }
        else
        {
            temp[0] = prefix[i];
            temp[1] = '\0';

            str_pop(str_stack, string1);
            str_pop(str_stack, string2);

            strcpy(infix, "(");
            strcat(infix, string2);
            strcat(infix, temp);
            strcat(infix, string1);
            strcat(infix, ")");

            str_push(str_stack, infix);
        }
        i++;
    }

    str_pop(str_stack, infix);
    printf("\nThe infix expression is : %s\n", infix);
}

int main()
{
    int ch;
    int size = 0;
    char infix[MAX], postfix[MAX], postfix1[MAX], infix1[MAX], prefix[MAX], infix2[MAX];

    printf("Choose the conversion to be performed : \n1. Infix to Postfix\n2. Postfix to Infix\n3. Prefix to Infix\n"); // Taking input of the type of conversion to be performed
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("\nEnter an Infix expression: "); // Taking input of infix expression
        scanf("%s", infix);

        in_to_post(infix, postfix); // Converting infix to postfix and displaying
        printf("Postfix expression: %s\n", postfix);
        break;
    case 2:
        printf("\nEnter a postfix expression: \n"); // Taking input of postfix expression
        scanf("%s", postfix1);
        size = strlen(postfix1);

        post_to_in(postfix1, size); // Converting postfix to infix and displaying
        break;
    case 3:
        printf("\nEnter a prefix expression: \n"); // Taking input of prefix expression
        scanf("%s", prefix);
        size = strlen(prefix);

        pre_to_in(prefix, size); // Converting prefix to infix and displaying
        break;
    default:
        printf("Invalid Choice!!!");
    }

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX 20

int top = -1;
char stack[MAX];

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

    printf("Postfix expression: %s\n", post_exp);
}

int calc(int a, int b, char op) // Function to perform arithmetic calculations based on operators
{
    int ans;
    switch (op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    default:
        ans = 0;
    }
    return ans;
}

void postfix_eval(char post_exp[]) // Function for postfix evaluation
{
    for (int i = 0; post_exp[i] != '\0'; i++)
    {

        if (isalpha(post_exp[i])) 
        {
            int x;
            printf("\nEnter value of %c is ", post_exp[i]);
            scanf("%d", &x);
            push(stack, x);
        }
        else if (isdigit(post_exp[i])) 
        {
            int x = post_exp[i] - '0';

            push(stack, x);
        }
        else
        {
            int op1, op2;
            op2 = pop(stack);
            op1 = pop(stack);

            int ans = calc(op1, op2, post_exp[i]); 

            printf("%d%c%d = %d\n", op1, post_exp[i], op2, ans);

            push(stack, ans); 
        }
    }

    printf("\nEvaluation is : %d", stack[top]);
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("\nEnter an Infix expression: "); // Taking input of infix expression
    scanf("%s", &infix);

    in_to_post(infix, postfix); // Converting infix to postfix and displaying
    postfix_eval(postfix); // Displaying the answer after postfix evaluation

    return 0;
}
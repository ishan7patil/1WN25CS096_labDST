#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(char item) 
{
    if (top >= MAX -1) 
    {
        printf("stack overflow!\n");
        return;
    }
    else 
    {
        top++;
        stack[top] = item;
    }
}

char pop() 
{
    char item;

    if (top == -1) 
    {
        printf("stack underflow!\n");
        return '\0';
    }
    else 
    {
        item = stack[top];
        top--;
        return item;
    }
}

int precedence(char operator) 
{
    if (operator == '^')
    {
        return 3;
    }
    else if (operator == '*' || operator == '/' || operator == '%') 
    {
        return 2;
    }
    else if (operator == '+' || operator == '-')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) 
{
    int i = 0; //iterate infix[]
    int j = 0; //iterate postfix[] 
    char symbol;

    push('(');

    int length = 0;

    while (infix[length] != '\0')
    {
        length++;
    }

    infix[length] = ')';

    infix[length+1] = '\0';

    while(infix[i] != '\0') 
    {
        symbol = infix[i];

        if (symbol == ' ') 
        {
            i++;
            continue;
        }
        else if (symbol == '(') 
        {
            push(symbol);
        }
        else if (isalpha(symbol) || isdigit(symbol))
        {
            postfix[j] = symbol;
            j++;
        }
        else if (symbol == ')')
        {
            while (top != -1 && stack[top] != '(') 
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else 
        {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
        }

        i++;

    }

    postfix[j] = '\0';
}

int main() 
{
    char infix[MAX];
    char postfix[MAX];

    printf("enter an expression: ");
    scanf("%s", infix);

    printf("infix expression: %s\n", infix);

    infixToPostfix(infix, postfix);

    printf("postfix expression: %s\n", postfix);

    return 0;
}
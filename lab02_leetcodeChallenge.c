#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    char word[MAX];
    char ch;
    char stack[MAX];
    int top = -1;
    int i = 0;

    printf("enter the word: ");
    scanf("%s", word);

    printf("enter the character: ");
    scanf(" %c", &ch);

    while (word[i] != '\0')
    {
        stack[++top] = word[i];

        if (word[i] == ch)
        {
            break;
        }

        i++;
    }

    if (word[i] == '\0')
    {
        printf("result: %s\n", word);
        return 0;
    }

    i = 0;

    while (top >= 0)
    {
        word[i] = stack[top];
        top--;
        i++;
    }

    printf("result: %s\n", word);

    return 0;
}
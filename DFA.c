#include <stdio.h>

int main()
{
    char str[100], f = '1';

    printf("Enter the string : ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (f)
        {
        case '1':
            if (str[i] == 'a')
            {
                f = '2';
            }
            else if (str[i] == 'b')
            {
                f = '2';
            }
            break;

        case '2':
            if (str[i] == 'a')
            {
                f = '3';
            }
            else if (str[i] == 'b')
            {
                f = '3';
            }
            break;

        case '3':
            if (str[i] == 'a')
            {
                f = '4';
            }
            else if (str[i] == 'b')
            {
                f = 'd';
            }
            break;

        case '4':
            if (str[i] == 'a')
            {
                f = '4';
            }
            else if (str[i] == 'b')
            {
                f = '4';
            }
            break;

        case 'd':
            if (str[i] == 'a')
            {
                f = 'd';
            }
            else if (str[i] == 'b')
            {
                f = 'd';
            }
            break;
        }
    }

    if (f == '4')
    {
        printf("String is Accepted");
    }
    else
    {
        printf("String is not accepted");
    }

    return 0;
}
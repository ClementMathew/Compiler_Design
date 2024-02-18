#include <stdio.h>
#include <string.h>
#include <ctype.h>

char a[10][10], b[10], f[10], x, c, ch;
int m, n, i, j, z = 0, l = 0;

void first(char);
void append(char);
int in(char);

void main()
{
    printf("enter the number of productions:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%c", a[i], &ch);
    }
    for (int i = 0; i < n; i++)
    {
        l = in(a[i][0]);
        if (l == 0)
        {
            append(a[i][0]);
            memset(f, '\0', 10);
            first(a[i][0]);
            x = a[i][0];
            m = 0;
            printf("first(%c)=%s\n", a[i][0], f);
        }
    }
}
void first(char c)
{
    /*terminal --> f=c
non term --> first (non term)
#  case 1: x==c --> #
   case 2: x!=c
        if there is symbol on right --> first(symbol on right)
        else if '\0' on right --> # */
    if (islower(c))
    {
        f[m++] = c;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == c)
        {
            if (islower(a[i][2]))
            {
                f[m++] = a[i][2];
            }
            else if (a[i][2] == '#')
            {
                if (x == c)
                {
                    f[m++] = '#';
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < strlen(a[i]); j++)
                        {
                            if (a[i][0] == x && a[i][j] == c && a[i][j + 1] != '\0')
                            {
                                first(a[i][j + 1]);
                            }
                            else if (a[i][0] == x && a[i][j] == c && a[i][j + 1] == '\0')
                            {
                                f[m++] = '#';
                            }
                        }
                    }
                }
            }
            else
            {
                first(a[i][2]);
            }
        }
    }
}
int in(char d)
{
    int flag = 0;
    for (int i = 0; i < strlen(b); i++)
    {
        if (b[i] == d)
        {
            flag = 1;
        }
    }
    return flag;
}
void append(char d)
{
    b[strlen(b)] = d;
    b[strlen(b) + 1] = '\0';
}
#include <stdio.h>
#include <ctype.h>

void FIRSTT(char);
int count, n = 0;
char prodn[10][10], first[10];

main()
{
    int i, choice;
    char c, ch;
    printf("How many productions ? :");
    scanf("%d", &count);
    printf("Enter %d productions epsilon= $ :\n\n", count);
    for (i = 0; i < count; i++)
        scanf("%s%c", prodn[i], &ch);
    do
    {
        n = 0;
        printf("Element :");
        scanf("%c", &c);
        FIRSTT(c);
        printf("\n FIRSTT(%c)= { ", c);
        for (i = 0; i < n; i++)
            printf("%c ", first[i]);
        printf("}\n");

        printf("press 1 to continue : ");
        scanf("%d%c", &choice, &ch);
    } while (choice == 1);
}

void FIRSTT(char c)
{
    int j;
    if (!(isupper(c)))
        first[n++] = c;
    for (j = 0; j < count; j++)
    {
        if (prodn[j][0] == c)
        {
            if (prodn[j][2] == '$')
                first[n++] = '$';
            else if (islower(prodn[j][2]))
                first[n++] = prodn[j][2];
            else
                FIRSTT(prodn[j][2]);
        }
    }
}
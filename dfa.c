#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void epsilon()
{
    printf("\nNullable = true");
    printf("\nFirst position = NULL");
    printf("\nLast position = NULL");
}

void leaf()
{
    int i;
    printf("\nEnter the position of leaf node: ");
    scanf("%d", &i);
    printf("\nNullable = false");
    printf("\nFirst position = %d", i);
    printf("\nLast position = %d", i);
}

void orr()
{
    int first_pos_c1[10], first_pos_c2[10], u[20], i, j, k, n, m;
    int last_pos_c1[10], last_pos_c2[10], v[20], a, b, c, p, q;
    // c1
    bool nullable_c1;
    printf("Enter the nullable of child C1(0,1): ");
    scanf("%d", &nullable_c1);

    // first position c1
    printf("Enter the size of first postion of C1: ");
    scanf("%d", &n);
    printf("Enter the first position of child C1: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &first_pos_c1[i]);

    // last position c1
    printf("Enter the size of last postion of C1: ");
    scanf("%d", &p);
    printf("Enter the last position of child C1: ");
    for (int a = 0; a < p; ++a)
        scanf("%d", &last_pos_c1[a]);

    // c2
    bool nullable_c2;
    printf("Enter the nullable of child C2(0,1): ");
    scanf("%d", &nullable_c2);

    // first position c2
    printf("Enter the size of first postion of C2: ");
    scanf("%d", &m);
    printf("Enter the first position of child C2: ");
    for (int i = 0; i < m; ++i)
        scanf("%d", &first_pos_c2[i]);

    // last position c2
    printf("Enter the size of last postion of C2: ");
    scanf("%d", &q);
    printf("Enter the last position of child C2: ");
    for (int a = 0; a < q; ++a)
        scanf("%d", &last_pos_c2[a]);

    // nullable
    bool nullable;
    nullable = nullable_c1 || nullable_c2;
    if (nullable == true)
        printf("\nNullable = true");
    else
        printf("\nNullable = false");

    // first position
    for (i = 0, j = 0, k = 0; i < n && j < m;)
    {
        if (first_pos_c1[i] < first_pos_c2[j])
        {
            u[k] = first_pos_c1[i];
            i++;
            k++;
        }
        else if (first_pos_c1[i] > first_pos_c2[j])
        {
            u[k] = first_pos_c2[j];
            j++;
            k++;
        }
        else
        {
            u[k] = first_pos_c1[i];
            i++;
            j++;
            k++;
        }
    }
    if (i < n)
    {
        for (; i < n; ++i)
        {
            u[k] = first_pos_c1[i];
            k++;
        }
    }
    else if (j < m)
    {
        for (; j < m; ++j)
        {
            u[k] = first_pos_c2[j];
            k++;
        }
    }
    printf("\nFirst position = ");
    for (i = 0; i < k; ++i)
    {
        printf("%d,", u[i]);
    }

    // last position
    for (a = 0, b = 0, c = 0; a < p && b < q;)
    {
        if (last_pos_c1[a] < last_pos_c2[b])
        {
            v[c] = last_pos_c1[a];
            a++;
            c++;
        }
        else if (last_pos_c1[a] > last_pos_c2[b])
        {
            v[c] = last_pos_c2[b];
            b++;
            c++;
        }
        else
        {
            v[c] = last_pos_c1[a];
            a++;
            b++;
            c++;
        }
    }
    if (a < p)
    {
        for (; a < p; ++a)
        {
            v[c] = last_pos_c1[a];
            c++;
        }
    }
    else if (b < q)
    {
        for (; b < q; ++b)
        {
            v[c] = last_pos_c2[b];
            c++;
        }
    }
    printf("\nlast position = ");
    for (a = 0; a < c; ++a)
    {
        printf("%d,", v[a]);
    }
}

void cat()
{
    int first_pos_c1[10], first_pos_c2[10], u[20], i, j, k, n, m;
    int last_pos_c1[10], last_pos_c2[10], v[20], a, b, c, p, q;
    // c1
    bool nullable_c1;
    printf("Enter the nullable of child C1(0,1): ");
    scanf("%d", &nullable_c1);

    // first position c1
    printf("Enter the size of first postion of C1: ");
    scanf("%d", &n);
    printf("Enter the first position of child C1: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &first_pos_c1[i]);

    // last position c1
    printf("Enter the size of last postion of C1: ");
    scanf("%d", &p);
    printf("Enter the last position of child C1: ");
    for (int a = 0; a < p; ++a)
        scanf("%d", &last_pos_c1[a]);

    // c2
    bool nullable_c2;
    printf("Enter the nullable of child C2(0,1): ");
    scanf("%d", &nullable_c2);

    // first position c2
    printf("Enter the size of first postion of C2: ");
    scanf("%d", &m);
    printf("Enter the first position of child C2: ");
    for (int i = 0; i < m; ++i)
        scanf("%d", &first_pos_c2[i]);

    // last position c2
    printf("Enter the size of last postion in C2: ");
    scanf("%d", &q);
    printf("Enter the last position of child C2: ");
    for (int a = 0; a < q; ++a)
        scanf("%d", &last_pos_c2[a]);

    // nullable
    bool nullable;
    nullable = nullable_c1 && nullable_c2;
    if (nullable == true)
        printf("\nNullable = true");
    else
        printf("\nNullable = false");

    // first position
    if (nullable_c1 == true)
    {
        for (i = 0, j = 0, k = 0; i < n && j < m;)
        {
            if (first_pos_c1[i] < first_pos_c2[j])
            {
                u[k] = first_pos_c1[i];
                i++;
                k++;
            }
            else if (first_pos_c1[i] > first_pos_c2[j])
            {
                u[k] = first_pos_c2[j];
                j++;
                k++;
            }
            else
            {
                u[k] = first_pos_c1[i];
                i++;
                j++;
                k++;
            }
        }
        if (i < n)
        {
            for (; i < n; ++i)
            {
                u[k] = first_pos_c1[i];
                k++;
            }
        }
        else if (j < m)
        {
            for (; j < m; ++j)
            {
                u[k] = first_pos_c2[j];
                k++;
            }
        }
        printf("\nFirst position = ");
        for (i = 0; i < k; ++i)
        {
            printf("%d,", u[i]);
        }
    }
    else
    {
        printf("\nFirst position = ");
        for (i = 0; i < n; ++i)
        {
            printf("%d,", first_pos_c1[i]);
        }
    };

    // last position
    if (nullable_c1 == true)
    {
        for (a = 0, b = 0, c = 0; a < p && b < q;)
        {
            if (last_pos_c1[a] < last_pos_c2[b])
            {
                v[c] = last_pos_c1[a];
                a++;
                c++;
            }
            else if (last_pos_c1[a] > last_pos_c2[b])
            {
                v[c] = last_pos_c2[b];
                b++;
                c++;
            }
            else
            {
                v[c] = last_pos_c1[a];
                a++;
                b++;
                c++;
            }
        }
        if (a < p)
        {
            for (; a < p; ++a)
            {
                v[c] = last_pos_c1[a];
                c++;
            }
        }
        else if (b < q)
        {
            for (; b < q; ++b)
            {
                v[c] = last_pos_c2[b];
                c++;
            }
        }
        printf("\nLast position = ");
        for (a = 0; a < c; ++a)
        {
            printf("%d,", v[a]);
        }
    }
    else
    {
        printf("\nLast position = ");
        for (a = 0; a < q; ++a)
        {
            printf("%d,", last_pos_c2[a]);
        }
    }
}

void star()
{
    // first position c1
    printf("\nEnter the size of first postion of C1: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the first position of child C1: ");
    int first_pos_c1[10];
    for (int i = 0; i < n; ++i)
        scanf("%d", &first_pos_c1[i]);

    // last position c1
    printf("\nEnter the size of last postion of C1: ");
    int p;
    scanf("%d", &p);
    printf("\nEnter the last position of child C1: ");
    int last_pos_c1[10];
    for (int a = 0; a < p; ++a)
        scanf("%d", &last_pos_c1[a]);

    // first position
    printf("\nFirst position = ");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", first_pos_c1[i]);
    }

    // last position
    printf("\nLast position = ");
    for (int a = 0; a < p; ++a)
    {
        printf("%d,", last_pos_c1[a]);
    }

    // nullable
    printf("\nNullable = true");
}

int main()
{
    int j;
    while (1)
    {
        printf("\n\n1.Epsilon(E)\n2.Leaf Node\n3.Or(|)\n4.Cat(.)\n5.Star(*)\nEnter Choice: ");
        scanf("%d", &j);
        switch (j)
        {
        case 1:
        {
            printf("Epsilon E\n\n");
            epsilon();
            break;
        }
        case 2:
        {
            printf("Leaf Node\n\n");
            leaf();
            break;
        }
        case 3:
        {
            printf("Or |\n\n");
            orr();
            break;
        }
        case 4:
        {
            printf("Cat .\n\n");
            cat();
            break;
        }
        case 5:
        {
            printf("Star *\n\n");
            star();
            break;
        }
        }
    }
}
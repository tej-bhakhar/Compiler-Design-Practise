#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count, n = 0, i = 0, k = 0;
char pron[10][10], first[10];
void FOLLOW(char c);
void FIRST(char c);

int main()
{
  int i, choice;
  char c, ch;
  printf("\nEnter the no. of productions: ");
  scanf("%d", &count);
  printf("\nEnter %d productions(epsilon=$): \n", count);
  for (i = 0; i < count; i++)
    scanf("%s%c", pron[i], &ch);

  do
  {
    n = 0;
    printf("\nEnter the element whose FOLLOW is to be found:");
    scanf("%c", &c);
    FOLLOW(c);
    printf("FOLLOW(%c) = { ", c);
    for (i = 0; i < n; i++)
      printf("%c ", first[i]);
    printf(" }\n");
    printf("\nDo you want to continue(0/1): ");
    scanf("%d%c", &choice, &ch);
  } while (choice == 1);

  do
  {
    n = 0;
    printf("Enter the element whose FIRST is to be found:");
    scanf("%c", &c);
    FIRSTT(c);
    printf("\n FIRST(%c)= { ", c);
    for (i = 0; i < n; i++)
      printf("%c ", first[i]);
    printf("}\n");

    printf("\nDo you want to continue(0/1): ");
    scanf("%d%c", &choice, &ch);
  } while (choice == 1);
}
void FOLLOW(char c)
{

  if (pron[0][0] == c)
    first[n++] = '$';
  for (i = 0; i < count; i++)
  {
    for (k = 2; k < strlen(pron[i]); k++)
    {
      if (pron[i][k] == c)
      {
        if (pron[i][k + 1] != '\0')
          FIRST(pron[i][k + 1]);

        if (pron[i][k + 1] == '\0' && c != pron[i][0])
          FOLLOW(pron[i][0]);
      }
    }
  }
}
void FIRST(char c)
{
  int k;
  if (!(isupper(c)))
    first[n++] = c;
  for (k = 0; k < count; k++)
  {
    if (pron[k][0] == c)
    {
      if (pron[k][2] == '$')
        FOLLOW(pron[i][0]);
      else if (islower(pron[k][2]))
        first[n++] = pron[k][2];
      else
        FIRST(pron[k][2]);
    }
  }
}

void FIRSTT(char c)
{
  int k;
  if (!(isupper(c)))
    first[n++] = c;
  for (k = 0; k < count; k++)
  {
    if (pron[k][0] == c)
    {
      if (pron[k][2] == '$')
        first[n++] = '$';
      else if (islower(pron[k][2]))
        first[n++] = pron[k][2];
      else
        FIRSTT(pron[k][2]);
    }
  }
}
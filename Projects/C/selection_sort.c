#include <stdio.h>

static void print(int tab[], int n)
{
  printf("%i", tab[0]);
  for (int i = 1; i < n; ++i)
    printf(" %i", tab[i]);
  printf("\n");
}

static void selection_sort(int *tab, int n)
{
  int min = 0;
  for (int i = 0; i < n - 2; ++i)
  {
    min = i;
    for (int j = i + 1; j < n - 1; ++j)
      if (tab[j] < tab[min])
        min = j;
    tab[min] = tab[i];
  }
  print(tab, 7);
}

int main(void)
{
  int tab[] =
  {
    10, 1337, 42, 123, 32, 5, 46
  };
  printf("Selection sort example\n");
  printf("Example: \n");
  print(tab, 7);
  // Sort
  printf("Selection sort: \n");
  selection_sort(tab, 7);
  return 0;
}

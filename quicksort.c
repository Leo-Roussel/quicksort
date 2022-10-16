#include <stdio.h>
#include <assert.h>

void sort_check(float tab[], int size)
{
  int i;
  printf("Running through the table.. ");
  for (i=1; i<size; i++)
    assert(tab[i-1]<=tab[i]);
  printf("The table is well sorted\n");
}

void sort_check_ld(long double tab[], int size)
{
  int i;
  printf("Running through the table.. ");
  for (i=1; i<size; i++)
    assert(tab[i-1]<=tab[i]);
  printf("The table is well sorted\n");
}

int partition(float tab[], int size)
{
  float x, y;
  int down, up, i;
  x = tab[0];
  down = 1;
  up = size - 1;
  do /* loop at least once (size = 2 => down = up) */
    {
      while (tab[down] < x && down < size-1)
	down++;
      while (tab[up] > x)
	up--;
      if (down < up)
	{
	  y = tab[down];
	  tab[down] = tab[up];
	  tab[up] = y;
	}
    } while (down < up);
  if (up < down) /* up < down => tab[up] = min(tab) */
	{
	  i = down;
	  down = up;
	  up = i;
	  }
  tab[0] = tab[down];
  tab[down] = x;
  return down;
}

int partition_ld(long double tab[], int size)
{
  long double x, y;
  int down, up, i;
  x = tab[0];
  down = 1;
  up = size - 1;
  do
    {
      while (tab[down] < x && down<size-1)
	down++;
      while (tab[up] > x)
	up--;
      if (down < up)
	{
	  y = tab[down];
	  tab[down] = tab[up];
	  tab[up] = y;
	}
      else
	break;
    } while (down < up);
  if (up < down)
	{
	  i = down;
	  down = up;
	  up = i;
	  }
  tab[0] = tab[down];
  tab[down] = x;
  return down;
}

void quicksort(float tab[], int size)
{
  int down;
  down = partition(tab, size);
  if (down < 1) /* if down == 0 then tab[0] = min(tab) ; sort tab[1:] */
    down++;
  if (down > 1)
      quicksort(tab, down);
  if (down < size - 1)
      quicksort(tab + down, size - down);
}

void quicksort_ld(long double tab[], int size)
{
  int down;
  down = partition_ld(tab, size);
  if (down < 1)
    down++;
  if (down > 1)
      quicksort_ld(tab, down);
  if (down < size - 1)
      quicksort_ld(tab + down, size - down);
}


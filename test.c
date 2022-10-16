#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

#define SIZE_TEST 5
	
int main()
{
  float tab[SIZE_TEST];
  int i;
  srand((unsigned int) time(NULL));
  for (i=0; i<SIZE_TEST; i++)
    tab[i] = (float)rand()/(float)(RAND_MAX/10);
  printf("Testing the algorithm : \n UNSORTED_ARRAY = [%f, %f, %f, %f, %f]\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
  quicksort(tab, SIZE_TEST);
  printf(" SORTED_ARRAY = [%f, %f, %f, %f, %f]\n\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
  return 0;
}

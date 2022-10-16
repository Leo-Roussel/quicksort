#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

#define SIZE 20000

float generate(float tab[], int size)
{
  float sum;
  int m;
  int i;
  m = size / 4;
  for (i=0; i<m ; i++)
    {
      tab[4*i] = (float)rand()/(float)(RAND_MAX/1112465223);
      tab[4*i+1] = (float)rand()/(float)(RAND_MAX/5);
      tab[4*i+2] = (float)rand()/(float)(RAND_MAX/5000);
      tab[4*i+3] = (float)rand()/(float)(RAND_MAX/1000000);
      sum += tab[4*i] + tab[4*i+1] + tab[4*i+2] + tab[4*i+3];
    }
  return sum;
}

long double generate_ld(long double tab[], int size)
{
  long double sum;
  int m;
  int i;
  m = size / 4;
  for (i=0; i<m ; i++)
    {
      tab[4*i] = (long double)rand()/(long double)(RAND_MAX/1112465223);
      tab[4*i+1] = (long double)rand()/(long double)(RAND_MAX/5);
      tab[4*i+2] = (long double)rand()/(long double)(RAND_MAX/5000);
      tab[4*i+3] = (long double)rand()/(long double)(RAND_MAX/1000000);
      sum += tab[4*i] + tab[4*i+1] + tab[4*i+2] + tab[4*i+3];
    }
  return sum;
}

float sum_float(float tab[], int size)
{
  float s;
  int i;
  s = 0;
  for (i=0; i<size; i++)
    s += tab[i];
  return s;
}

long double sum_ld(long double tab[], int size)
{
  long double s;
  int i;
  s = 0;
  for (i=0; i<size; i++)
    s += tab[i];
  return s;
}

int main()
{
  float tab_float[SIZE];
  long double tab_ld[SIZE];
  float s_float;
  long double s_ld;
  srand((unsigned int) time(NULL));
  printf("Generating random tables of size %d\n", SIZE);
  s_float = generate(tab_float, SIZE);
  printf("Sum of the unsorted table of floats : s = %f\n", s_float);
  printf("Sorting..\n");
  quicksort(tab_float, SIZE);
  sort_check(tab_float, SIZE);
  s_float = sum_float(tab_float, SIZE);
  printf("Sum of the sorted table of floats : s = %f\n", s_float);
  s_ld = generate_ld(tab_ld, SIZE);
  printf("Sum of the unsorted table of long doubles : s = %Lf\n", s_ld);
  printf("Sorting..\n");
  quicksort_ld(tab_ld, SIZE);
  sort_check_ld(tab_ld, SIZE);
  s_ld = sum_ld(tab_ld, SIZE);
  printf("Sum of the sorted table of long doubles : s = %Lf\n", s_ld);
  printf("\nWhen summing two floating point numbers with differents exponents, \
the computation is made with the bigger exponent, thus truncating the mantissa \
of the smaller number and generating an approximation error. However, this is \
not an issue for summing over sorted tables since the elements added at each \
iteration are of the same magnitude.\n");
  return 0;
}
  

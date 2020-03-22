#include <stdio.h>

int main(void)
{
  FILE* file = NULL;

  int lbaValue = 0;
  int size = 0;

  /*
  printf("start LBA : ");
  scanf("%d", &lbaValue);
  printf("size : ");
  scanf("%d", &size);
  */

  file = fopen("Progress.txt", "r");

  printf("%d \n", fileno(file));

  fclose(file);
  return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  int fileNum = 0;
  ssize_t nread = 0;
  char buf[1024];

  /*
  int lbaValue = 0;
  int size = 0;
  printf("start LBA : ");
  scanf("%d", &lbaValue);
  printf("size : ");
  scanf("%d", &size);
  */

  //file = fopen("Progress.txt", "r");
  fileNum = open("Progress.txt", O_RDONLY);
  nread = read(fileNum, buf, 1024);

  //printf("%d \n", fileno(rFile));
  printf("%d %d\n", fileNum, nread);

  close(fileNum);
  return 0;
}

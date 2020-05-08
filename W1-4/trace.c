#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SECTOR_SIZE 512

int main(void)
{
  int fd = 0;
  char* buf = NULL;
  int fileSize = 0;
  int curSeek = 0;

  fd = open("txt.txt", O_RDONLY | O_DIRECT);

  buf = (char*)malloc(sizeof(char) * SECTOR_SIZE);
  posix_memalign((void**)&buf, SECTOR_SIZE, SECTOR_SIZE);
  fileSize = lseek(fd, 0, SEEK_END);
  lseek(fd, 0 , SEEK_SET);

  while(curSeek < fileSize)
  {
    read(fd, buf, SECTOR_SIZE);
    curSeek = lseek(fd, SECTOR_SIZE, SEEK_SET);
  }

  free(buf);
  close(fd);

  return 0;
}

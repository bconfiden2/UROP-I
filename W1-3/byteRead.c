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
  int fileIdx = 0;
  int prevSeek = 0;
  int curSeek = 0;

  fd = open("TestFile.txt", O_RDONLY | O_DIRECT);
  //buf = (char*)malloc(sizeof(char));
  posix_memalign((void**)&buf, SECTOR_SIZE, 1);
  fileSize = lseek(fd, 0, SEEK_END);
  lseek(fd, 0 , SEEK_SET);

  while(curSeek < fileSize)
  {
    prevSeek = lseek(fd, 0 ,SEEK_CUR);
    read(fd, buf, 1);
    curSeek = lseek(fd, SECTOR_SIZE, SEEK_CUR) - 1;
    printf("byte offset %d ~ %d -> LBA ??? ~ ???\n", prevSeek, curSeek);
  }

  free(buf);
}

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
  buf = (char*)malloc(sizeof(char) * SECTOR_SIZE);
  posix_memalign((void**)&buf, SECTOR_SIZE, SECTOR_SIZE);
  fileSize = lseek(fd, 0, SEEK_END);
  lseek(fd, 0 , SEEK_SET);

  while(curSeek < fileSize)
  {
    prevSeek = lseek(fd, curSeek ,SEEK_SET);
    read(fd, buf, SECTOR_SIZE);
    curSeek = lseek(fd, prevSeek + SECTOR_SIZE, SEEK_SET);
    if(curSeek >= fileSize)
    {
      curSeek = fileSize;
      curSeek++;
    }
    //printf("byte offset %d ~ %d -> LBA ??? ~ ???\n", prevSeek, curSeek - 1);
  }

  free(buf);
  close(fd);
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

#define SECTOR_SIZE 512

int main(void)
{
  int fd = 0;
  char* buf = NULL;
  char* allignBuf = NULL;
  int pos = 0;

  long int startLBA = 0;
  int size = 0;

  fd = open("/dev/sda", O_DIRECT | O_RDONLY);

  printf("start LBA : ");
  scanf("%ld", &startLBA);
  printf("size : ");
  scanf("%d", &size);

  //startLBA = 2048;
  //size = 8;

  buf = (char*)malloc(sizeof(char) * size * SECTOR_SIZE);
  pos = posix_memalign((void**)&buf, SECTOR_SIZE, SECTOR_SIZE * size);

  lseek(fd, startLBA * SECTOR_SIZE, SEEK_SET);
  read(fd, buf, size * SECTOR_SIZE);

  free(buf);
  close(fd);

  return 0;
}

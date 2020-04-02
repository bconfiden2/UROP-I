#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

#define SECTOR_SIZE 512

int main(void)
{
  int fd = 0;
  //FILE* file = NULL;
  //long int devStartLBA = 0;
  //long int devEndLBA = 0;
  //long int devCurLBA = 0;
  char* buf = NULL;
  char* allignBuf = NULL;
  int pos = 0;
  //int i = 0;

  long int startLBA = 0;
  int size = 0;

  fd = open("/dev/sda", O_DIRECT | O_RDONLY);

  //file = fopen("/dev/sda", "r");

  //fseek(file, 0 , SEEK_SET);
  //devStartLBA = ftell(file) / SECTOR_SIZE;
  //fseek(file, 0, SEEK_END);
  //devEndLBA = ftell(file) / SECTOR_SIZE;
  //printf("/dev/sda : %ld ~ %ld\n", devStartLBA, devEndLBA);

  //printf("start LBA : ");
  //scanf("%ld", &startLBA);
  //printf("size : ");
  //scanf("%d", &size);

  startLBA = 2048;
  size = 8;

  buf = (char*)malloc(sizeof(char) * size * SECTOR_SIZE); // 할당
  pos = posix_memalign((void**)&buf, SECTOR_SIZE, SECTOR_SIZE * size);
  //fseek(file, startLBA, SEEK_SET); // 지정 섹터로 이동
  lseek(fd, startLBA * SECTOR_SIZE, SEEK_SET);
  //fread(buf, 1, size * SECTOR_SIZE, file); // 섹터를 size개 읽음
  read(fd, buf, size * SECTOR_SIZE);

  free(buf);

  //fclose(file);
  close(fd);


  return 0;
}

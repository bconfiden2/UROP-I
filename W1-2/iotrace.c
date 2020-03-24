#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

int main(void)
{
  int sdaFD = 0;
  ssize_t nread = 0;
  char buf[1024];

  //입력
  int startLBA = 0;
  int size = 0;
  printf("start LBA : ");
  scanf("%d", &startLBA);
  printf("size : ");
  scanf("%d", &size);



  //처리

  sdaFD = open("/dev/sda", O_RDONLY); // 파일의 fd 번호, sda를 읽기전용으로 열었
  //nread = read(fileNum, buf, 1024); // 파일의 바이트



  //출력
  printf("FD : %d\n", sdaFD);


  close(sdaFD);
  return 0;
}

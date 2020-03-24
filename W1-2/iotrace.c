#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

#define SECTOR_SIZE 512

int main(void)
{
  FILE* file = NULL;
  long int devStartLBA = 0;
  long int devEndLBA = 0;
  long int devCurLBA = 0;
  char* buf = NULL;
  int i = 0;
  //사용자 입력부분
  long int startLBA = 0;
  int size = 0;

  //
  file = fopen("/dev/sda", "r");
  fseek(file, 0 , SEEK_SET);
  devStartLBA = ftell(file) / SECTOR_SIZE;
  fseek(file, 0, SEEK_END);
  devEndLBA = ftell(file) / SECTOR_SIZE;

  printf("/dev/sda : %ld ~ %ld\n", devStartLBA, devEndLBA);


  //입력
  printf("start LBA : ");
  scanf("%ld", &startLBA);
  printf("size : ");
  scanf("%d", &size);


  //처리
  buf = (char*)malloc(sizeof(char) * size); // 내용 저장해줄 공간 생성
  fseek(file, startLBA, SEEK_SET); // 입력한 lba 만큼 이동
  devCurLBA = ftell(file);
  fread(buf, 1, size, file); // 현재 포인터부터 32바이트를 한바이트씩 읽어 buf에 저장


  //출력
  for(i = 0 ; i < size ; i++)
  {
    printf("%c / ", buf[i]);
  }
  printf("\n");


  fclose(file);
  return 0;
}

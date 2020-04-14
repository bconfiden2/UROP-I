#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#define SECTOR_SIZE 512

int main(void)
{
  //%2d %2a %4p  %8S %8n

  FILE* fp_txt = NULL;
  int txtFileSize = 0;
  int curTxtPoint = 0;
  int nextTxtPoint = 0;

  FILE* fp = NULL;
  char buf[31] = {'\0'};
  char lba[9] = {'\0'};

  int curPoint = 0;

  int i = 0;
  int j = 0;

  fp_txt = fopen("txt.txt", "r");
  fseek(fp_txt, 0, SEEK_END);
  txtFileSize = ftell(fp_txt);

  fp = fopen("blkOutput.txt", "r");

  printf("----txt.txt File LBA mapping----\n");
  while(fgets(buf, sizeof(buf), fp))
  {
    if(buf[28] == '1' && buf[4] == 'D')  // read사이즈가 1이고 issued 되었을때의 경우
    {
      for(j = 0 ; j < 8 ; j++)
      {
        lba[j] = buf[12 + j];  // 해당 LBA 주소 가져오기
      }
      if((curPoint + 1) * SECTOR_SIZE < txtFileSize)
      {
        curTxtPoint = curPoint * SECTOR_SIZE;
        nextTxtPoint = curTxtPoint + SECTOR_SIZE - 1;
      }
      else
      {
        nextTxtPoint = txtFileSize;
      }
      printf("byte offset %d ~ %d\t-> LBA %s\n", curTxtPoint, nextTxtPoint,  lba);
      curPoint++;
    }
  }

  fclose(fp_txt);
  fclose(fp);

  //파일 열어서 -> blkOutput.txt
  //줄마다 읽으면서 lba 뽑아내기
  //내가 실행시킨 파일의 pid 에 맞는 파일에서만!
}

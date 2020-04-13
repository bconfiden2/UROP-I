#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct FileStruct
{
  int pid;
  int startLBA;
  int endLBA;
} fileStruct;

typedef struct FileNode
{
  fileStruct file;
  fileStruct* pnext;
} fileNode;

/*
fileStruct* seekWithPid(int pid, fileNode* curFile)
{
  {
    if(*curFile.file.pid == pid)
    {
      return &*curFile.file
    }
    else
    {
      if(*curFile.pnext)
      {
        curFile = *curFile.pnext;
      }
    }
}*/

int main(void)
{
  //%2d %2a %4p  %8S %8n

  char buf[31] = {'\0'};
  FILE* fp = NULL;
  int i = 0;

  fp = fopen("blkOutput.txt", "r");

  while(fgets(buf, sizeof(buf), fp))
  {
    for(i = 0 ; i < sizeof(buf) - 2 ; i++)
    {
      if(buf[i] == '\n') break;
    }
    if(i != sizeof(buf) - 2) break;
    //if(isdigit(buf[28]) && buf[29] == '\n')
    //{
      //for(i = 0 ; i < sizeof(buf) ; i++)
      //{
        //printf("%c", buf[i]);
      //}
    //}
    if(buf[4] != 'C')
    {
      printf("%s", buf);
    }
  }


  fclose(fp);

  //파일 열어서 -> blkOutput.txt
  //줄마다 읽으면서 lba 뽑아내기
  //내가 실행시킨 파일의 pid 에 맞는 파일에서만!
}

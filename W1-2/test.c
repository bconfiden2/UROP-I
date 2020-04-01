#include <stdio.h>
#include <stdlib.h>

#define U8 unsigned char
#define S8 char
#define U16 unsigned short
#define U32 unsigned int
#define U64 unsigned __int64

U32 HDD_read(U8 drv, U32 SecAddr, U32 blocks, U8* buf);
void HexDump(U8* addr, U32 len);

int main(void) {
  U8 dumpData[512];
  HDD_read(0, 0, 1, dumpData);
  HexDump(dumpData, 512);
}

U32 HDD_read(U8 drv, U32 SecAddr, U32 blocks, U8* buf){
  U32 ret;
  U32 ldistanceLow, ldistanceHigh, dwpointer, bytestoread, numread;

  char cur_drv[100];
  HANDLE
}

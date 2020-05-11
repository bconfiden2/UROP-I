# UROP_I
[과제 3]
txtReader 는 txt.txt 파일을 O_DIRECT 로 read 하는 프로그램 입니다.
blktrace 로 /dev/sda 를 읽게 한 후 txtReader 를 실행시켜 txt.txt 파일을 트레이싱 한 후
blkparse 결과물을 blkOutput.txt 에 저장합니다.

blkParser 은 blkOutput.txt 를 분석하여 그 중에서 txtReader 로 read 한 로그만을 뽑아내 매핑된 LBA 를 출력하는 프로그램 입니다.
3-make 사진이 blkParser 실행 결과이고,
3-res 사진은 hdparm 과 stat 을 사용해 실제 매핑되어 있는 주소를 출력한 사진입니다.

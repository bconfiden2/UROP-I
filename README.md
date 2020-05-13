# UROP_I

[과제 1]

sudo blktrace /dev/sda -a complete -a issue -o - | sudo blkparse -f "%M %m %d %a %S %n\n" -i -
![1-1](https://user-images.githubusercontent.com/58922834/81796032-d7905b00-9547-11ea-98a3-ddc273e6b40f.png)

아래는 btt 실행 결과입니다.

![btt](https://user-images.githubusercontent.com/58922834/81796034-d828f180-9547-11ea-9236-1663bb8bb798.png)

아래는 seekwatcher 실행 결과입니다. ![trace](https://user-images.githubusercontent.com/58922834/81796038-d95a1e80-9547-11ea-86a2-9e6b0ad8a675.png)
[과제 2]

iotrace.c 는 LBA 와 size 를 입력받아 /dev/sda 에 read 를 발생시키는 프로그램 입니다.

아래는 2048 에서 8 만큼 read 하게 실행한 사진입니다.
![capture](https://user-images.githubusercontent.com/58922834/81796031-d65f2e00-9547-11ea-87d0-14aa52165f11.png)


[과제 3]

txtReader 는 txt.txt 파일을 O_DIRECT 로 read 하는 프로그램 입니다.
blktrace 로 /dev/sda 를 읽게 한 후 txtReader 를 실행시켜 txt.txt 파일을 트레이싱 한 후
blkparse 결과물을 blkOutput.txt 에 저장합니다.

blkParser 은 blkOutput.txt 를 분석하여 그 중에서 txtReader 로 read 한 로그만을 뽑아내 매핑된 LBA 를 출력하는 프로그램 입니다.
3-make 사진이 blkParser 실행 결과이고,
![3-make](https://user-images.githubusercontent.com/58922834/81793619-98acd600-9544-11ea-8606-feca28af9179.png)

3-res 사진은 hdparm 과 stat 을 사용해 실제 매핑되어 있는 주소를 출력한 사진입니다.
![3-res](https://user-images.githubusercontent.com/58922834/81793627-9b0f3000-9544-11ea-8cf2-46a9796e2316.png)

LBA 27064704 부터 2660바이트, 총 8개 블록에 매핑되어있음을 확인할 수 있습니다.

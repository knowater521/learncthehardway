#ifndef _dbg_h
#define _dbg_h

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M,...)
#else
#define debug(M,...) fprintf(stderr, "DEBUG %s:%d:{%s}"M"\n", __FILE__ ,__LINE__ , __FUNCTION__, ##__VA_ARGS__)     //...代表可变参数
#endif                    //fprintf(stderr,"xxx")专门用于记录错误信息，__FILE__是文件名，__LINE__是代码第几行

#define clean_errno() (errno==0? "None":strerror(errno))

#define log_err(M,...) fprintf(stderr, "[ERROR] (%s:%d:{%s}:errno:%s)" M "\n",__FILE__ , __LINE__ , __FUNCTION__, clean_errno() , ##__VA_ARGS__)

#define log_warn(M,...) fprintf(stderr, "[WARN] (%s:%d:{%s}:errno:%s)" M "\n",__FILE__ , __LINE__ , __FUNCTION__, clean_errno() , ##__VA_ARGS__)

#define log_info(M,...) fprintf(stderr, "[INFO] (%s:%d:{%s})" M "\n",__FILE__ , __LINE__ , __FUNCTION__, ##__VA_ARGS__)

#define check(A,M,...) if(!(A)){log_err(M,##__VA_ARGS__);errno=0;goto error;}

#define sentinel(M,...) {log_err(M,##__VA_ARGS__);errno=0;goto error;}
//sentinel 可以放在函数的任何不应该执行的地方,它会打印错误信息并且跳到 error: 标签
#define check_mem(A) check((A),"Out of memory.")
//check_mem用于确保指针有效
#define check_debug(A,M,...) if(!(A)){debug(M,##__VA_ARGS__);errno=0;goto error;}
//当你定义了 NDEBUG ,它仍然会检查并且发生错误时跳出,但是不会打印消息了
#endif

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef _OFF_T
#define _OFF_T
typedef long int off_t;
#endif

#ifndef _PID_T
#define _PID_T
typedef int pid_t;
#endif

#ifndef _UID_T
#define _UID_T
typedef unsigned int uid_t;
#endif

#ifndef _GID_T
#define _GID_T
typedef unsigned int gid_t;
#endif

#ifdef __cplusplus
}
#endif

#endif
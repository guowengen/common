/*
 * Copyright (C) dirlt
 */

#ifndef __CC_COMMON_LOGGER_INL_H__
#define __CC_COMMON_LOGGER_INL_H__

#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>

#define SERRNO (strerror(errno))
#define SERRNO2(n) (strerror(n))

#define DEBUG(fmt,...) fprintf(stderr,"[DEBUG][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define NOTICE(fmt,...) fprintf(stderr,"[NOTICE][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define TRACE(fmt,...) fprintf(stderr,"[TRACE][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define WARNING(fmt,...) fprintf(stderr,"[WARNING][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__)
#define FATAL(fmt,...) fprintf(stderr,"[FATAL][%s:%d]"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__); abort()

namespace common {

enum log_level_t {
    T_DEBUG,
    T_NOTICE,
    T_TRACE,
    T_WARNING,
    T_FATAL
};

typedef void (*log_cb_t)(log_level_t level, const char* msg);
extern void set_log_level(log_level_t level);
extern void set_log_max_size(size_t size);
extern void set_log_cb(log_cb_t cb);
extern void log(log_level_t level, const char* fmt, va_list ap);

} // namespace common


#endif // __CC_COMMON_LOGGER_INL_H__

//
// Created by zhangmengnan on 2025/11/14.
//

#ifndef CPP_DEV_ZLOGGER_H
#define CPP_DEV_ZLOGGER_H

#include <memory>
#include <string>
#include <spdlog/spdlog.h>
// 代码方式 - 简单直观
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

namespace zmn {
    extern spdlog::logger *g_logger;

    void InitLogger(const std::string &projectname, const std::string &logdir,
                    const int &loglevel, const int &logMaxMB, const int &logCnt);

    void ShutdownLogger();

#define ZLOG_DEBUG(sfmt, args...)                                            \
    ::zmn::g_logger->debug("file={}:{}\t" sfmt, __FILENAME__, __LINE__, \
                              ##args)

#define ZLOG_INFO(sfmt, args...)                                            \
    ::zmn::g_logger->info("file={}:{}\t" sfmt, __FILENAME__, __LINE__, \
                              ##args)

#define ZLOG_WARN(sfmt, args...)                                            \
    ::zmn::g_logger->warn("file={}:{}\t" sfmt, __FILENAME__, __LINE__, \
                              ##args)

#define ZLOG_ERR(sfmt, args...)                                            \
    ::zmn::g_logger->error("file={}:{}\t" sfmt, __FILENAME__, __LINE__, \
                              ##args)

}

#endif //CPP_DEV_ZLOGGER_H

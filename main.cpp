#include <iostream>
#include "src/zlogger/zlogger.h"
#include "conf/flags.h"

using zmn::InitLogger;
using zmn::ShutdownLogger;


int main(int argc, char **argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    InitLogger("cpp-dev", "./", 0, 10, 10);
    ZLOG_INFO("name={}\tage={}", "zhangsan", 12);
    ZLOG_DEBUG("name={}\tage={}", "zhangsan", 12);
    ZLOG_WARN("name={}\tage={}", "zhangsan", 12);
    ZLOG_ERR("name={}\tage={}", "zhangsan", 12);
    std::cout << "server run port:" << FLAGS_port << std::endl;
    ShutdownLogger();
}



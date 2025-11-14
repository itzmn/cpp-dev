//
// Created by zhangmengnan on 2025/11/14.
//

#include "zlogger.h"

namespace zmn {

    spdlog::logger *g_logger;

    void InitLogger(const std::string &projectname, const std::string &logdir,
                    const int &loglevel, const int &logMaxMB, const int &logCnt) {
        spdlog::set_pattern("ts=%L%Y%m%d %H%M%S.%e\tthread=%t\tlogLev=[%l]\t%v");

        switch (loglevel) {
            case 0:
                spdlog::set_level(spdlog::level::debug);
                break;
            case 1:
                spdlog::set_level(spdlog::level::info);
                break;
            case 2:
                spdlog::set_level(spdlog::level::warn);
                break;
            case 3:
                spdlog::set_level(spdlog::level::err);
                break;
        }
        auto logger = spdlog::rotating_logger_mt(projectname,
                                                 logdir + projectname, logMaxMB * 1024 * 1024, logCnt);
        logger->flush_on(spdlog::level::err);
        g_logger = logger.get();
    }

    void ShutdownLogger() {
        g_logger->flush();
        g_logger = nullptr;
        spdlog::drop_all();
    }

    void testLog() {

        auto console = spdlog::stdout_logger_mt("console");
        spdlog::set_pattern("ts=%L%Y%m%d %H%M%S.%e\tthread=%t\tlogLev=[%l]\t%v");
//    spdlog::set_level(spdlog::level::debug);
        console->error("obj={}\tmsg={}", "zmn", "test");

        spdlog::drop_all();
    }


}


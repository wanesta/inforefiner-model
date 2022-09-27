//
// Created by root on 9/26/22.
//

#ifndef INFOREFINER_MODEL_LOG_H
#define INFOREFINER_MODEL_LOG_H

#ifdef logger
#undef logger
#endif

#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/loglevel.h>
#include "Logger.h"

//#define g_log4_logger  log4cplus::Logger::getRoot()
#define g_log4_logger  log4cplus::Logger::getInstance("root")

#define LOG_TRACE(format)     LOG4CPLUS_TRACE(g_log4_logger, format)
#define LOG_DEBUG(format)     LOG4CPLUS_DEBUG(g_log4_logger, format)
#define LOG_INFO(format)      LOG4CPLUS_INFO(g_log4_logger, format)
#define LOG_WARN(format)      LOG4CPLUS_WARN(g_log4_logger, format)
#define LOG_ERROR(format)     LOG4CPLUS_ERROR(g_log4_logger, format)
#define LOG_FATAL(format)     LOG4CPLUS_FATAL(g_log4_logger, format)


inline void log_init(Logger * logger)
{
    std::string log_path = "../config/log4cplus.properties";
    log_path = logger->Read("log_config_path", log_path);
    log4cplus::initialize();
    log4cplus::PropertyConfigurator::doConfigure(log_path);
}


#endif //INFOREFINER_MODEL_LOG_H

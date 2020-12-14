#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>
#include <fstream>
#include <iostream>
#include <cstdarg>

class Logger
{
private:
    /* data */
    const std::string filename = "program.log";
    std::ofstream fs;

    enum level
    {
        INFO,
        WARNING,
        ERROR
    };

public:
    Logger(/* args */);
    ~Logger();

    bool Initialize();

    void Info(std::string message);
    void Error(std::string message);
    void Warning(std::string message);
    void Fatal(std::string message);
    void Debug(std::string message);
};

#endif // __LOGGER_H__
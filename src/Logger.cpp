#include "Logger.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdarg>

bool Logger::Initialize()
{
    fs.open("program.log", std::ofstream::out);
    if (!fs.is_open())
    {
        //    std::cout << "ERROR: Can't open file." << std::endl;
        Error("Log file could not be opened.");
        return false;
    }
    Info("Log file has been successfully opened.");
    return true;
}

void Logger::Info(std::string message)
{
    fs << "INFO: " << message << std::endl;
}

void Logger::Error(std::string message)
{
    fs << "ERROR: " << message << std::endl;
}

void Logger::Warning(std::string message)
{
    fs << "WARNING: " << message << std::endl;
}

void Logger::Fatal(std::string message)
{
    fs << "FATAL: " << message << std::endl;
}

void Logger::Debug(std::string message)
{
    fs << "DEBUG: " << message << std::endl;
}

Logger::Logger(/* args */)
{
    Initialize();
}

Logger::~Logger()
{
    fs.close();
}

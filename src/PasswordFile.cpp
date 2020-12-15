#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include <memory>

#include "PasswordFile.h"
#include "Logger.h"

PasswordFile::PasswordFile(std::shared_ptr<Logger> &logger) : LOGGER(logger)
{
    //LOGGER = logger;
}

PasswordFile::~PasswordFile()
{
}

bool PasswordFile::Open()
{
    LOGGER->Info("Opening the passwd file.");

    fs.open("passwd", std::ifstream::in);
    if (!fs.is_open())
    {
        LOGGER->Error("Passwd file could not be opened opened.");
        return false;
    }
    LOGGER->Info("Passwd file successfully opened.");

    return true;
}

void PasswordFile::LoadEntries()
{
    int numberOfLines = 0;
    std::string line;
    while (std::getline(fs, line))
    {
        //std::istringstream iss(line);
        std::cout << line << std::endl;
        numberOfLines++;
    }

    LOGGER->Info("Loaded 45 entries from the passwd file.");
}

void PasswordFile::ParseFile()
{
}

void PasswordFile::ParseLine()
{
    //std::vector<std::string> strings;
    std::istringstream f("root:!:0:0::/:/usr/bin/ksh");
    std::string s;
    std::getline(f, s, ':');
    logins.push_back(s);

    //while (std::getline(f, s, ':'))
    //{
    //    std::cout << s << std::endl;
    //    strings.push_back(s);
    // }
}

bool PasswordFile::Initialize(const std::string &passwordFileName)
{
    ParseFile();
    if (Open() == false)
    {
        LOGGER->Error("Password file initialization failed.");
        return false;
    }
    LOGGER->Info("Password file initialization successful.");
    return true;
}

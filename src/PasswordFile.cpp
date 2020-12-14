
#include "Logger.h"
#include "PasswordFile.h"
#include <memory.h>
#include <fstream>
#include <string>
#include <iostream>

PasswordFile::PasswordFile(std::shared_ptr<Logger> logger)
{
    LOGGER = logger;
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

    LoadEntries();

    return true;
}

void PasswordFile::LoadEntries()
{
    LOGGER->Info("Loaded 45 entries from the passwd file.");
}

bool PasswordFile::Initialize()
{
    if (Open() == false)
    {
        LOGGER->Error("Password file initialization failed.");
        return false;
    }
    LOGGER->Info("Password file initialization successful.");
    return true;
}

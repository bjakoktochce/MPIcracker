#ifndef __PASSWORDFILE_H__
#define __PASSWORDFILE_H__

#include "Logger.h"
#include <memory>

class PasswordFile
{
private:
    std::shared_ptr<Logger> LOGGER;
    std::ifstream fs;

public:
    PasswordFile(std::shared_ptr<Logger> logger);
    ~PasswordFile();
    bool Open();
    void LoadEntries();

    bool Initialize();
};

#endif // __PASSWORDFILE_H__
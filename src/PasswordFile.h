#ifndef __PASSWORDFILE_H__
#define __PASSWORDFILE_H__

#include "Logger.h"
#include <memory>

#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR -1

struct Entry
{
    std::string login;
    std::string passwordEncrypted;
    std::string passwordDecrypted;
};

class PasswordFile
{
private:
    std::shared_ptr<Logger> LOGGER;
    std::ifstream fs;

    std::vector<Entry> entries;

public:
    PasswordFile(std::shared_ptr<Logger> logger);
    ~PasswordFile();
    bool Open();
    void LoadEntries();
    void ParseFile();
    void ParseLine();

    bool Initialize();
};

#endif // __PASSWORDFILE_H__
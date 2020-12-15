#ifndef __PASSWORDFILE_H__
#define __PASSWORDFILE_H__

#include <memory>
#include <vector>

#include "Logger.h"

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
    std::string passwordFileName;

    std::shared_ptr<Logger> LOGGER;
    std::ifstream fs;

    std::vector<std::string> logins;
    std::vector<Entry> entries;

    bool Open();
    void ParseFile();
    void ParseLine();

public:
    explicit PasswordFile(std::shared_ptr<Logger> &logger);
    ~PasswordFile();

    bool Initialize(const std::string &passwordFileName);
    void LoadEntries();
};

#endif // __PASSWORDFILE_H__
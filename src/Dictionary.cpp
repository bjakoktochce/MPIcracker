#include <memory>

#include "Dictionary.h"
#include "Logger.h"

Dictionary::Dictionary(std::shared_ptr<Logger> logger) : LOGGER(logger)
{
    //LOGGER = logger;
}

Dictionary::~Dictionary()
{
}

bool Dictionary::Initialize()
{
    LOGGER->Info("Initializing dictionary file.");
    return true;
}

void Dictionary::GenerateListOfPasswords()
{
}
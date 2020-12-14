#include "Logger.h"
#include <memory>

#include "Dictionary.h"

Dictionary::Dictionary(std::shared_ptr<Logger> logger)
{
    LOGGER = logger;
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
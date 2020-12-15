#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <vector>

#include "Logger.h"
#include "IObject.h"

class Dictionary
{
private:
    std::shared_ptr<Logger> LOGGER;

    //std::vector<char> smallLetters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    //std::vector<char> hugeLetters {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //std::vector<char> numbers {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    //std::vector<char> specialCharacters {'~', '!', '@', '#'};

public:
    explicit Dictionary(std::shared_ptr<Logger> Logger);
    ~Dictionary();

    bool Initialize();

    std::vector<std::string> listOfPasswords;
    void GenerateListOfPasswords();
};

#endif // __DICTIONARY_H__
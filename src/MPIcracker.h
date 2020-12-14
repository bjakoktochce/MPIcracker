#ifndef __TEST_H__
#define __TEST_H__

#include "Logger.h"

class Test
{
private:
public:
    Test(/* args */);
    ~Test();

    Logger LOGGER;

    Logger initializeLogger();
};

#endif // __TEST_H__
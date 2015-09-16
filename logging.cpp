#include "logging.h"
#include <iostream>

namespace nlpservice
{

void log(const char* msg)
{
    std::cout << msg << std::endl;
}

}
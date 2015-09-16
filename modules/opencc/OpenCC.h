#ifndef _OPENCC_H_
#define _OPENCC_H_

#include <string>
#include "opencc/opencc.h"
#include "../../logging.h"

namespace opencc 
{
    
class OpenCC
{
public: 
    OpenCC()
        :descriptorFan2Jian((opencc_t)-1),
         descriptorJian2Fan((opencc_t)-1)
    {
        descriptorFan2Jian = opencc_open(OPENCC_DEFAULT_CONFIG_TRAD_TO_SIMP);
        descriptorJian2Fan = opencc_open(OPENCC_DEFAULT_CONFIG_SIMP_TO_TRAD);
        if (descriptorFan2Jian == (opencc_t)-1 ||
            descriptorJian2Fan == (opencc_t)-1)
        {
            if (opencc_errno() == OPENCC_ERROR_CONFIG)
                nlpservice::log("opencc configuration error");
        }
    }
    
    ~OpenCC()
    {
        if (descriptorFan2Jian != (opencc_t)-1)
            opencc_close(descriptorFan2Jian);

        if (descriptorJian2Fan != (opencc_t)-1)
            opencc_close(descriptorJian2Fan);
    }
    
    void fan2jian(std::string& result, const std::string& sentence)
    {
        if (descriptorFan2Jian != (opencc_t)-1)
        {
            char* buf = opencc_convert_utf8(descriptorFan2Jian, sentence.c_str(), sentence.length());
            if (buf != NULL)
            {
                result = buf;
                opencc_convert_utf8_free(buf);
            }
        }
    }

    void jian2fan(std::string& result, const std::string& sentence)
    {
        if (descriptorJian2Fan != (opencc_t)-1)
        {
            char* buf = opencc_convert_utf8(descriptorJian2Fan, sentence.c_str(), sentence.length());
            if (buf != NULL)
            {
                result = buf;
                opencc_convert_utf8_free(buf);
            }
        }
    }
    
private:
    opencc_t descriptorFan2Jian;
    opencc_t descriptorJian2Fan;
};
    
    
}

#endif
/**
 * Description : 
 *
 * Author      : 
 * Date        : 
 */

#ifndef NUMB_TO_TEXT
#define NUMB_TO_TEXT

#include <string>

#define MAX_LENTH 5

class NumToText
{
    public:
        static NumToText* getConvertor(std::string lang="english");
        virtual std::string convert(std::string numStr);
};

#endif 

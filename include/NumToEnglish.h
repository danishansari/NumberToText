/**
 * Description : 
 *
 * Author      : 
 * Date        : 
 */

#ifndef NUM_TO_ENGLISH
#define NUM_TO_ENGLISH

#include <vector>

#include "NumToText.h"

class NumToEnglish : public NumToText
{
    std::string getText(std::vector<int> vec);
    public:
        std::string convert(std::string numStr);
};

#endif

/**
 * Description : Base class to provide correct derived class
 *                  interface based in language.
 *
 * Author      : Md Danish Ansari
 * Date        : 2017-03-12
 */

#ifndef NUM_TO_ENGLISH
#define NUM_TO_ENGLISH

#include <vector>

#include "NumToText.h"

/**
 *  @brief Class to convert number to englist text.
 */
class NumToEnglish : public NumToText
{
    /*
     * @brief Function to vector of number to text.
     *
     * @param Vector of number(int).
     *
     * @return Converted String.
     */

    std::string getText(std::vector<int> vec);

    public:

        /*
         * @brief Function to conver number(string) to text.
         *
         * @param String, number to be converted.
         *
         * @return Converted String.
         */
        std::string convert(std::string numStr);
};

#endif

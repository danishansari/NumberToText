/**
 * Description : Base class to provide correct derived class
 *                  interface based in language.
 *
 * Author      : Md Danish Ansari
 * Date        : 2017-03-12
 */

#ifndef NUMB_TO_TEXT
#define NUMB_TO_TEXT

#include <string>

/**
 *  @brief Base class to provide support for multiple languages in future.
 */
class NumToText
{
    public:
        /*
         * @brief Funtion to provide Derived class pointer based on language.
         *
         * @param String, langauge to return corresponding derived class.
         */
        static NumToText* getConvertor(std::string lang="english");

        /*
         * @brief Function to conver number(string) to text.
         *
         * @param String, number to be converted.
         *
         * @return Converted String.
         */
        virtual std::string convert(std::string numStr);
};

#endif 

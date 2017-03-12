/**
 * Description : Source to provide derived class pointer based on language string
 *
 * Author      : Md Danish Ansari
 * Date        : 2017-03-12
 */

#include "NumToText.h"

#include "NumToEnglish.h"

#include <iostream>
#include <algorithm>

using namespace std;

// Function to return derived class pointer, based on language
//  default is english
NumToText* NumToText::getConvertor(string lang)
{
    // transform input string to lover case
    transform(lang.begin(), lang.end(), lang.begin(), ::tolower);

    // english language
    if (lang == "english")
    {
        // return english lang derived class pointer
        return new NumToEnglish();
    }
    else // other language
        cout << "Err: Language '" << lang << "' not supported." << endl;

    return NULL;
}

// Virtual Function to be overriden in the rerived class
// convers number string to corresponding text
string NumToText::convert(string numStr) { 

    return "";     
}

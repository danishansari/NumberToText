/**
 * Description : 
 *
 * Author      : 
 * Date        : 
 */

#include "NumToText.h"

#include "NumToEnglish.h"

#include <iostream>
#include <algorithm>

using namespace std;

NumToText* NumToText::getConvertor(string lang)
{
    transform(lang.begin(), lang.end(), lang.begin(), ::tolower);

    if (lang == "english")
    {
        return new NumToEnglish();
    }
    else
        cout << "Err: Language '" << lang << "' not supported." << endl;

    return NULL;
}

string NumToText::convert(string numStr) { return ""; }

/**
 * Description : 
 *
 * Author      : 
 * Date        : 
 */


#include <iostream>
#include <vector>
#include <sstream>

#include <stdlib.h>
#include <string.h>

#include "NumToText.h"

using namespace std;

int main(int argc, char*argv[])
{
    if (argc < 2)
    {
        cout << "usage: " << endl;
        cout << argv[0] << "-l <language(def=english)>\t e.g. " << argv[0] << " -l english 123" << endl;
        cout << argv[0] << "-r <range(any number)>    \t e.g  " << argv[0] << " -r 99" << endl;
        cout << argv[0] << "1 2 3 4 ...               \t e.g. " << argv[0] << " 1 99 156"<< endl;

        return -1;
    }

    vector<string> numbersVec;

    string lang = "english";

    int range = 0;
    
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-l") == 0)
            lang = argv[++i];
        if (strcmp(argv[i], "-r") == 0)
            range = atoi(argv[++i]);
        else
            numbersVec.push_back(string(argv[i]));
    }

    if (range)
    {
        numbersVec.clear();

        for (int i = 0; i < range; i++)
        {
            stringstream ss;
            ss << i;

            numbersVec.push_back(ss.str());
        }
    }

    NumToText* convertor = NumToText::getConvertor(lang);

    if (convertor)
    {
        for (int i = 0; i < numbersVec.size(); i++)
            cout << numbersVec[i] << ": " << convertor->convert(numbersVec[i]) << endl;
    }
    else
        cout << "could not convert!!" << endl;

    return 0;
}


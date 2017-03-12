/**
 * Description : 
 *
 * Author      : 
 * Date        : 
 */

#include "NumToEnglish.h"

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

string digitStr_g[] = {"zero", "one", "two", "three", "four", "five", "six", 
        "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", 
        "twenty", "", "", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string placeVal_g[] = {"", "", "hundred", "thousand", "thousand", "", "million", "million", 
                       "", "billion", "billion", "", "trillion", "trillion", " ", "quadrillion", 
                       "quadrillion", "", "quintillion", "quintillion", "", "sextillion", "sextillion",
                       "", "septillion", "septillion", "", "octillion", "octillion", "", "nonillion", 
                       "nonillion", "", "decillion", "decillion", "", "undecillion", "undecillion",
                       "", "duodecillion", "duodecillion", "", "tredecillion", "tredecillion", "",
                       "quattuordecillion", "quattuordecillion", "", "quindecillion", "quindecillion", 
                       "", "sexdecillion", "sexdecillion", "", ""};

std::string NumToEnglish::convert(string numStr)
{
    vector<int> digitsVec;

    for (int i = numStr.length()-1; i >=0 ; i--)
    {
        int tmpNum = (int)numStr[i] - 48;
        digitsVec.push_back(tmpNum);
    }

    return getText(digitsVec);
}

std::string NumToEnglish::getText(vector<int> digitsVec)
{
    string text = "";
    
    int i = digitsVec.size()-1;

    bool visited = false;

    if (i == 0 && digitsVec[i] == 0)
        text += digitStr_g[digitsVec[i]];
    else if (i > 33)
        text = "number not supported";
    else
    {
        while (i >= 0)
        {
            if (digitsVec[i])
            {
                switch ((i+1)%3) 
                {
                    case 2: 
                        {
                            if (digitsVec[i] < 2)
                            {
                                text += digitStr_g[digitsVec[i]*10+digitsVec[i-1]] + " " + placeVal_g[i] + " ";
                                i -= 2;
                            }
                            else
                            {
                                if (digitsVec[i] == 2)
                                {
                                    text += digitStr_g[digitsVec[i--]*10] + " ";
                                }
                                else if (digitsVec[i])
                                {
                                    text += digitStr_g[20+digitsVec[i--]] + " ";
                                }

                                if (digitsVec[i])
                                {
                                    text += digitStr_g[digitsVec[i]] + " ";
                                }

                                text +=  placeVal_g[i--] + " ";
                            }

                            break;
                        }
                    case 1:
                    {
                        text += digitStr_g[digitsVec[i--]] + " " + placeVal_g[i] + " ";
                        break;
                    }
                    case 0:
                    {
                        if (i < 3)
                        {
                            text += digitStr_g[digitsVec[i--]] + " " + placeVal_g[i] + " ";
                        }
                        else
                        {
                            text += digitStr_g[digitsVec[i--]] + " " +  placeVal_g[2] + " ";
                        }
                        break;
                    }
                }
            }
            else
            {
                if (!visited && !text.empty() && i > 3)
                {
                    text +=  placeVal_g[i] + " ";
                    visited = true;
                }

                i --;
            }
        }
    }

    return text;
}

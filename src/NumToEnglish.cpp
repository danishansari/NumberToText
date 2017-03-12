/**
 * Description : Source file to convert number to english text
 *
 * Author      : Md Danish ansari
 * Date        : 2017-03-12
 */

#include "NumToEnglish.h"

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

// numbers in string format
string digitStr_g[] = {"zero", "one", "two", "three", "four", "five", "six", 
        "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", 
        "twenty", "", "", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// place value of numbers in string format, upto sexdecillion(10^51)
string placeVal_g[] = {"", "", "hundred", "thousand", "thousand", "", "million", "million", 
                       "", "billion", "billion", "", "trillion", "trillion", " ", "quadrillion", 
                       "quadrillion", "", "quintillion", "quintillion", "", "sextillion", "sextillion",
                       "", "septillion", "septillion", "", "octillion", "octillion", "", "nonillion", 
                       "nonillion", "", "decillion", "decillion", "", "undecillion", "undecillion",
                       "", "duodecillion", "duodecillion", "", "tredecillion", "tredecillion", "",
                       "quattuordecillion", "quattuordecillion", "", "quindecillion", "quindecillion", 
                       "", "sexdecillion", "sexdecillion", "", ""};


// Function to convert string number to text
std::string NumToEnglish::convert(string numStr)
{
    vector<int> digitsVec;

    // parsing each digits, to convert to int
    for (int i = numStr.length()-1; i >=0 ; i--)
    {
        // conversion to int
        int tmpNum = (int)numStr[i] - 48;

        // push into the vector 
        digitsVec.push_back(tmpNum);
    }

    // helper function to convert vector of int to text.
    return getText(digitsVec);
}

// Function to convert vector of ints to text
std::string NumToEnglish::getText(vector<int> digitsVec)
{
    string text = "";
    
    int i = digitsVec.size()-1;

    bool visited = false;

    // if number is zero, convert and return
    if (i == 0 && digitsVec[i] == 0)
        text += digitStr_g[digitsVec[i]];
    else if (i > 51) // if number is too big, not spported
        text = "number not supported";
    else // convert number to text
    {
        // iterate for ech digits
        while (i >= 0)
        {
            if (digitsVec[i]) // if number is non-zero
            { 
                if (!text.empty())
                    text += " ";

                // switch-case to check number position, taking 3 at a time
                switch ((i+1)%3) 
                {
                    case 2: // current number at 2nd position
                    {
                        // in number is less than 2, its already there in the array
                        if (digitsVec[i] < 2)
                        {
                            // get corrsponding text
                            text += digitStr_g[digitsVec[i]*10+digitsVec[i-1]];
                            if (!placeVal_g[i].empty())
                                text += " " + placeVal_g[i];

                            i -= 2;
                        }
                        else // number is bigger, need to construct text
                        {
                            if (digitsVec[i] == 2) // if number is 2, mutiply by 10 coz 
                            {                      // is a two digit number.
                                text += digitStr_g[digitsVec[i--]*10];
                            }
                            else if (digitsVec[i]) // other number, add 20 and get the text from vector
                            {
                                text += digitStr_g[20+digitsVec[i--]];
                            }

                            if (digitsVec[i]) // remaining last digit, if non-zero
                            {
                                // get text from array
                                text += "-" + digitStr_g[digitsVec[i]];
                            }

                            // get the place value from array
                            if (!placeVal_g[i].empty())
                                text +=  " " + placeVal_g[i];

                            i --;
                        }

                        break;
                    }
                    case 1: // number is at 1st position
                    {
                        text += digitStr_g[digitsVec[i]];
                        if (!placeVal_g[i].empty())
                            text += " " + placeVal_g[i];

                        i --;
                        break;
                    }
                    case 0: // one digit number
                    {
                        if (i < 3) // if number is less than 3, get the place
                        {
                            text += digitStr_g[digitsVec[i]];
                            if (!placeVal_g[i].empty())
                                text += " " + placeVal_g[i];

                            i --;
                        }
                        else // number is bigger at that position have place value as hundred
                        {
                            text += digitStr_g[digitsVec[i--]] + " " +  placeVal_g[2];
                        }
                        break;
                    }
                }
            }
            else
            {
                // number having more than one zeros, we will visit here once.
                // e.g. 001, 100, 1000, 10000, 100000
                if (!visited && !text.empty() && i > 3)
                {
                    text +=  " " + placeVal_g[i];
                    visited = true;
                }

                i --;
            }
        }
    }

    // return converted text
    return text;
}

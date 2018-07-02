#include "Decoder.h"

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

void Decoder::DecodeIt(const string & input, json dictionary)
{
    string outputString = "";
    string actualInputString = "";
    for (unsigned int i = 0; i < input.length(); i++)
    {
        actualInputString += input[i];
        auto tempString = dictionary.find(actualInputString);
        if(tempString != dictionary.end())
        {
            outputString += *tempString;
            actualInputString = "";
        }
    }
    if(actualInputString == "")
    {
        cout << "Decoding result: " << outputString << endl;
    }
    else
    {
        cout << "Unavailable to decode" << endl;
    }
}

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
        cout << "Actual decoderstring: " << actualInputString << endl;
        for (json::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
        {
            pair <string, string> pairTemp = *it;
            if(actualInputString == pairTemp.first)
            {
                outputString += pairTemp.second;
                actualInputString = "";
            }
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
    cout << endl;
}

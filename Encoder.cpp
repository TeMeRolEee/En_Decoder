#include "Encoder.h"



Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

void Encoder::EncodeIt(const string& input, json dictionary)
{
    string encodedString = "";
    int badCharacters = 0;
	for (unsigned int i = 0; i < input.length(); i++)
	{
        string actual(1, input[i]);
        if(dictionary.find(actual) == dictionary.end())
        {
            badCharacters++;
        }

	}
    if(badCharacters == 0)
    {
        for (unsigned int i = 0; i < input.length(); i++)
        {
            string actual(1, input[i]);
            if(dictionary.find(actual) != dictionary.end())
            {
                string encodedChar = dictionary[actual];
                encodedString += encodedChar;
                //cout << dictionary[actual.c_str()];
            }
        }
        //cout << endl;
        cout << "Result: " << encodedString << endl;
    }
    else
    {
        cout << "Wrong character in the input, unavailable to encode it!" << endl;
    }
}





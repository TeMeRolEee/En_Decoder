#include "Encoder.h"



Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

void Encoder::EncodeIt(const string& input, json dictionary)
{
    string encodedString;
	for (unsigned int i = 0; i < input.length(); i++)
	{
        string actual(1, input[i]);
        if(dictionary.find(actual) == dictionary.end())
        {
            cout << "Wrong character in the input, unavailable to encode it!" << endl;
            return;
        }
        else
        {
            string encodedChar = dictionary[actual];
            encodedString += encodedChar;
        }


	}
    cout << encodedString << endl;
}





#include "Decoder.h"

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

void Decoder::DecodeIt(const string & input, json dictionary)
{
    for (unsigned int i = 0; i < input.length(); i++)
    {
        string actual(1, input[i]);
        cout << dictionary[actual.c_str()];
    }
    cout << endl;
}

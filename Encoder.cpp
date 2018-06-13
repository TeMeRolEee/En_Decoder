#include "Encoder.h"



Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

void Encoder::EncodeIt(const string& input, json dictionary)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		string actual(1, input[i]);
        if(dictionary[actual.c_str()].is_null() != true)
		cout << dictionary[actual.c_str()];
	}
	cout << endl;
}

void Encoder::DecodeIt(const string & input, json dictionary)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		string actual(1, input[i]);
		cout << dictionary[actual.c_str()];
	}
	cout << endl;
}



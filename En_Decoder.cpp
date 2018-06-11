// En_Decoder.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include "Dictionary.h"
#include "Encoder.h"

using namespace std;

void helper()
{
	cout << "Available commands:" << endl;
	cout << "> ENCODE" << endl;
	cout << "> DECODE" << endl;
	cout << "> ENCODE_FILE" << endl;
	cout << "> DECODE_FILE" << endl;
	cout << "> HELP" << endl;
	cout << "> EXIT" << endl;
}

int menu()
{
    //cout << "Type a command:" << endl;
    int input;
	cin >> input;
    cout << input << endl;
    return input;
}

Encoder encoder(Encoder* encode, Dictionary* dictionary)
{
	//cout << "Encoder fuggveny" << endl;
	string input;
	cin >> input;
	encode->EncodeIt(input, dictionary->getDict());
	return *encode;
}

json swapjson(json dictionary)
{
	json temp;
	for (json::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
		temp.push_back({ it.value(), it.key() });
	}
	return temp;
}

int main()
{
	Dictionary *encode_dictionary = new Dictionary();
	encode_dictionary->setEnDict();
    Dictionary *decode_dictionary = new Dictionary();
    //decode_dictionary->setDeDict(swapjson(encode_dictionary->getDict()));
	Encoder *encode= new Encoder();
	//Decoder *decode=NULL;

	helper();
    int menuswitch = 0;
    while (true)
	{
        menuswitch = menu();
        if(menuswitch == 6)
        {
            break;
        }
		if (menuswitch == 1)
		{
			string input;
			cin >> input;
			encode->EncodeIt(input, encode_dictionary->getDict());

		}
		if (menuswitch == 2)
		{
            string input;
            cin >> input;
            //encode->DecodeIt(input,decode_dictionary);
		}
		if (menuswitch == 3)
		{

		}
		if (menuswitch == 4)
		{

		}
		if (menuswitch == 5)
		{
			helper();
        }
	}
    return 0;
}


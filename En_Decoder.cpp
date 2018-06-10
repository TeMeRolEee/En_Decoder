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
    int input;
    cin >> input;
    cout << input << endl;
    return input;
    while (input != 0)
	{
        switch (input) {
        case 0:
            input = 0;
        case 1:
            string inputString;
            cin >> inputString;
            encode->EncodeIt(inputString, encode_dictionary->getDict());
            break;
        case 2:
            string input;
            cin >> input;
            //encode->DecodeIt(input,decode_dictionary);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            helper();
            break;
        default:
            break;
        }
	}
    return 0;
}


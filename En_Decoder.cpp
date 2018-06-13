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
    cout << ">1 ENCODE" << endl;
    cout << ">2 DECODE" << endl;
    //cout << ">3 ENCODE_FILE" << endl;
    //cout << ">4 DECODE_FILE" << endl;
    cout << ">5 HELP" << endl;
    cout << ">0 EXIT" << endl;
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
    int input = 10;
    string EncodeString;
    string DecodeString;
    while (input != 0)
	{
        cin >> input;
        cout << input << endl;

        switch (input) {
        case 1:
            cin >> EncodeString;
            encode->EncodeIt(EncodeString, encode_dictionary->getDict());
            break;
        case 2:
            cin >> DecodeString;
            //encode->DecodeIt(DecodeString,decode_dictionary);
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


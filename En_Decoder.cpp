// En_Decoder.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>


#include "Dictionary.h"
#include "Encoder.h"
#include "Decoder.h"

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

int main()
{
    string encodePath;
    cout << "Pls give me the path: ";
    cin >> encodePath;
    Dictionary *encode_dictionary = new Dictionary(encodePath);
    Dictionary *decode_dictionary = new Dictionary(encode_dictionary->getDict());
    Encoder *encoder = new Encoder();
    Decoder *decoder = new Decoder();
	//Decoder *decode=NULL;

	helper();
    int input = 10;
    string EncodeString;
    string DecodeString;
    while (input != 0)
	{
        cin >> input;
        switch (input) {
        case 1:
            cin >> EncodeString;
            encoder->EncodeIt(EncodeString, encode_dictionary->getDict());
            break;
        case 2:
            cout << input << endl;
            cin >> DecodeString;
            decoder->DecodeIt(DecodeString,decode_dictionary->getDict());
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


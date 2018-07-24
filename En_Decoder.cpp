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
	qDebug() << "Available commands:" << endl;
    qDebug() << ">1 ENCODE" << endl;
    qDebug() << ">2 DECODE" << endl;
    //qDebug() << ">3 ENCODE_FILE" << endl;
    //qDebug() << ">4 DECODE_FILE" << endl;
    qDebug() << ">5 HELP" << endl;
    qDebug() << ">0 EXIT" << endl;
}

int main()
{
    string encodePath;
    qDebug() << "Pls give me the path: ";
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
            qDebug() << input << endl;
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


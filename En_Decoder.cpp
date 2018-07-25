// En_Decoder.cpp : Defines the entry point for the console application.
//

#include <QtCore>

#include "Dictionary.h"
#include "Encoder.h"
#include "Decoder.h"


void helper()
{
	qDebug() << "Available commands:";
    qDebug() << ">1 ENCODE";
    qDebug() << ">2 DECODE";
    qDebug() << ">5 HELP";
    qDebug() << ">0 EXIT";
}

int main()
{
    QTextStream qtin(stdin);
    QString line = qtin.readLine();
    QString dictionaryPath;
    qDebug() << "Pls give me the path: ";
    qtin >> dictionaryPath;
    Dictionary *encode_dictionary = new Dictionary(dictionaryPath);
    Dictionary *decode_dictionary = new Dictionary(encode_dictionary->getDict());
    Encoder *encoder = new Encoder();
    Decoder *decoder = new Decoder();

	helper();
    int input = 10;
    QString EncodeString;
    QString DecodeString;
    while (input != 0)
	{
        qtin >> input;
        switch (input) {
        case 1:
            qtin >> EncodeString;
                try
                {
                    encoder->EncodeIt(EncodeString, encode_dictionary->getDict());
                }
                catch(QException &exception)
                {
                    qDebug() << exception.what();
                }

            break;
        case 2:
            qDebug() << input;
            qtin >> DecodeString;

                try
                {
                    decoder->DecodeIt(DecodeString,decode_dictionary->getDict());
                }
                catch(QException &exception)
                {
                    qDebug() << exception.what();
                }
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


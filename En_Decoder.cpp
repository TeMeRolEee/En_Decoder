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

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("En_Decoder");
    QCoreApplication::setApplicationVersion("0.8.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Encodes and decodes text via a given dictionary");
    parser.addHelpOption();
    parser.addVersionOption();
    //parser.addPositionalArgument("dictionary", QCoreApplication::translate("main", "The path to the dictionary file."));
    //parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    //parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    //-p  Path to the dictionary
    QCommandLineOption pathToDictionaryOption("p",  QCoreApplication::translate("main", "The path to the dictionary file."));
    parser.addOption(pathToDictionaryOption);

    //-en String to encode
    QCommandLineOption encodeOption("en",  QCoreApplication::translate("main", "The string to be encoded."));
    parser.addOption(encodeOption);

    //-de String to decode
    QCommandLineOption decodeOption("de",  QCoreApplication::translate("main", "The string to be decoded."));
    parser.addOption(decodeOption);

    //-help Helper
    QCommandLineOption helpOption("help",  QCoreApplication::translate("main", "Helper"));
    parser.addOption(helpOption);

    //Parsing the commands given by the user
    parser.process(app);




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


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
    qDebug() << ">0 EXIT";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("En_Decoder");
    QCoreApplication::setApplicationVersion("0.8.0");

    //qDebug() << app.arguments();

    QCommandLineParser parser;
    parser.setApplicationDescription("Encodes and decodes text via a given dictionary");
    parser.addHelpOption();
    parser.addVersionOption();
    //parser.addPositionalArgument("dictionary", QCoreApplication::translate("main", "The path to the dictionary file."));
    //parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    //parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    //-p  Path to the dictionary
    QCommandLineOption pathToDictionaryOption(QStringList() << "p" << "path",  "The path to the dictionary", "path");
    parser.addOption(pathToDictionaryOption);

    //-en String to encode
    QCommandLineOption encodeOption(QStringList() << "e" <<  "encode", "The string to be encoded.", "encode");
    parser.addOption(encodeOption);

    //-de String to decode
    QCommandLineOption decodeOption(QStringList() << "d" <<  "decode", "The string to be decoded.", "decode");
    parser.addOption(decodeOption);

    //-help Helper
    QCommandLineOption helpOption("help", "Helper");
    parser.addOption(helpOption);

    //Parsing the commands given by the user
    parser.process(app);



    QString dictionaryPath = parser.value(pathToDictionaryOption);
    //qDebug() << dictionaryPath;
    if(!parser.isSet(pathToDictionaryOption))
    {
        qDebug() << "No path given. Exiting";
        return 1;
    } else
    {
        dictionaryPath = parser.value(pathToDictionaryOption);
        //qDebug() << "Path:" << dictionaryPath;
    }

    Dictionary *encode_dictionary = new Dictionary(dictionaryPath);
    Dictionary *decode_dictionary = new Dictionary(encode_dictionary->getDict());

    Encoder *encoder = new Encoder();
    Decoder *decoder = new Decoder();

    QString EncodeString;
    QString DecodeString;

    if(parser.isSet(helpOption))
    {
        parser.showHelp();
    }

    if(parser.isSet(encodeOption))
    {
        EncodeString = parser.value(encodeOption);
        try
        {
            encoder->EncodeIt(EncodeString, encode_dictionary->getDict());
        }
        catch(QException &exception)
        {
            qDebug() << exception.what();
        }
    }

    if(parser.isSet(decodeOption))
    {
        DecodeString  = parser.value(decodeOption);
        try
        {
            decoder->DecodeIt(DecodeString,decode_dictionary->getDict());
        }
        catch(QException &exception)
        {
            qDebug() << exception.what();
        }
    }
    return 0;
}


// En_Decoder.cpp : Defines the entry point for the console application.
//

#include <QtCore>

#include "Dictionary.h"
#include "Encoder.h"
#include "Decoder.h"

void writeFile(const QString& input, const QString& path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Couldn't open the file";
    } else
    {
        QTextStream out(&file);
        out << input;
    }
}

QString readFile(const QString& path)
{
    QString readString;
    QFile file("in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return"";
    }


    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        readString.append(line);
    }
}

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("En_Decoder");
	QCoreApplication::setApplicationVersion("0.8.0");

	//qDebug() << app.arguments();

	QCommandLineParser parser;
	parser.setApplicationDescription("Encodes and decodes text via a given dictionary");
	parser.addHelpOption();
	parser.addVersionOption();

	//-p  Path to the dictionary
	parser.addPositionalArgument("dictionary", "The path to the dictionary file.");


	//-en String to encode
	QCommandLineOption encodeOption(QStringList() << "e" << "encode", "The string to be encoded.", "encode");
	parser.addOption(encodeOption);

	//-ens String to encode source path
    QCommandLineOption encodeSourceFileOption(QStringList() << "efs" <<  "encodesource", "Encode source path.", "encodesource");
    parser.addOption(encodeSourceFileOption);

    //-end Encode destination path
    QCommandLineOption encodeDestinationFileOption(QStringList() << "efd" <<  "encodedest", "Encode destination path.", "encodedest");
    parser.addOption(encodeDestinationFileOption);

    //-de String to decode
	QCommandLineOption decodeOption(QStringList() << "d" << "decode", "The string to be decoded.", "decode");
	parser.addOption(decodeOption);

    //-help Helper
    QCommandLineOption helpOption("help", "Helper");
    parser.addOption(helpOption);

	//Parsing the commands given by the user
	parser.process(app);

	const QStringList positionalArgument = parser.positionalArguments();

	QString dictionaryPath;

	if (!positionalArgument.isEmpty()) {
		dictionaryPath = positionalArgument.first();
	} else {
		qDebug() << "No path given. Exiting";
		return 1;
	}

	Dictionary *encode_dictionary = new Dictionary(dictionaryPath);
	Dictionary *decode_dictionary = new Dictionary(encode_dictionary->getDict());

	Encoder *encoder = new Encoder();
	Decoder *decoder = new Decoder();

	QString EncodeString, EncodedString;
	QString DecodeString, DecodedString;


	if(parser.isSet(encodeSourceFileOption) && parser.isSet(encodeDestinationFileOption)) {
        EncodeString = readFile(parser.value(encodeSourceFileOption));
        try {
            EncodedString = encoder->EncodeIt(EncodeString, encode_dictionary->getDict());
            if(EncodedString == "")
            {
                qDebug() << "Wrong character in the input, unavailable to encode it!";
            } else
            {
                qDebug() << EncodedString;
            }
        }
        catch(QException &exception)
        {
            qDebug() << exception.what();
        }
    }

    if(parser.isSet(encodeOption)){
		EncodeString = parser.value(encodeOption);
		try {
			EncodedString = encoder->EncodeIt(EncodeString, encode_dictionary->getDict());
            if(EncodedString == "")
            {
                qDebug() << "Wrong character in the input, unavailable to encode it!";
            } else
            {
                qDebug() << EncodedString;
            }
		}
		catch (QException &exception) {
			qDebug() << exception.what();
		}
        return 0;
	} else if (parser.isSet(decodeOption)) {
		DecodeString = parser.value(decodeOption);
		try {
			DecodedString = decoder->DecodeIt(DecodeString,decode_dictionary->getDict());
            if(DecodedString == "")
            {
                qDebug() << "Unavailable to decode";
            } else
            {
                qDebug() << DecodedString;
            }
		}
		catch (QException &exception) {
			qDebug() << exception.what();
		}
        return 0;
	}

	parser.showHelp();

}


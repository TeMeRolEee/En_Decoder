#include <QtCore>

#include "Dictionary.h"
#include "Encoder.h"
#include "Decoder.h"

QString getFilename(const QString &path, const QString &prefix) {
    QString defaultFileName = QDate::currentDate().toString("yyyy_MM_dd") + "_" +
                              QTime::currentTime().toString("hh_mm_ss") + ".txt";
    if (path.isEmpty()) {
        return QString().append(prefix).append(defaultFileName);
    }

    return path;
}

void writeFile(const QString &input, const QString &path, bool codingMode = false) {

    QString fileName;
    if (!codingMode) {
        fileName = getFilename(path, "./encode_");
    } else {
        fileName = getFilename(path, "./decode_");
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Couldn't open the file";
    } else {
        QTextStream out(&file);
        out << input << endl;
    }
}

QString readFile(const QString &path) {
    QString readString;
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Couldn't open file";
        return QString();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        readString.append(line);
    }
    return readString;
}

void printOutput(const QString &input) {
    qDebug() << input;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("En_Decoder");
    QCoreApplication::setApplicationVersion("0.9.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Encodes and decodes text via a given dictionary");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("dictionary", "The path to the dictionary file.");

    QCommandLineOption FileModeOption(QStringList() << "f" << "filemode",
                                      "Asks for files to read from and write to.");
    parser.addOption(FileModeOption);

    QCommandLineOption encodeOption(QStringList() << "e" << "encode", "The string to be encoded.", "encode");
    parser.addOption(encodeOption);

    QCommandLineOption decodeOption(QStringList() << "d" << "decode", "The string to be decoded.", "decode");
    parser.addOption(decodeOption);

    QCommandLineOption destinationOption(QStringList() << "o" << "outputpath", "Filepath to the processed content.",
                                         "outputpath");
    parser.addOption(destinationOption);

    QCommandLineOption helpOption("help", "Helper");
    parser.addOption(helpOption);

    parser.process(app);

    const QStringList positionalArgument = parser.positionalArguments();

    QString dictionaryPath;

    if (!positionalArgument.isEmpty()) {
        dictionaryPath = positionalArgument.first();
    } else {
        qDebug() << "No path given.";
        parser.showHelp();
    }

    auto encode_dictionary = std::make_unique<Dictionary>(dictionaryPath);
    auto decode_dictionary = std::make_unique<Dictionary>(encode_dictionary->getDict());

    auto encoder = std::make_unique<Encoder>();
    auto decoder = std::make_unique<Decoder>();


    QString EncodeString, EncodedString;
    QString DecodeString, DecodedString;

    QString outputPath = parser.isSet(destinationOption) ? parser.value(destinationOption) : "";

    if (parser.isSet(encodeOption)) {

        QString Input = parser.isSet(FileModeOption) ? readFile(parser.value(encodeOption)) : parser.value(
                encodeOption);

        if (Input.isEmpty()) {
            qDebug() << "Wrong input";
            return 1;
        }

        QString EncodeOutput = encoder->EncodeIt(Input, encode_dictionary->getDict());

        if (EncodeOutput.isEmpty()) {
            qDebug() << "Unable to encode";
            return 1;
        }

        parser.isSet(FileModeOption) ? writeFile(EncodeOutput, outputPath) : printOutput(EncodeOutput);
        return 0;

    } else if (parser.isSet(decodeOption)) {
        QString DecodeInput = parser.isSet(FileModeOption) ? readFile(parser.value(decodeOption)) : parser.value(
                decodeOption);

        if (DecodeInput.isEmpty()) {
            qDebug() << "Wrong input";
            return 1;
        }

        QString DecodeOutput = decoder->DecodeIt(DecodeInput, decode_dictionary->getDict());

        if (DecodeOutput.isEmpty()) {
            qDebug() << "Unable to encode";
            return 1;
        }

        parser.isSet(FileModeOption) ? writeFile(DecodeOutput, outputPath, true) : printOutput(DecodeOutput);
        return 0;
    }

    parser.showHelp();
}
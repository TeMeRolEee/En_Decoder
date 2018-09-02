#include <QtCore>
#include <iostream>

#include "dictionary.h"
#include "encoder.h"
#include "decoder.h"

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
    std::cout << input.toStdString() << std::endl;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("En_Decoder");
    QCoreApplication::setApplicationVersion("0.9.5");

    QCommandLineParser parser;
    parser.setApplicationDescription("Encodes and decodes text via a given dictionary");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("dictionary", "The path to the dictionary file.");

    QCommandLineOption fileModeOption(QStringList() << "f" << "filemode",
                                      "Asks for files to read from and write to.");
    parser.addOption(fileModeOption);

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

    auto dictionary = std::make_unique<Dictionary>(dictionaryPath);


    QString outputPath = parser.isSet(destinationOption) ? parser.value(destinationOption) : "";

    if (parser.isSet(encodeOption)) {
        auto encoder = std::make_unique<Encoder>(dictionary->getDict());

        QString input = parser.isSet(fileModeOption) ? readFile(parser.value(encodeOption)) : parser.value(
                encodeOption);

        if (input.isEmpty()) {
            qDebug() << "Wrong input";
            return 1;
        }

        QString encodeOutput = encoder->encodeInput(input);

        if (encodeOutput.isEmpty()) {
            qDebug() << "Unable to encode";
            return 1;
        }

        parser.isSet(fileModeOption) ? writeFile(encodeOutput, outputPath) : printOutput(encodeOutput);
        return 0;

    } else if (parser.isSet(decodeOption)) {
        auto decoder = std::make_unique<Decoder>(dictionary->swapJson(dictionary->getDict()));

        QString decodeInput = parser.isSet(fileModeOption) ? readFile(parser.value(decodeOption)) : parser.value(
                decodeOption);

        if (decodeInput.isEmpty()) {
            qDebug() << "Wrong input";
            return 1;
        }

        QString decodeOutput = decoder->decodeInput(decodeInput);

        if (decodeOutput.isEmpty()) {
            qDebug() << "Unable to encode";
            return 1;
        }

        parser.isSet(fileModeOption) ? writeFile(decodeOutput, outputPath, true) : printOutput(decodeOutput);
        return 0;
    }

    parser.showHelp();
}
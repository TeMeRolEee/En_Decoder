#include "decoder.h"

Decoder::Decoder(QJsonDocument *inputDictionary) {
    dictionary = inputDictionary;
}

Decoder::~Decoder() {
    delete dictionary;
}

QString Decoder::decodeInput(QString input)
{
    QString outputString;
    QString actualInputString;

    for (const auto &item : input)
    {
        actualInputString = actualInputString.append(item);
        QJsonObject tempObject = dictionary->object();
        QJsonValue tempValue = tempObject.value(actualInputString);

        if(tempValue != QJsonValue::Undefined)
        {
            outputString += tempValue.toString();
            actualInputString.clear();
        }
    }

    if(actualInputString.isEmpty())
    {
        return outputString;
    }

    return QString();
}


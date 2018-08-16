#include "Decoder.h"

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

void Decoder::DecodeIt(QString input, QJsonDocument dictionary)
{
    QString outputString = "";
    QString actualInputString = "";
    for (auto item : input)
    {
        actualInputString = actualInputString.append(item);
        QJsonObject tempObject = dictionary.object();
        QJsonValue tempValue = tempObject.value(actualInputString);
        if(tempValue != QJsonValue::Undefined)
        {
            outputString += tempValue.toString();
            actualInputString = "";
        }
    }
    if(actualInputString == "")
    {
        qDebug() << "Decoding result:" << outputString;
    }
    else
    {
        qDebug() << "Unavailable to decode" << endl;
    }
}

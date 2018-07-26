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
    for (qint32 i = 0; i < input.length(); i++)
    {
        actualInputString = actualInputString.append(input.at(i));
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
        qDebug() << "Decoding result: " << outputString;
    }
    else
    {
        qDebug() << "Unavailable to decode" << endl;
    }
}

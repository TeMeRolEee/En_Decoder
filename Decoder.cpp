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
        //qDebug() << "actualInputString" << actualInputString;
        QJsonObject tempObject = dictionary.object();
        QJsonValue tempValue = tempObject.value(actualInputString);
        //qDebug() << "Current value" << tempValue;
        if(tempValue != QJsonValue::Undefined)
        {
            //qDebug() << "Not undefined";
            outputString += tempValue.toString();
            actualInputString = "";
        } else
        {
            //qDebug() << "Undefined";
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

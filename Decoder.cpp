#include "Decoder.h"

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

QString Decoder::DecodeIt(QString input, QJsonDocument dictionary)
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
        return outputString;
    }
    return "";
}

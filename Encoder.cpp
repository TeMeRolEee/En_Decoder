#include "Encoder.h"

QString Encoder::EncodeIt(QString input, QJsonDocument dictionary)
{
    QString encodedString;
    for (const auto &i : input) {
        QString actual(1, i);
        QJsonObject tempObject = dictionary.object();
        QJsonValue tempValue = tempObject.value(actual);
        if(tempValue == QJsonValue::Undefined)
        {
            return QString();
        }
        else
        {
            encodedString += tempValue.toString();
        }
    }
    return encodedString;
}





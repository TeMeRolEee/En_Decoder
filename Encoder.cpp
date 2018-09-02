#include "Encoder.h"

Encoder::Encoder(QJsonDocument inputDictionary) {
    dictionary = std::move(inputDictionary);
}

QString Encoder::EncodeIt(QString input)
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

Encoder::~Encoder() {

}







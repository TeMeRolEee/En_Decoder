#include "Encoder.h"



Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

void Encoder::EncodeIt(QString input, QJsonDocument dictionary)
{
    QString encodedString;
    for (unsigned int i = 0; i < input.length(); i++)
    {
        QString actual(1, input[i]);
        QJsonObject tempObject = dictionary.object();
        QJsonValue tempValue = tempObject.value(actual);
        if(tempValue == QJsonValue::Undefined)
        {
            qDebug() << "Wrong character in the input, unavailable to encode it!" << endl;
            return;
        }
        else
        {
            encodedString += tempValue.toString();
        }


    }
    qDebug() << "Encoding result:" << encodedString;
}





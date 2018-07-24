#include "Decoder.h"

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

void Decoder::DecodeIt(const QString & input, QJsonDocument *dictionary)
{
    QString outputString = "";
    QJsonValue actualInputString = "";
    for (qint32 i = 0; i < input.length(); i++)
    {


        actualInputString. += input[i];
        auto tempString = dictionary[actualInputString];
        if(tempString != dictionary.end())
        {
            outputString += *tempString;
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

#include "Encoder.h"



Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

void Encoder::EncodeIt(const QString& input, json dictionary)
{
    QString encodedString;
	for (unsigned int i = 0; i < input.length(); i++)
	{
        QString actual(1, input[i]);
        if(dictionary.find(actual) == dictionary.end())
        {
            qDebug() << "Wrong character in the input, unavailable to encode it!" << endl;
            return;
        }
        else
        {
            QString encodedChar = dictionary[actual];
            encodedString += encodedChar;
        }


	}
    qDebug() << encodedString << endl;
}





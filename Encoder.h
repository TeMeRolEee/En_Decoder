#pragma once

#include "Dictionary.h"

class Encoder
{
public:
    Encoder(QJsonDocument inputDictionary);
    ~Encoder();
	QString EncodeIt(QString input);

private:
    QJsonDocument dictionary;
};


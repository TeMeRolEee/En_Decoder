#pragma once

#include "dictionary.h"

class Encoder
{
public:
    Encoder(QJsonDocument inputDictionary);
    ~Encoder();
	QString encodeInput(QString input);

private:
    QJsonDocument dictionary;
};


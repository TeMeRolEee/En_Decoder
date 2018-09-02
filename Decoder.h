#pragma once

#include "Dictionary.h"

class Decoder
{
public:
    Decoder(QJsonDocument *inputDictionary);
    ~Decoder();
    QString DecodeIt(QString input);

private:
    QJsonDocument *dictionary;
};


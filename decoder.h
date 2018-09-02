#pragma once

#include "dictionary.h"

class Decoder {
public:
    Decoder(QJsonDocument *inputDictionary);

    ~Decoder();

    QString decodeInput(QString input);

private:
    QJsonDocument *dictionary;
};


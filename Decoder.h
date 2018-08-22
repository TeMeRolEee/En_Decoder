#pragma once

#include "Dictionary.h"

class Decoder
{
public:
    QString DecodeIt(QString input, QJsonDocument dictionary);
};


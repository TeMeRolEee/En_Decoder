#pragma once

#include "Dictionary.h"

using namespace std;

class Decoder
{
public:
    Decoder();
    ~Decoder();
    QString DecodeIt(QString input, QJsonDocument dictionary);
};


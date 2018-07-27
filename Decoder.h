#pragma once
#include <iostream>
#include <string>


#include "Dictionary.h"

using namespace std;

class Decoder
{
public:
    Decoder();
    ~Decoder();
    QString DecodeIt(QString input, QJsonDocument dictionary);
};


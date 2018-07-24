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
    void DecodeIt(const QString & input, QJsonDocument *dictionary);
};


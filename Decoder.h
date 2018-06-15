#ifndef DECODER_H
#define DECODER_H

#pragma once
#include <string>
#include "json.hpp"
#include <iostream>
#include "Dictionary.h"
using json = nlohmann::json;
using namespace std;

class Decoder
{
public:
    Decoder();
    ~Decoder();
    void DecodeIt(const string & input, json dictionary);
};

#endif // DECODER_H

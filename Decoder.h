#pragma once
#include <iostream>
#include <string>

#include "json.hpp"
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


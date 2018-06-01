#pragma once
#include <string>
#include "json.hpp"
#include <iostream>
#include "Dictionary.h"

using json = nlohmann::json;
using namespace std;
class Encoder
{
private:
	string encoded_str;
	//ostream stream;
public:
	Encoder();
	~Encoder();

	void EncodeIt(const string& input, json dictionary);
	void DecodeIt(const string& input, json dictionary);
	
};


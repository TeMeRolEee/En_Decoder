#pragma once
#include <string>
#include <iostream>

#include "json.hpp"
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
	
};


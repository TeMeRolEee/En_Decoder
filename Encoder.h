#pragma once
#include <string>
#include <iostream>

#include "Dictionary.h"

class Encoder
{
private:
	QString encoded_str;
public:
	Encoder();
	~Encoder();
	void EncodeIt(QString input, QJsonDocument dictionary);
	
};


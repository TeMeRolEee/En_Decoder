#pragma once

#include "Dictionary.h"

class Encoder
{
private:
	QString encoded_str;
public:
	Encoder();
	~Encoder();
	QString EncodeIt(QString input, QJsonDocument dictionary);
	
};


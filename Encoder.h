#pragma once

#include "Dictionary.h"

class Encoder
{
public:
	QString EncodeIt(QString input, QJsonDocument dictionary);
};


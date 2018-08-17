#pragma once
#include <QtCore>

class Dictionary
{
    QJsonDocument *dictionary;
    void swapJson(QJsonDocument inputJson);
public:
    Dictionary(QString path);
    Dictionary(QJsonDocument inputJson);
	~Dictionary();

	QJsonDocument getDict();
};


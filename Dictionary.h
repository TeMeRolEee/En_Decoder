#pragma once
#include <QtCore>

class Dictionary
{
private:
    QJsonDocument *dictionary;
    void swapJson(QJsonDocument inputJson);
public:
    explicit Dictionary(QString path);

    explicit Dictionary(QJsonDocument inputJson);
	~Dictionary();

	QJsonDocument getDict();
};


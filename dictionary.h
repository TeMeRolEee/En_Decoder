#pragma once
#include <QtCore>

class Dictionary
{
public:
    explicit Dictionary(QString path);

    explicit Dictionary(QJsonDocument inputJson);
	~Dictionary();

	QJsonDocument *swapJson(QJsonDocument inputJson);
	QJsonDocument getDict();
private:
    QJsonDocument *jsonDictionary;
};


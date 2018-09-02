#pragma once
#include <QtCore>

class Dictionary
{
private:
    QJsonDocument *dictionary;
public:
    explicit Dictionary(QString path);

    explicit Dictionary(QJsonDocument inputJson);
	~Dictionary();

	QJsonDocument *swapJson(QJsonDocument inputJson);
	QJsonDocument getDict();


};


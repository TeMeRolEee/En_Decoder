#include "Dictionary.h"


Dictionary::Dictionary(QString path)
{
	QFile handle(path);
	if(!handle.open(QFile::ReadOnly)) return;

	QByteArray data = handle.readAll();

	*dictionary = QJsonDocument::fromJson(data);
}

Dictionary::Dictionary(QJsonDocument inputJson)
{
	swapJson(inputJson);
}


Dictionary::~Dictionary() {
}

QJsonDocument Dictionary::getDict()
{
	return *dictionary;
}


void Dictionary::swapJson(QJsonDocument inputJson)
{
	QJsonObject jsonObject = inputJson.object();
	QJsonObject *insertJson = new QJsonObject();

	foreach(const QString& key, jsonObject.keys())
	{
		QJsonValue jsonValue = jsonObject.value(key);
		insertJson->insert(jsonValue.toString(),key);
	}

	dictionary = new QJsonDocument(*insertJson);
}




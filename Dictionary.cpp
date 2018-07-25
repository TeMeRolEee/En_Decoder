#include "Dictionary.h"


Dictionary::Dictionary(QString path)
{
	QFile handle(path);
	if(!handle.open(QFile::ReadOnly)) qDebug() << "Couldn't open file";

	QByteArray data = handle.readAll();
	qDebug() << "file opened";

    try
    {
        dictionary = new QJsonDocument(QJsonDocument::fromJson(data));
    }
    catch (QException &exception)
    {
        qDebug() << exception.what() << " bleeeeee";
    }


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
    qDebug() << "swapped";
    try
    {
        dictionary = new QJsonDocument(*insertJson);
    }
    catch (QException &exception)
    {
        qDebug() << exception.what();
    }

}




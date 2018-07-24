#include "Dictionary.h"


Dictionary::Dictionary(QString path) {
	QFile handle(path);
	if(!handle.open(QFile::ReadOnly)) return;

	QByteArray data = handle.readAll();

	dictionary = QJsonDocument::fromJson(data);

}

Dictionary::Dictionary(QJsonDocument inputJson) {
	swapJson(inputJson);
}


Dictionary::~Dictionary() {
}

QJsonDocument Dictionary::getDict() {
	return dictionary;
}


void Dictionary::swapJson(QJsonDocument inputJson) {
	QJsonDocument tempJson;
//	QJsonDocument tempJson(json::value_t::object);
//	for (json::iterator it = inputJson.begin(); it != inputJson.end(); ++it) {
//		tempJson += json::object_t::value_type(it.value(), it.key());
//	}
	dictionary = tempJson;
}




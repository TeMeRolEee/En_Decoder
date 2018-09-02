#include "dictionary.h"

Dictionary::Dictionary(QString path) {
    QFile handle(path);
    if (!handle.open(QFile::ReadOnly)) qDebug() << "Couldn't open file";

    QByteArray data = handle.readAll();

    try {
        jsonDictionary = new QJsonDocument(QJsonDocument::fromJson(data));
    }
    catch (QException &exception) {
        qDebug() << exception.what();
    }
}

Dictionary::Dictionary(QJsonDocument inputJson) {
    swapJson(inputJson);
}

Dictionary::~Dictionary() {
    delete jsonDictionary;
}

QJsonDocument Dictionary::getDict() {
    return *jsonDictionary;
}

QJsonDocument *Dictionary::swapJson(QJsonDocument inputJson) {
    QJsonObject jsonObject = inputJson.object();
    QJsonObject *insertJson = new QJsonObject();
    for (const auto &key : jsonObject.keys()) {
        QJsonValue jsonValue = jsonObject.value(key);
        insertJson->insert(jsonValue.toString(), key);
    }
    QJsonDocument *qJsonDocument = new QJsonDocument(*insertJson);
    delete insertJson;
    return qJsonDocument;

}

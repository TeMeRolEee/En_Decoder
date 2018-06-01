#pragma once
#include "json.hpp"
#include <string>

using namespace std;

using json = nlohmann::json;
class Dictionary
{
	json dictionary;
public:
	Dictionary();
	~Dictionary();

	void setEnDict();
	json getDict();
	json ReadJson(const string &path);
	bool canbeopened(const string &path);

	void setDeDict(json dictionary);

};


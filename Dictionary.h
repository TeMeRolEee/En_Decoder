#pragma once
#include "json.hpp"
#include <string>

using namespace std;

using json = nlohmann::json;
class Dictionary
{
    json dictionary;

public:
    Dictionary(string path);
    Dictionary(json inputJson);
	~Dictionary();

    json getDict();
    void setDeDict(json inputJson);
    void swapJson(json inputJson);
};


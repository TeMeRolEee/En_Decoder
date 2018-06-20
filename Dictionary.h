#pragma once
#include "json.hpp"
#include <string>

using namespace std;

using json = nlohmann::json;
class Dictionary
{
    json dictionary;
    void swapJson(json inputJson);
public:
    Dictionary(string path);
    Dictionary(json inputJson);
	~Dictionary();

    json getDict();
};


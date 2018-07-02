#include "Dictionary.h"

#include <iostream>
#include <fstream>

Dictionary::Dictionary(string path)
{
    do
    {
        ifstream stream(path);
        if (stream.is_open())
        {
            cout << "Reading..." << endl;
            stream >> dictionary;
            break;
        }
        else
        {
            cout << "Invalid path / or file cannot be opened. Please try again: ";
            std::cin >> path;
        }
    } while (true);
}

Dictionary::Dictionary(json inputJson)
{
    swapJson(inputJson);
}


Dictionary::~Dictionary()
{
}

json Dictionary::getDict()
{
	return dictionary;
}


void Dictionary::swapJson(json inputJson)
{
    json tempJson(json::value_t::object);
    for (json::iterator it = inputJson.begin(); it != inputJson.end(); ++it)
    {
        tempJson += json::object_t::value_type(it.value(), it.key());
    }
    dictionary = tempJson;
}




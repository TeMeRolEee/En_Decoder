#include "Dictionary.h"

#include <iostream>
#include <fstream>

Dictionary::Dictionary()
{
	
}


Dictionary::~Dictionary()
{
}

void Dictionary::setEnDict()
{
	string path;
	cout << "> Give a dictionary path here: ";
	cin >> path;
	do
	{
		if (canbeopened(path) == true)
		{
			cout << "Reading..." << endl;
			dictionary = ReadJson(path);
			break;
		}
		else
		{
			cout << "Invalid path, try again: ";
			cin >> path;
		}

	} while (true);
}

json Dictionary::getDict()
{
	return dictionary;
}

json Dictionary::ReadJson(const string & path)
{
	json JsonTemp;
	ifstream stream(path);
	stream >> JsonTemp;
	return JsonTemp;
}

bool Dictionary::canbeopened(const string &path)
{
	ifstream stream(path.c_str());

	if (stream.is_open()==true)
	{
		cout << "true" << endl;
		return true;
	}
	else
	{
		cout << "false" << endl;
		return false;
	}
}

void Dictionary::setDeDict(json dictionary_)
{
	//dictionary = dictionary_;
}



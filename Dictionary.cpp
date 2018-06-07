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
			cin >> path;
		}

	} while (true);
}

json Dictionary::getDict()
{
	return dictionary;
}

void Dictionary::setDeDict(json dictionary_)
{
    //dictionary = dictionary_;
}



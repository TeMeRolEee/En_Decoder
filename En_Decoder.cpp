// En_Decoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Dictionary.h"
#include "Encoder.h"

using namespace std;

void helper()
{
	cout << "Available commands:" << endl;
	cout << "> ENCODE" << endl;
	cout << "> DECODE" << endl;
	cout << "> ENCODE_FILE" << endl;
	cout << "> DECODE_FILE" << endl;
	cout << "> HELP" << endl;
	cout << "> EXIT" << endl;
}

int menu()
{
	cout << "Type a command:" << endl;
	string input;
	cin >> input;
	cout << input << endl;
	if (input == "ENCODE")
	{
		//cout << "1" << endl;
		return 1;
	}
	else
	if (input == "DECODE")
	{
		//cout << "2" << endl;
		return 2;
	}
	else
	if (input == "ENCODE_FILE")
	{
		//cout << "3" << endl;
		return 3;
	}
	else
	if (input == "DECODE_FILE")
	{
		//cout << "4" << endl;
		return 4;
	}
	else
	if (input == "HELP")
	{
		//cout << "5" << endl;
		return 5;
	}
	else
	if (input == "EXIT")
	{
		return 6;
	}
	/*if (input.compare("ENCODE") == true)
	{
		cout << "1" << endl;
		return 1;
	}
	else
	if (input.compare("DECODE") == true)
	{
		cout << "2" << endl;
		return 2;
	}
	else
	if (input.compare("ENCODE_FILE") == true)
	{
		cout << "3" << endl;
		return 3;
	}
	else
	if (input.compare("DECODE_FILE") == true)
	{
		cout << "4" << endl;
		return 4;
	}
	else
	if (input.compare("HELP") == true)
	{
		cout << "5" << endl;
		return 5;
	}
	else
	if (input.compare("EXIT") == true)
	{
		return 6;
	}*/

}

Encoder encoder(Encoder* encode, Dictionary* dictionary)
{
	//cout << "Encoder fuggveny" << endl;
	string input;
	cin >> input;
	encode->EncodeIt(input, dictionary->getDict());
	return *encode;
}

json swapjson(json dictionary)
{
	json temp;
	for (json::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
		temp.push_back({ it.value(), it.key() });
	}
	return temp;
}

int main()
{
	Dictionary *encode_dictionary = new Dictionary();
	encode_dictionary->setEnDict();
	Dictionary *decode_dictionary = new Dictionary();
	//decode_dictionary->setDeDict(swapjson(encode_dictionary->getDict()));
	Encoder *encode= new Encoder();
	//Decoder *decode=NULL;

	helper();
	int menuswitch = menu();
	while (menuswitch != 6)
	{
		if (menuswitch == 1)
		{
			string input;
			cin >> input;
			encode->EncodeIt(input, encode_dictionary->getDict());

		}
		if (menuswitch == 2)
		{
			//string input;
			//cin >> input;
			//encode->(encode_dictionary->getDict(), encode_dictionary->getDict());
		}
		if (menuswitch == 3)
		{

		}
		if (menuswitch == 4)
		{

		}
		if (menuswitch == 5)
		{
			helper();
		}
		menuswitch = 0;
		menuswitch = menu();
	}
    return 0;
}


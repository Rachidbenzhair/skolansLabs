#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include<list>
using namespace std;

void map_stringInt()
{
	map<string, int> ageof;

	ageof["sami"] = 30;
	ageof["Rachid"] = 40;

	cout << ageof["sami"] << endl;
	cout << ageof["Rachid"] << endl;
	cout << ageof["Raid"] << endl;

	map<string, int>::iterator it;
	for (it = ageof.begin(); it != ageof.end(); it++)
	{
		pair<string, int > p = *it;
		cout << "the age of " << p.first << " is " << p.second << endl;

	}

}

void map_stringString()
{
	map<string, string> info
	{
		{"ID", "1234"},
		{"Name", "Ahmed"},
		{"Age", "22"},
		{"City", "New york"}
	};

	info.insert({ "State", "Sverige" });
	info.erase("age");
	cout << info.at("Name");

	for (map<string, string>::iterator i = info.begin(); i != info.end(); i++)

		cout << i->first << " " << i->second << endl;
}

void map_pair()
{
	map<string, string>login;
	login.insert(pair<string, string>("Student1", "1234"));
	login.insert(pair<string, string>("Student2", "1865"));
	login.insert(pair<string, string>("Student3", "4367"));
	login.insert(pair<string, string>("Student4", "8392"));

	login["Student1"] = "1978";// på detta sättet kan vi lägga till ny key med value i slutet eller ändra password på key Studen1

	login.clear();//tabort alla element som finns

	cout << login.size() << endl; //veta antal elemet i map 


	for (auto pair : login)
		cout << pair.first << "::" << pair.second << endl;

}
void map_List()
{

	// vi har pokemen men de har flera attacks då vi kan använda List namnt på pokemen blir key och attaks blir value

	map < string, list < string>> pokedex;

	list<string> pikachuAttacks{ "thunder shock"," tail whip", "quick attack" };
	list<string> charmanderAttacks{ "flame thrower", "scary face" };
	list<string> chikoritaAttacks{ "razor leaf", "poison powder" };

	pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
	pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
	pokedex.insert(pair<string, list<string>>("Chikorita", chikoritaAttacks));

	for (auto pair : pokedex)
	{
		cout << pair.first << " - ";

		for (auto attack : pair.second)
			cout << attack << ", ";

		cout << endl;
	}
}





//int main()
//{
//	map_List();
//}
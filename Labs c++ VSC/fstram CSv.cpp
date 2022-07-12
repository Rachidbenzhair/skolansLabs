#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Step 1: Write to a .txt file
bool writeRecordToFile(string file_name, string field_one, string field_two, string field_three)
{
	ofstream file;
	file.open(file_name, ios_base::app);	//
	file.open(file_name, ios::trunc); 		// over-write file
	file << field_one << ";" << field_two << ";" << field_three << endl;
	file.close();

	return 0;
}

// Step 2: Read from a .txt file
vector<string> readRecordFromFile(string file_name, string search_term)
{
	vector<string> record;
	ifstream file;
	file.open(file_name);

	bool found_record = false;

	string field_one;
	string field_two;
	string field_three;

	while (getline(file, field_one, ';') && !found_record)
	{
		getline(file, field_two, ';');
		getline(file, field_three, '\n');

		cout << "VEC: " << field_one << endl;
		cout << "VEC: " << field_two << endl;
		cout << "VEC: " << field_three << endl;

		if (field_one == search_term)
		{
			found_record = true;
			record.push_back(field_one);
			record.push_back(field_two);
			record.push_back(field_three);
		}
	}

	file.close();
	return record;
}
//
//int main()
//{
//	// Step 1: Write to a .txt file
//	bool writeToFile = writeRecordToFile("fstream_exempel.txt", "1234", "Ludwig", "1997");
//
//	// Step 2: Read from a .txt file
//	vector<string> Result = readRecordFromFile("fstream_exempel.txt", "1234");
//
//	// Step 3: Print result ...
//	cout << "Result: " << endl << Result[0] << endl << Result[1] << endl << Result[2] << endl;
//
//	return 0;
//}

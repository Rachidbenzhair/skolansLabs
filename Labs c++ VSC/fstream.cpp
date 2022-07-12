#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream;//Read
ofstream; //write
fstream; //Read + write

void ofstream_myfile()
{
	ofstream myfile;
	myfile.open("myfile.txt");
	myfile << "Hello word\n";
	myfile.close();

}
void ifstream_yfile()
{
	ifstream yfile;
	yfile.open("myfile.txt");
	cout << yfile.rdbuf();
	yfile.close();

}

void fstream_mfile()
{

	fstream mfile;
	mfile.open("mfile.txt", ios::app);
	mfile << "this is from fstream" << endl;
	mfile.close();

	mfile.open("mfile.txt");
	cout << mfile.rdbuf();
	mfile.close();

}
void ifstream_rectangle()
{

	int x, y;
	ifstream in("rectangle.txt");
	in >> x >> y;
	in.close();
	cout << 2 * (x + y) << endl;
}

void ifstream_xfile()
{
	char c;
	ifstream xfile("mfile.txt");

	while (!xfile.eof())
	{
		xfile.get(c);
		cout << c;
	}
}


//använda pointer för att skriva till och från filen
void pointer_file()
{
	FILE* minfile;
	char txt;
	char path[] = "C:\\Users\\Rachid\\Downloads\\pointerfile.txt";

	minfile = fopen(path, "a");
	do
	{
		cin.get(txt);
		if (txt != '#')
			putc(txt, minfile);

	} while (txt != '#');
	fclose(minfile);


	minfile = fopen(path, "r");

	while ((txt = getc(minfile)) != EOF)
	{
		cout << txt;
	}
	fclose(minfile);



}


//int main()
//{
//
//
//	return 0;
//
//
//}
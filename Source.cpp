#include <iostream>
#include <fstream>
#include<string>
#include<stdlib.h>
#include <math.h>

using namespace std;   // RASH VERSION

/*task 1(d) and 2 (12/05/2020). Declare two entities, include one in the other, 
make reading and writing to text and binary files.*/

const int string_len = 3;

struct Books {

	string name;
	string genre;
	int pages;
	
};

struct Library {

	float area;
	float age;
	Books book;
};

void libraryShow(const Library lib) {  
	cout << lib.area << "\t"
		<< lib.book.pages << "\t\t["
		<< lib.age << ","
		<< lib.book.name << ","
		<< lib.book.genre << "]" << endl;
}

void librarysShow(const Library sts[], const int lim) { 
	cout << "area \t"
		<< "age \t"
		<< "books,"
		<< endl;

	for (int i = 0; i < lim; i++) {
		libraryShow(sts[i]);
	}

	cout << endl;
}

void stringCreator(string& str, const int lim) {
	static const char alphabet[] =
		"ABCDEFGHIGKLMNOPQRSTUVWXYZ"
		"abcdefghigklmnopqrstuvwxyz"
		"1234567890";

	str.clear();
	str.append(lim, ' ');

	for (int i = 0; i < str.length(); i++) {

		int r = rand() % (sizeof(alphabet) - 1);
		str[i] = alphabet[r];

	}
	str[str.length()] = 0;
}

void definit(Library sts[], const int lim) {
	for (int i = 0; i < lim; i++) {
		
		sts[i].age = rand() % 10;
		sts[i].book.pages = 20 * (float)rand() / RAND_MAX;
		stringCreator(sts[i].book.name, string_len);

		
		stringCreator(sts[i].book.genre, string_len);
		sts[i].book.genre = rand() % 10;
	}
}

void fileWork(const Library sts[], const int l) { 
	ofstream file;

	file.open("result.txt");
	for (int i = 0; i < l; i++)  
		file << sts[i].book.name << " "
		<< sts[i].age << " "
		<< endl;
	file.close();
}

void openfileWork(Library sts[], const int l) { //openTextFile
	ifstream f;

	f.open("result.txt");
	for (int i = 0; i < l; i++)
		f >> sts[i].book.name
		>> sts[i].age
		>> sts[i].book.genre
		>> sts[i].area
		>> sts[i].book.pages;
	f.close();
}

void writeBinFile(Library sts[], const int l) {
	
	fstream f;
	f.open("result.bin.txt", ios::out | ios::binary);
	f.write((char*)sts, sizeof(Library) * l);
	f.close();
}

void binFileWork(Library sts[], const int l) {
	fstream f;
	f.open("result.bin.txt", ios::in | ios::binary);
	f.read((char*)sts, sizeof(Library) * l);
	f.close();
}

int main() {

	cout.precision(3);
	srand(100);

	const int lim = 10;
	Library content[lim];

	cout << "Start massive:\n";
	definit(content, lim);
	fileWork(content, lim);
	librarysShow(content, 5);

	cout << "New:\n";
	definit(content, lim);
	librarysShow(content, 5);

	cout << "Read:\n";
	openfileWork(content, lim);
	librarysShow(content, 5);

	cout << "Bin:\n";
	writeBinFile(content, lim);

	cout << "New massive again:\n";
	definit(content, lim);
	librarysShow(content, 5);

	cout << "Read massive again:\n";
	binFileWork(content, lim);
	librarysShow(content, 5);

	getchar();
	getchar();

	return 0;
}


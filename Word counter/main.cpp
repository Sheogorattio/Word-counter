#include<iostream>
#include<map>
#include"function.h"
using namespace std;

int main() {
	map<string, int> obj;//only string and int. dont change
	string path = "vocab.txt";
	//cout << "Enter path:\t";
	//cin >> path;
	analyseWords(path, obj);
	mapToFile<string, int>(obj);
	auto topVal = wordTop(obj);
	cout << topVal->first << "\t" << topVal->second << endl << endl;
	printMap(obj);
}	
#pragma once
#include <iostream>
#include<map>
#include<fstream>
using namespace std;


void addWord(map<string, int>& obj, const string& key) {
	auto iter = obj.find(key);
	if (iter != obj.end()) {//if key is already exist
		iter->second++;
	}
	else {//if there is no such key
		obj.insert(make_pair(key, 1));
	}
}


void printMap(const map<string, int>& obj) {//contain a word and number of repeats
	auto iter = obj.begin();
	for (; iter != obj.end() /*&& iter->second >=2*/; iter++) {
		cout << "Word:\t" << iter->first << endl << "Count:\t " << iter->second << endl << "-------------------------------------\n";
	}
}


 void analyseWords(string path, map<string, int>& _map) {
	ifstream in(path, ios::in);
	int sum = 0;
	while (!in.eof()) {
		string temp;
		in >> temp;
		addWord(_map, temp);
	}
	in.close();
}

template<class T1, class T2>
int mapToFile(map<T1, T2>& _map) {
	ofstream OUT("result.txt", ios::out | ios::trunc);
	auto iter = _map.begin();
	int sum = 0;
	for (; iter != _map.end() ; iter++) {
		OUT << endl << iter->first << "\t" << iter->second;
		sum += iter->second;
	}
	OUT << endl << "SUM: " << sum;
	OUT.close();
	return sum;
}

map<string, int>::iterator wordTop(map<string, int>& _map) {
	map<string, int>::iterator iter = _map.begin(), temp = _map.begin();
	int frequency = 0;
	for (; iter != _map.end(); iter++) {
		if (iter->second > temp->second) {
			temp = iter;
		}
	}
	return temp;
}

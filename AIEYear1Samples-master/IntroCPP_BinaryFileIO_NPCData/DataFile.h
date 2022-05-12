#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
	int recordCount;
	string fileName; // keep to open and close file at will
	Record currentRecord; //designate the record as this variable and have this as the one that loads

public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);

	int GetRecordCount() { return recordCount; };

	void Save(string filename);
	void Load(string filename);

private:
	void Clear();

};


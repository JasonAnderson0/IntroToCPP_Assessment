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
	Record currentRecord;



public:
	DataFile();
	~DataFile();

	Record* GetRecord();

	int GetRecordCount() { return recordCount; };

	void Load(string filename, int index);

private:
	void Clear();

};


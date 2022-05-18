#include "DataFile.h"
#include <fstream>
#include <iostream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
}


DataFile::Record* DataFile::GetRecord()
{
	//returns directory to current record
	return &currentRecord;
}

void DataFile::Load(string filename, int index)
{
	//opens file for streaming binary data
	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	//loops through all the records in the data file
	for (int i = 0; i <= index; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		//reads the size of the name, age and image
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;
		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		//then if the size is the same as the one at the specified index it will assign
		//the values of that index to the current record variable
		if (i == index) 
		{
			char* imgdata = new char[imageSize];
			infile.read(imgdata, imageSize);

			Image img = LoadImageEx((Color*)imgdata, width, height);
			char* name = new char[nameSize];

			int age = 0;

			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);

			Record* r = &currentRecord;
			r->image = img;
			r->name = string(name, nameSize);
			r->age = age;

			delete[] imgdata;
			delete[] name;
		}
		//else it will skip to reading the next set of sizes and compare them
		else 
		{
			int skipAmount = imageSize + nameSize + ageSize;
			infile.seekg(skipAmount, ios::cur);
		}

	}
	infile.close();
}
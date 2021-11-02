#include <iostream>
#include <fstream>
#include <vector>
#include "SinhVien.hpp"
using namespace std;

#define DATABASE_PATH "data.txt"

void saveDataToFile(vector<SinhVien> sv)
{
	ofstream fileStream;
	fileStream.open(DATABASE_PATH, ios::out | ios::app);
	for (int i = 0; i < sv.size(); i++)
	{
		sv[i].printToFile(fileStream);
		fileStream << endl;
	}
}

void addDataFromFile(string path)
{
	ifstream file(path, ios::in);
	if (file.is_open())
	{
		vector<SinhVien> sv;
		string line;
		while (getline(file, line))
		{
			SinhVien sinhVien;
			sinhVien.fromString(line);
			sv.push_back(sinhVien);
		}

		saveDataToFile(sv);
		cout << "Data added successfully!";
		file.close();
	}
}

void loadDataFromFile(vector<SinhVien> &sv)
{
	ifstream file(DATABASE_PATH, ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			SinhVien newSV;
			newSV.fromString(line, true);
			sv.push_back(newSV);
		}
		
		file.close();
	}
}

void findByKeywords(vector<string> keywords)
{
	vector<SinhVien> sv;
	loadDataFromFile(sv);

	int stt = 1;
	cout << "Founded students:\n";
	cout << sv.size();
	for (int i = 0; i < sv.size(); i++)
	{
		if (sv[i].mssv.find(keywords[0]) != string::npos)
		{
			cout << stt++ << ' ';
			sv[i].print();
			cout << endl;
		}
		else
		{
			for (int j = 0; j < keywords.size(); j++)
			{
				if (sv[i].hoTen.find(keywords[j]) != string::npos)
				{
					cout << stt++ << ' ';
					sv[i].print();
					cout << endl;
				}
			}
		}
	}
}

void passedStudents()
{
	vector<SinhVien> sv;
	loadDataFromFile(sv);

	int stt = 1;
	for (int i = 0; i < sv.size(); i++)
	{
		if (sv[i].dtb >= 5.0)
		{
			cout << stt++ << ' ';
			sv[i].print();
			cout << endl;
		}
	}
}

int main(int argc, char* argv[])
{

	string action = argv[1];
	if (action == "add")
	{
		string path = argv[2];
		addDataFromFile(path);
	}
	else if (action == "find")
	{
		vector<string> keywords;
		for (int i = 0; i < argc - 2; i++)
			keywords.push_back(argv[i + 2]);
		
		findByKeywords(keywords);
	}
	else if (action == "passed")
	{
		passedStudents();
	}
	
	return 0;
}

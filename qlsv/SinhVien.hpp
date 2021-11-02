#ifndef SinhVien_hpp
#define SinhVien_hpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class SinhVien
{
public:
	string mssv, hoTen;
	float toan, van, av, dtb;

	void fromString(string str, bool fromDB = false)
	{
		vector<string> arr;
		string word;
		for (int i = 0; i <= str.length(); i++)
		{
			if (str[i] == ' ' || i == str.length())
			{
				arr.push_back(word);
				word = "";
			}
			else
			{
				word += str[i];
			}
		}

		int k = arr.size();
		if (fromDB)
		{
			dtb = stof(arr[k - 1]);
			av = stof(arr[k - 2]);
			van = stof(arr[k - 3]);
			toan = stof(arr[k - 4]);
			for (int i = 1; i < k - 4; i++)
			{
				hoTen += arr[i];
				hoTen += ' ';
			}
		}
		else
		{
			av = stof(arr[k - 1]);
			van = stof(arr[k - 2]);
			toan = stof(arr[k - 3]);
			dtb = (toan + av + van) / 3.0;
			for (int i = 1; i < k - 3; i++)
			{
				hoTen += arr[i];
				hoTen += ' ';
			}
		}
		mssv = arr[0];
		hoTen = hoTen.substr(0, hoTen.length() - 1);
	}
	
	void printToFile(ofstream& fileStream)
	{
		fileStream << mssv << ' ';
		fileStream << hoTen << ' ';
		fileStream << toan << ' ';
		fileStream << van << ' ';
		fileStream << av << ' ';
		fileStream << dtb;
	}

	void print()
	{
		cout << mssv << ' ';
		cout << hoTen << ' ';
		cout << toan << ' ';
		cout << van << ' ';
		cout << av << ' ';
		cout << dtb;
	}
};

#endif
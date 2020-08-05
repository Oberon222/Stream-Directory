#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<list>
using namespace std;

	struct Firm
	{
		string name; // назва фірми
		string owner; // власник
		string phonNumber;
		string address; // адреса
		string kindOfActivity; // рід діяльності

		Firm()
		{
			string name = " ";
			string owner = " ";
			string phonNumber = " ";
			string address = " ";
			string kindOfActivity = " ";
		}

		Firm(string name, string owner, string phonNumber,string address, string kendOfActivity)
		{
			this->name = name;
			this->owner = owner;
			this->phonNumber = phonNumber;
			this->address = address;
			this->kindOfActivity= kendOfActivity;
		}
	};
class Directory
{
	
	struct Node
	{
		Firm firm;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;
	int size;  

	friend ofstream& operator <<(ofstream& fout, const Directory& dir);
	friend ifstream& operator>>(ifstream& fin, Directory& dir);

public:

	Directory() : head(nullptr), tail(nullptr), size(0) {}

	~Directory()
	{
		while (!IsEmpty())
		{
			DeleteHead();
		}
	}


	bool IsEmpty() const
	{
		return size == 0;
	}

	int GetCount() const
	{
		return size;
	}

	void AddToHead(Firm newFirm);

	void AddToTail(Firm newFirm);

	void DeleteHead();

	void DeleteTail();

	void AddToPosition(Firm newFirm, int pos);

	void DeleteByPosition(int pos);

	void SerchByName(string name )const;

	void SerchByOwner(string owner)const;

	void SerchByPhonNumber(string phonNumber)const;

	void SerchByKindOfActivity(string kindOfActivity)const;

	void ShowDirectory()const;

	void Print(Firm fm)const;

	void Save(Directory& dir)const;

	void Load(Directory& dir);




};

ofstream& operator <<(ofstream& fout, const Directory& dir)
{
	Directory::Node* current = dir.head;
	fout << dir.size << endl;
	for (int i = 0; i < dir.size; i++)
	{
		fout << current->firm.name << endl;
		fout << current->firm.owner << endl;
		fout << current->firm.phonNumber << endl;
		fout << current->firm.address << endl;
		fout << current->firm.kindOfActivity << endl;
		current = current->next;
	}
	return fout;
}

ifstream& operator>>(ifstream& fin, Directory& dir)
{
	int size;
	fin >> size;
	for (int i = 0; i < size; i++)
	{
		Firm buff;
		fin >> buff.name;
		fin >> buff.owner;
		fin >> buff.phonNumber;
		fin >> buff.address;
		fin >> buff.kindOfActivity;
		dir.AddToHead(buff);
	}

	return fin;
}



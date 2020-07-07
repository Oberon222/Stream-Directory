#include<iostream>
#include<string>
#include<fstream>
#include"Directory.h"
using namespace std;

void Directory::AddToHead(Firm newFirm)
{
	Node* newElem = new Node;
		newElem->firm.name = newFirm.name;
		newElem->firm.owner = newFirm.owner;
		newElem->firm.phonNumber = newFirm.phonNumber;
		newElem->firm.address = newFirm.address;
		newElem->firm.kindOfActivity = newFirm.kindOfActivity;
		newElem->next = head;
		newElem->prev = nullptr;
		if (IsEmpty())
		{
			head = tail = newElem;
		}

		else
		{
			head->prev = newElem;
			head = newElem;
		}
		++size;
	
}

void Directory::AddToTail(Firm newFirm)
{
	Node* newElem = new Node;
	newElem->firm.name = newFirm.name;
	newElem->firm.owner = newFirm.owner;
	newElem->firm.phonNumber = newFirm.phonNumber;
	newElem->firm.address = newFirm.address;
	newElem->firm.kindOfActivity = newFirm.kindOfActivity;
	newElem->next = nullptr;
	newElem->prev = tail;

	if (IsEmpty())
	{
		head = tail = newElem;
	}

	else
	{
		tail->next = newElem;
		tail = newElem;
	}
	++size;
}

void Directory::DeleteHead()
{
	if (IsEmpty()) return;

	Node* tmp = head->next;
	delete head;

	if (tmp == nullptr) head = tail = nullptr;
	else
	{
		tmp->prev = nullptr;
		head = tmp;
	}
	--size;
}

void Directory::DeleteTail()
{
	if (IsEmpty()) return;

	if (head->next == nullptr)
	{
		delete head;
		head = tail = nullptr;
	}

	else
	{
		Node* tmp = tail->prev;
		delete tmp->next;
		tmp->next = nullptr;
		tail = tmp;
	}
	--size;
}

void Directory::AddToPosition(Firm newFirm, int pos)
{
	if (pos <= 0 || pos > size + 1) return;

	if (pos == 1)
	{
		AddToHead( newFirm);
		return;
	}
	if (pos == size + 1)
	{
		AddToTail(newFirm);
		return;
	}
	Node* newElem = new Node;
	newElem->firm.name = newFirm.name;
	newElem->firm.owner = newFirm.owner;
	newElem->firm.phonNumber = newFirm.phonNumber;
	newElem->firm.address = newFirm.address;
	newElem->firm.kindOfActivity = newFirm.kindOfActivity;
	Node* current = head;
	for (int i = 0; i < pos - 1; i++)
	{
		current = current->next;
	}
	newElem->prev = current->prev;
	current->prev->next = newElem;

	current->prev = newElem;
	newElem->next = current;
	++size;
}

void Directory::DeleteByPosition(int pos)
{
	if (pos <= 0 || pos > size)return;
	if (pos == 1)
	{
		DeleteHead();
		return;
	}
	if (pos == size)
	{
		DeleteTail();
		return;
		
	}

	Node* current = head;
	for(int i = 0; i < pos - 1; i++)
	{
		current = current->next;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	--size;
}

void Directory::SerchByName(string name) const
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		if (current->firm.name == name)
		{
			Print(current->firm);
		}
	}

}

void Directory::SerchByOwner(string owner) const
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		if(current->firm.owner == owner)
			Print(current->firm);
	}
}

void Directory::SerchByPhonNumber(string phonNumber) const
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		if (current->firm.phonNumber == phonNumber)
			Print(current->firm);
	}

}

void Directory::SerchByKindOfActivity(string kindOfActivity) const
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		if (current->firm.kindOfActivity == kindOfActivity)
			Print(current->firm);
	}
}

void Directory::ShowDirectory() const
{
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << current->firm.name << endl;
		current = current->next;
	}
}


void Directory::Print(Firm fm) const
{
	cout << "Ñompany name: "<<fm.name << endl;
	cout << "Owner: " << fm.owner << endl;
	cout << "Phone number: " << fm.phonNumber << endl;
	cout << "Company address: " << fm.address << endl;
	cout << "The type of activity of the firm: " << fm.kindOfActivity << endl;
}

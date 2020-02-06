#ifndef OperatingSystem_H
#define OperatingSystem_H
#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include "Node.h"

class OperatingSystem
{
private:
	Node *Head, *Rptr, *Sptr;
	bool Compare(string Str_1, string Str_2);
	OperatingSystem& Delete(Node*& Ptr);
	bool IsGreater(string rptr, string ptr);
	Node* Remove();
	
public:
	OperatingSystem();
	OperatingSystem& AddDrive(Node*& Ptr);
	OperatingSystem& AddFile(Node*& Ptr);
	OperatingSystem& AddFolder(Node*& Ptr);
	OperatingSystem& AddUser(Node*& Ptr);
	void ChangeCredentials(string pass, string hint);
	Node* DeleteDrive(Node*& Ptr);
	Node* DeleteFiles(Node*& Ptr);
	Node* DeleteFolder(Node*& Ptr);
	Node* DeleteUser(Node*& Ptr);
	bool Empty();
	Node* FormatDrive(Node*& Ptr);
	bool GetDeleted();
	vector<string> GetDeletedList();
	string GetHint();
	vector<string> GetList();
	string GetName();
	string GetPass();
	int GetType();
	void MoveIn();
	void MoveNext();
	void MoveOut();
	void MovePrev();
	void MoveStart();
	void ReName(string name);
	void TempDelete(bool deleted);
	bool Exist(string name);
	~OperatingSystem();
};

#endif // OperatingSystem_H
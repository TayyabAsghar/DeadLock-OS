#ifndef OperatingSystem_H
#define OperatingSystem_H
#pragma once
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"

class OperatingSystem
{
private:
	Node *Head, *Rptr, *Sptr, *Uptr;                            // To know which user are we on.
	bool Compare(string Str_1, string Str_2);
	OperatingSystem& Delete(Node*& Ptr);
	bool IsGreater(string rptr, string ptr);
	Node* Remove();
	
public:
	bool Administrator();
	OperatingSystem();
	OperatingSystem& AddDrive(Node*& Ptr);
	OperatingSystem& AddFile(Node*& Ptr);
	OperatingSystem& AddFolder(Node*& Ptr);
	OperatingSystem& AddUser(Node*& Ptr);
	void ChangeCredentials(string pass, string hint);
	OperatingSystem& PermanentDelete();
	bool Empty();                                      // To see whether Rptr is Null Or Not
	string FileData();
	OperatingSystem& FormatDrive();
	bool GetDeleted();                                 // To see the Node is Temporarily deleted or Not.
	vector<string> GetDeletedList();                   // To get List of Temporarily deleted Files.
	string GetHint();                                  // To get Hint of Password of Current User.
	vector<string> GetList();
	string GetName();
	string GetPass();                                  // To get Password of Current User.
	int GetType();
	vector<string> GetUserList();                      // Static User List
	int ItemsCount();
	void MoveIn();
	void MoveNext();
	void MoveOut();
	void MovePrev();
	void MoveStart();                             // Move Rptr to Node of current Layer of Data Structure.
	void MoveTop();                               // Move all Pointers to very First Node of Data Structure.
	void ReName(string name);
	void TempDelete();
	bool Exist(string name);
	~OperatingSystem();
};

#endif // OperatingSystem_H
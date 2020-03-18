#ifndef Node_H
#define Node_H
#pragma once
#include <string>

using namespace std;
                                                            // Defining Constexpr
constexpr unsigned _USER = 0;
constexpr unsigned _DRIVE = 1;
constexpr unsigned _FOLDER = 2;
constexpr unsigned _FILE = 3;

class Node
{
private:
	string Name, Password, Hint;
	int Type;                                              // For Identification of Node Type
	bool Del;                                              // To check if We can delete Node
	bool Delete = false;                                   // To check it is deleted or not

public:
	Node *Up, *Down, *Next, *Prev;                         // Pointers to move in all directions
	Node();
	Node(string name, int type, bool del=true);            // Constructor for Drives, Folders, and Files
	Node(string name, string pass, string hint, bool del=true); // Constructor for User
	bool Deleted();
	bool GetDel();
	string GetHint();
	string GetName();
	string GetPass();
	int GetType();
	void SetDel(bool del);
	void SetDeleted(bool deleted);
	void SetHint(string hint);
	void SetName(string name);
	void SetPass(string pass);
	void SetType(int type);
	bool Similar(Node* &Source);
};

#endif // Node_H
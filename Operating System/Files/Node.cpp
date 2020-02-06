#include "Node.h"

Node::Node() : Name(""), Password(""), Hint(""), Type(-1), Del(true)
{
   Up = Down = Next = Prev = NULL;
}

Node::Node(string name, int type, bool del) : Name(name), Password(""), Hint(""), Type(type), Del(del)
{
    Up = Down = Next = Prev = NULL;
}

Node::Node(string name, string pass, string hint, bool del)
{
    Name = name;
    Password = pass;
    Hint = hint;
    Type = _USER;
    Del = del;
    Up = Down = Next = Prev = NULL;
}

bool Node::Deleted()
{
    return Delete;
}

bool Node::GetDel()
{
    return Del;
}

string Node::GetHint()
{
    return Hint;
}

string Node::GetName()
{
    return Name;
}

string Node::GetPass()
{
    return Password;
}

int Node::GetType()
{
    return Type;
}

void Node::SetDel(bool del)
{
    Del = del;
}

void Node::SetDeleted(bool deleted)
{
    Delete = deleted;
}

void Node::SetHint(string hint)
{
    Hint = hint;
}

void Node::SetName(string name)
{
    Name = name;
}

void Node::SetPass(string pass)
{
    Password = pass;
}

void Node::SetType(int type)
{
    Type = type;
}

bool Node::Similar(Node* &Source)
{
    if (Type == Source->Type)
       if (Name == Source->Name)
          if ((Password == Source->Password) && (Hint == Source->Hint))
              return true;

    return false;
}

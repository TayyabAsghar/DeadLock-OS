#include "OperatingSystem.h"

bool OperatingSystem::Compare(string Str_1, string Str_2)
{
	int Size = Str_1.size();

	transform(Str_1.begin(), Str_1.end(), Str_1.begin(), ::tolower);
	transform(Str_2.begin(), Str_2.end(), Str_2.begin(), ::tolower);

	if (Str_1.size() < Str_2.size())                               // Loop Size will be smaller string.
		Size = Str_2.size();

	for (int i = 0; i < Size; ++i)
	{
		if (Str_1[i] != Str_2[i])
			return false;
	}

	return true;
}

OperatingSystem& OperatingSystem::Delete(Node*& Ptr)
{
	Node* sptr = Ptr;
	Node* rptr;
	
	if (Ptr == Head)                                   // If it is use in Destructor.
		rptr = sptr;
	else
		rptr = sptr->Down;

	while (rptr->Next)                                            // Moving Parallel in List.
		rptr = rptr->Next;

	if (rptr->Down)                                              // Moving to Down List
		Delete (rptr->Down);
	else                                                         // Ending Node.
	{
		Node* ptr = rptr;

		if (!(rptr->Prev))                                       // Deleting the Node 
		{
			if (!(rptr->Up))
				delete ptr;
			//else

		}
		else                                                     // Moving Prev
		{
			rptr = rptr->Prev;
			delete ptr;                                          // Deleting the current Node.

			Delete(rptr);
		}
	}

	return *this;
}

bool OperatingSystem::IsGreater(string rptr, string ptr)      // It will fail after 9.
{
	int Size = rptr.size();

	transform(rptr.begin(), rptr.end(), rptr.begin(), ::tolower);
	transform(ptr.begin(), ptr.end(), ptr.begin(), ::tolower);

	if (rptr.size() > ptr.size())
		Size = ptr.size();

	for (int i = 0; i < Size; ++i)                           // Loop will continue until  both are same.
	{
		if (rptr[i] > ptr[i])
			return false;

		if (rptr[i] < ptr[i])
			return true;
	}

	if (rptr.size() < ptr.size())                               // Smaller size won.
		return true;

	return false;
}

Node* OperatingSystem::Remove()
{
	Node* Ptr = Rptr;

	if (Sptr->Down == Rptr)                                      // For First Node.
	{
		Rptr = Rptr->Next;
		Rptr->Up = Sptr;
		Sptr->Down = Rptr;
		Rptr->Prev = Ptr->Next = Ptr->Up = NULL;
	}
	else
	{
		Rptr = Rptr->Prev;

		Rptr->Next = Ptr->Next;

		if (Ptr->Next)                                         // For between the Nodes
		{
			Ptr->Next->Prev = Rptr;
			Ptr->Next = NULL;
		}
		Ptr->Prev = NULL;
	}

	return Ptr;
}

bool OperatingSystem::Administrator()
{
	return Uptr->GetDel();
}

OperatingSystem::OperatingSystem() : Head(NULL), Rptr(NULL), Sptr(NULL), Uptr(NULL)
{}

OperatingSystem& OperatingSystem::AddDrive(Node* &Ptr)
{
	if (!Sptr->Down)
	{
		Ptr->SetName(Ptr->GetName() + " (C:)");
		Rptr = Sptr->Down = Ptr;
		Rptr->Up = Sptr;
		Rptr->Next = Rptr->Prev = NULL;
	}
	else
	{
		char DrivePostfix = 'C';
		string Name;
		int Postfix = 0;

		Rptr = Sptr->Down;

		while (true)     // To find correct PostFix, Loop will be control mostly in DeadLocK.cpp 
		{
			Name = Rptr->GetName();

			if (Name[Name.length() - 3] == DrivePostfix)
				++DrivePostfix;                                    // Search with next Character
			else
				Rptr = Rptr->Prev;

			if(Rptr->Next)                                          // Only move Next if exist
				Rptr = Rptr->Next;
			else
				break;
		}

		Ptr->SetName(Ptr->GetName() + " (" + DrivePostfix + ":)");

		if (Rptr->Next)                                                // Between Nodes
		{
			Ptr->Next = Rptr->Next;
			Ptr->Prev = Rptr;
			Rptr->Next = Rptr->Next->Prev = Ptr;
		}
		else                                                           // Last Node
		{
			Rptr->Next = Ptr;
			Ptr->Prev = Rptr;
		}
		Rptr = Ptr;
		Rptr->Up = NULL;
	}
	Ptr = Ptr->Down = NULL;

	return *this;
}

OperatingSystem& OperatingSystem::AddFile(Node* &Ptr)
{
	if (!Sptr->Down)
	{
		Rptr = Sptr->Down = Ptr;
		Rptr->Up = Sptr;
		Rptr->Next = Rptr->Prev = NULL;
	}
	else
	{
		Rptr = Sptr->Down;

		if ((Rptr->GetType() == _FILE) && IsGreater(Ptr->GetName(), Rptr->GetName()))
		{                                    // Before First Node when all are Files.
			Rptr->Prev = Ptr;
			Ptr->Next = Rptr;
			Sptr->Down = Ptr;
			Ptr->Up = Sptr;
			Ptr->Prev = Rptr->Up = NULL;
		}
		else
		{
			while (Rptr->Next) // Finding right place.If condition good to works as long as GetType is First ||
				if ((Rptr->GetType() == _FOLDER) || IsGreater(Rptr->GetName(), Ptr->GetName()))
					Rptr = Rptr->Next;
				else
					break;

			if (Rptr->Next)
			{
				Ptr->Next = Rptr->Next;
				Ptr->Prev = Rptr;
				Rptr->Next = Rptr->Next->Prev = Ptr;
			}
			else
			{
				Rptr->Next = Ptr;
				Ptr->Prev = Rptr;
				Ptr->Next = NULL;
			}

		}
	}
	Rptr = Ptr;
	Ptr = Ptr->Down = NULL;

	return *this;
}

OperatingSystem& OperatingSystem::AddFolder(Node* &Ptr)
{
	if (!Sptr->Down)
	{
		Rptr = Sptr->Down = Ptr;
		Rptr->Up = Sptr;
		Rptr->Next = Rptr->Prev = NULL;
	}
	else
	{
		Rptr = Sptr->Down;

		if(Rptr->GetType() == _FILE)                               // There is No Folder but Files.
		{
			Rptr->Prev = Ptr;
			Ptr->Next = Rptr;
			Sptr->Down = Ptr;
			Ptr->Up = Sptr;
			Ptr->Prev = Rptr->Up = NULL;
		}
		else
		{
			if (IsGreater(Rptr->GetName(), Ptr->GetName()))
			{
				bool Correct;                                     // Storing data for later use.
				
				while (Correct = IsGreater(Rptr->GetName(), Ptr->GetName()))
					if (Rptr->Next && (Rptr->Next->GetType() == _FOLDER))
							Rptr = Rptr->Next;
					else
						break; 

				if (!Correct)                  // Moving Rptr to Prev Node if IsGreater() is false.
					Rptr = Rptr->Prev;

				if(Rptr->Next)                                               // Between The Nodes.
				{
					Ptr->Next = Rptr->Next;
					Ptr->Prev = Rptr;
					Rptr->Next = Rptr->Next->Prev = Ptr;
				}
				else                                                        // Last Node.
				{
					Rptr->Next = Ptr;
					Ptr->Prev = Rptr;
					Ptr->Next = NULL;
				}
			}
			else                                                            // Before First Node.
			{
				Rptr->Prev = Ptr;
				Ptr->Next = Rptr;
				Sptr->Down = Ptr;
				Ptr->Up = Sptr;
				Ptr->Prev = Rptr->Up = NULL;
			}
		}
	}
	Rptr = Ptr;
	Ptr = Ptr->Down = NULL;

	return *this;
}

OperatingSystem& OperatingSystem::AddUser(Node*& Ptr)
{
	if (!Head)
	{
		Ptr->SetName(Ptr->GetName() + " (AD)");             // To show it is Admin Account
		Rptr = Head = Ptr;
		Rptr->Next = Rptr->Prev = NULL;
	}
	else
	{
		Sptr = Head;                                         // Start from Head

		while (Sptr->Next)                                   // Move up to last User 
			Sptr = Sptr->Next;

		Rptr = Sptr->Next = Ptr;

		Rptr->Prev = Sptr;
	}
	Rptr->Down = Rptr->Up = NULL;
	Uptr = Sptr = Rptr;                                           // Both Pointing to Last User
	Ptr = NULL;

	return *this;
}

void OperatingSystem::ChangeCredentials(string pass, string hint)
{
	Uptr->SetPass(pass);
	Uptr->SetHint(hint);
}

OperatingSystem& OperatingSystem::PermanentDelete()
{
	Node* Ptr = Remove();

	Delete(Ptr);

	return *this;
}

bool OperatingSystem::Empty()
{
	if (Rptr)
		return false;

	return true;
}

string OperatingSystem::FileData()
{
	return string();
}

OperatingSystem& OperatingSystem::FormatDrive()
{
	if (Rptr->Down)
	{
		Node* Ptr;

		Rptr = Rptr->Down;

		while (Rptr)
		{
			Ptr = Remove();
			Delete(Ptr);
		}
	}

	return *this;
}

bool OperatingSystem::GetDeleted()
{
	return Rptr->Deleted();
}

vector<string> OperatingSystem::GetDeletedList()                          // HAHAHAHAHAHA
{
	Node* rptr = Sptr;
	vector<string> DeletedList;
	
	while (rptr->Next)
		rptr = rptr->Next;

	while (rptr->Prev)
	{
		if (rptr->Deleted())
			DeletedList.push_back(rptr->GetName());
		else if (Sptr->Down)
			rptr = Sptr->Down;

	}
	
	return DeletedList;
}

string OperatingSystem::GetHint()
{
	return Uptr->GetHint();
}

vector<string> OperatingSystem::GetList()
{
	vector<string> Name;
	Node* rptr;
	size_t Count = 0;

	Name.clear();                                              // Clearing if there is any garbage value

	if (!(Rptr))                                               // If Rptr is Empty.
		return Name;

	if (Rptr->GetType() == _USER)
		rptr = Head;
	else
		rptr = Sptr->Down;

	while (rptr)
	{
		if (!rptr->Deleted())                                 // Don't push if it is deleted temporarily.
		{
			if (rptr == Rptr)
				Name.push_back("--> " + rptr->GetName() + " <--");
			else
				Name.push_back(rptr->GetName());
			++Count;
		}
		rptr = rptr->Next;
	}

	if (Count)
		Name.push_back(to_string(Count));

	return Name;
}

string OperatingSystem::GetName()
{
	if (Rptr)
		return Rptr->GetName();
	return "";
}

string OperatingSystem::GetPass()
{
	return Uptr->GetPass();
}

int OperatingSystem::GetType()
{
	if (Rptr)
		return Rptr->GetType();
	return -1;
}

vector<string> OperatingSystem::GetUserList()
{
	Node* rptr = Head;
	vector<string> Name;
	int Count = 0;

	while (rptr)
	{
		Name.push_back(rptr->GetName());
		rptr = rptr->Next;
		++Count;
	}

	if (Count)
		Name.push_back(to_string(Count));

	return Name;
}

int OperatingSystem::ItemsCount()
{
	int Count = 0;
	Node* rptr = Sptr->Down;

	while (rptr)
	{
		rptr = rptr->Next; 
		++Count;
	}

	return Count;
}

void OperatingSystem::MoveIn()
{
	if (Rptr)
	{
		Sptr = Rptr;
		Rptr = Rptr->Down;
	}
}

void OperatingSystem::MoveNext()
{
	while (Rptr->Next)                            // While Node Exist.
	{
		Rptr = Rptr->Next;

		if (!Rptr->Deleted())                     // If it is not Deleted break the loop.
			break;
	}

	if (Rptr->GetType() == _USER)                  // If we are switching user then set Sptr to last Rptr.
		Uptr = Sptr = Rptr;
}

void OperatingSystem::MoveOut()
{
	Rptr = Sptr;

	while (Sptr->Prev)
		Sptr = Sptr->Prev;

	if (Sptr->Up)
		Sptr = Sptr->Up;
}

void OperatingSystem::MovePrev()
{
	while (Rptr->Prev)                            // While Node Exist.
	{
		Rptr = Rptr->Prev;

		if (!Rptr->Deleted())                     // If it is not Deleted break the loop.
			break;
	}

	if (Rptr->GetType() == _USER)                  // If we are switching user then set Sptr to last Rptr.
		Uptr = Sptr = Rptr;
}

void OperatingSystem::MoveStart()
{
	if (Rptr->GetType() == _USER)                   // To Move Rptr on drives when comes from user.
		Rptr = Rptr->Down;

	while (Rptr->Prev)
		Rptr = Rptr->Prev;
}

void OperatingSystem::MoveTop()
{
	Rptr = Sptr = Uptr = Head;
}

void OperatingSystem::ReName(string name)
{
	if (Rptr->GetType() == _DRIVE)
	{ 
		string Drive = Rptr->GetName();

		Drive.erase(0, (Drive.length()-5));                             // Saving [ (C:)]

		Rptr->SetName(name + Drive);
	}
	else
	{
		Node* Ptr;

		Rptr->SetName(name);

		if (!((Sptr->Down == Rptr) && (!Rptr->Next)))               // If there is more than one nodes.
		{
			Ptr = Remove();

			if (Ptr->GetType() == _FILE)
				AddFile(Ptr);
			else
				AddFolder(Ptr);
		}
	}
}

void OperatingSystem::TempDelete()
{
	if ((Rptr->GetType() == _FILE) || (Rptr->GetType() == _FOLDER))
	{
		Rptr->SetDeleted(true);

		if (Rptr->Next)                                 // Moving pointer away from deleted Node.
			MoveNext();
		else if (Rptr->Prev)
			MovePrev();
		else
			Rptr = NULL;
	}
}

bool OperatingSystem::Exist(string name)
{
	Node* rptr;

	if (!(Rptr))                                               // If Rptr is Empty.
		return false;

	if (Rptr->GetType() == _USER)
		rptr = Head;
	else
		rptr = Sptr->Down;

	while (rptr)
	{
		if(!rptr->Deleted())
			if (Compare(rptr->GetName(), name))
				return true;

		rptr = rptr->Next;
	}
	return false;
}

OperatingSystem::~OperatingSystem()
{
	Delete(Head);
}
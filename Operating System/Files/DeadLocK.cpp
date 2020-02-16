#include <ctime>
#include <iomanip>
#include <iostream>
#include <Shlwapi.h>
#include <stdlib.h>                         // system("");
#include <windows.h>                        // sleep(), VK's
#include "ConsoleKeysInput.h"
#include "OperatingSystem.h"

using namespace std;

constexpr auto CPANEL = " | Control Panel | ";
constexpr auto DriveControls = " >> | Drives Controls |";
constexpr auto UserControls = " >> | Users Controls |";
constexpr auto DLK = R"(
				.-----------.      |''|            |''|   /''/
				'  .-----.  |      |  |            |  |  /  /
				'  '      |  |     |  |            |  | /  /
				'  '      |  |     |  |            |  |/  /
				'  '      |  |     |  |            |  |\  \
				'  '      |  |     |  |            |  | \  \
				'  '-----'  |      |  '-------.    |  |  \  \
				'-----------'      '----------'    |..|   \..\ )";

void Desktop(OperatingSystem& OS);
bool InvalidChar(string& Str);
void NewDrive(OperatingSystem& OS);
void NewFile(OperatingSystem& OS);
void NewFolder(OperatingSystem& OS);
void NewUser(OperatingSystem& OS);
void StartingWindow();
void Trim(string& Str);
void UserSelection(OperatingSystem& OS);

int main()
{
	OperatingSystem DeadLocK;

	NewUser(DeadLocK);

	//do                                                   // Start and Restart Loop;
	//{
	//	StartingWindow();
	//	
	//	do                                              // User Selection Loop;
	//	{
	//		UserSelection(DeadLocK);
			Desktop(DeadLocK);

	//	} while (true);

	//} while (true);
			

	   return 0;
}

void Desktop(OperatingSystem& OS)
{
	void ThisPC(OperatingSystem & OS);
	void RecycleBin(OperatingSystem& OS);
	void ControlPanel(OperatingSystem& OS);
	void Time();

	int Action = -1;
	const size_t SIZE = 4;                        // Icons string array Size;
	string PC    = "\n\n\n     --> This PC <--\n\n\n    Recycle Bin \n\n\n    Control Panel \n\n\n    Clock ";
	string Bin   = "\n\n\n    This PC \n\n\n     --> Recycle Bin <--\n\n\n    Control Panel \n\n\n    Clock ";
	string CP    = "\n\n\n    This PC \n\n\n    Recycle Bin \n\n\n     --> Control Panel <--\n\n\n    Clock ";
	string Clock = "\n\n\n    This PC \n\n\n    Recycle Bin \n\n\n    Control Panel \n\n\n     --> Clock <--";
	string Icons[SIZE] = {PC, Bin, CP, Clock};
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	size_t Icon = 0;

	while (!(Action == EXIT))                                    // Desktop Loop
	{
		while (!((Action == ENTER) || (Action == EXIT)))
		{
			cout << Icons[Icon] << NewLines;

			Action = KeysInput();                                 // Take Input From Keys

			switch (Action)
			{
			case DOWN:
				if (Icon < (SIZE - 1))
					++Icon;
				break;

			case EXIT:
			   //Exit:
				break;

			case ENTER:                                         // To break through the loop.
				break;

			case UP:
				if (Icon > 0)
					--Icon;
			}
			system("CLS");
		}
		                                                         // Icons Selection
		if (Action == ENTER)
		{
			Action = -1;                                         // Clearing Action

			switch (Icon)
			{
			case 0:
				ThisPC(OS);
				break;

			case 1:
				RecycleBin(OS);
				break;

			case 2:
				ControlPanel(OS);
				break;

			case 3:
			{
				for (int i = 0; i < 60; ++i)                         // Clock Effect
				{
					Time();
					Sleep(100);
					system("CLS");
				}
			}
			}
		}
		system("CLS");
	}
}

bool InvalidChar(string& Str)
{
	bool CompRun = true;

	for (unsigned i = 0; i < Str.length(); ++i)
	{
		if (!((Str[i] == '\\') || (Str[i] == '/') || (Str[i] == ':')))
		{
			if (!((Str[i] == '*') || (Str[i] == '?') || (Str[i] == '"')))
			{
				if (!((Str[i] == '<') || (Str[i] == '>') || (Str[i] == '|')))
				{
					continue;
				}
				else
				{
					CompRun = false;
					break;
				}
			}
			else
			{
				CompRun = false;
				break;
			}
		}
		else
		{
			CompRun = false;
			break;
		}
	}

	if (CompRun)
		return false;

	return true;
}

void NewDrive(OperatingSystem& OS)
{
	void DriveCredentials(string& name, OperatingSystem& OS);

	string Name;
	Node* Ptr;

	if (OS.ItemsCount() < 7)                              // Manage how many Drives we can add.
	{
		DriveCredentials(Name, OS);

		if (!Name.empty())
		{
			Ptr = new Node(Name, _DRIVE);
			OS.AddDrive(Ptr);
		}
	}
	else
		cout << " Drives Partition Exceeding it's Limit.";
}

void NewFile(OperatingSystem& OS)
{
	string FileType();

	string Name = FileType();
	Node* Ptr;

	if (Name.empty())                                        // If user press APPS then it will be empty.
		return;

	if (OS.Empty())
		Ptr = new Node("New " + Name, _FILE);
	else
	{
		string name = "New " + Name;
		size_t Pos = Name.rfind(".");
		string Extention = Name.substr(Pos, (Name.size() - 1));
		int i = 2;

		Name = Name.substr(0, Pos);                            // Breaking file Name into two parts.

		while (OS.Exist(name))
		{
			name = "New " + Name + " (" + to_string(i) + ")" + Extention;
			++i;
		}
		Ptr = new Node(name, _FILE);
	}
	OS.AddFolder(Ptr);
}

void NewFolder(OperatingSystem& OS)
{
	string Name = "New Folder";
	Node* Ptr;

	if (OS.Empty())
		Ptr = new Node(Name, _FOLDER);
	else
	{
		string name = Name;
		int i = 2;

		while (OS.Exist(name))
		{
			name = Name + " (" + to_string(i) + ")";
			++i;
		}
		Ptr = new Node(name, _FOLDER);
	}
	OS.AddFolder(Ptr);
}

void NewUser(OperatingSystem& OS)
{
	void UserCredentials(string & name, string & pass, string & hint, OperatingSystem & OS);

	string Name = "Admin", Password = "0000", Hint = "0000";
	bool Del = false;                                        // Set Del to false so we can't remove Admin
	Node* Ptr;

	if (!OS.Empty())                                          // To make a Non-Admin users
	{
		UserCredentials(Name, Password, Hint, OS);             // Taking User data

		Del = true;
	}

	if (!Name.empty())
	{
		Ptr = new Node(Name, Password, Hint, Del);
		OS.AddUser(Ptr);

		for (int i = 0; i < 2; ++i)                             // Pre Install Drives for each User
		{
			Ptr = new Node("Local Drive", _DRIVE, false);        // Set Del to false so we can't delete Derives (Accidentally)
			OS.AddDrive(Ptr);
		}
	}
}

void ReName(OperatingSystem& OS)
{
	string NewName;
	string OldName = OS.GetName();
	string Extention = "";
	bool Clear;

	if (OS.GetType() == _FILE)
	{
		size_t Pos = OldName.find_last_of(".");
		Extention = OldName.substr(Pos, (OldName.size() - 1));
		OldName = OldName.substr(0, Pos);
	}

	system("CLS");

	do
	{
		Clear = true;

		cout << "\n\t\t\t\t\t\t      Rename \n\n";
		cout << "\n\n\t\t\t\t\t\t " << OldName << "\n\n\t\t\t\t\t\t> ";
		getline(cin, NewName);

		Trim(NewName);

		if (NewName.empty())
		{
			cout << "\n\n\n\n\t\t\t\t\t\t  Name is Empty ";
			Clear = false;
		}

		if (InvalidChar(NewName))
		{
			cout << "\n\n\n\n\t\t\t\t\t Name contains Invalid Characters. (\\/*?\"<>|) ";
			Clear = false;
		}

		if (OS.Exist(NewName))
		{
			if (OS.GetType() == _FILE)
				cout << "\n\n\n\n\t\t This destination already contains a File named '" << OS.GetName() << "'";
			else
				cout << "\n\n\n\n\t\t This destination already contains a Folder named '" << NewName << "'";
			Clear = false;
		}
		Sleep(1000);
		system("CLS");

	} while (!(Clear));

	OS.ReName(NewName + Extention);                        // Extension will only non-Empty if it is a File.
}

void StartingWindow()                                       // Loading Screen
{
	string LoadingBar[9];
	string NewLines = "\n\n\n\n\n\n\n\n\n\n";

	LoadingBar[0] = "[      D e a d     L o c K      ]  00%";
	LoadingBar[1] = "[--    D e a d     L o c K    --]  12%";
	LoadingBar[2] = "[----  D e a d     L o c K  ----]  25%";
	LoadingBar[3] = "[------D e a d     L o c K------]  37%";
	LoadingBar[4] = "[      D e a d     L o c K      ]  50%";
	LoadingBar[5] = "[--    D e a d     L o c K    --]  62%";
	LoadingBar[6] = "[----  D e a d     L o c K  ----]  75%";
	LoadingBar[7] = "[------D e a d     L o c K------]  87%";
	LoadingBar[8] = "[------D e a d-----L o c K------] 100%";

	cout << NewLines << DLK << NewLines << "\n";

	Sleep(700);
	system("CLS");

	for (int i = 0; i < 9; ++i)
	{
		Sleep(300);
		system("CLS");
		cout << NewLines << "\n\n\n\n";
		cout << setw(78) << LoadingBar[i];
		cout << NewLines << "\n\n\n\n\n";
	}

	Sleep(1000);
	system("CLS");
}

void Trim(string& Str)
{
	int Lenght = Str.find_first_not_of(" \t");

	Str.erase(0, Lenght);

	Lenght = Str.find_last_not_of(" \t");

	if (string::npos != Lenght)
		Str.erase(Lenght + 1);
}

void UserSelection(OperatingSystem& OS)
{
	void LogInWindow(OperatingSystem & OS);
	
	string Account = "   ---Select an Account---";
	int Action = -1;
	size_t Size;
	vector<string> Name;
	string NewLines = "\n\n\n\n\n\n\n";
	string Tabs = "\t\t\t\t\t";

	OS.MoveTop();

	while (!((Action == ENTER) || (Action == EXIT)))
	{
		Name = OS.GetList();
		Size = Name.size() - 1;

		cout << Tabs << Account << NewLines;

		for (size_t i = 0; i < Size; ++i)
			cout << Tabs << "\t" << Name[i] << "\n\n";

		for (size_t i = 0; i < (10 - Size); ++i)
			cout << "\n\n";

		cout << "\t" << Name[Size] << " Items    1 Item selected \n";

		Action = KeysInput();                                 // Take Input From Keys

		switch (Action)
		{
		case DOWN:
			OS.MoveNext();
			break;

		case EXIT:
			//TODO:
			break;

		case ENTER:
			if (!(OS.GetPass().empty()))                // If Password Exist
			   LogInWindow(OS);
			break;

		case UP:
			OS.MovePrev();
		}
		system("CLS");
	}
}

							/*****************************
							  ***** Local Functions *****
							 *****************************/

void Apps(OperatingSystem& OS)
{
	void ReName(OperatingSystem& OS);

	int Action = -1;
	int op = -1;
	const size_t SIZE = 7;                        // Option array Size.
	size_t loop;
	string NewLines = "\n\n\n    ";
	string Tabs = "\t\t\t\t\t";
	string Options[SIZE] = { "Open", "Add Folder", "Add File", "Rename", "Format", "Delete", "Refresh"};


	system("CLS");

	while (Action != EXIT)                                    // Desktop Loop
	{
		while (!((Action == ENTER) || (Action == APPS)))
		{
			loop = 0;

			if (OS.GetList().empty())
				cout << "\n" << Tabs << " Empty Folder \n\n";
			else
				cout << "\n" << Tabs << "> " << OS.GetName() << "\n\n";

			while (loop < SIZE)
			{
				if (OS.GetType() == _DRIVE)              // To show selected options on Drive
					while (true)
						if ((loop == 0) || (loop == 3) || (loop == 4) || (loop == 6))
							break;
						else
							++loop;
				else if(OS.GetList().empty())            // To show selected options on Empty Folder
					while (true)
						if ((loop == 1) || (loop == 2) || (loop == 6))
							break;
						else
							++loop;
				else                                 // To show selected options
					while (true)
						if (loop != 4)
							break;
						else
							++loop;

				if (loop == op)
					cout << NewLines << "  -> " << Options[loop] << " <-";
				else
					cout << NewLines << Options[loop];
				++loop;
			}

			cout << "\n\n\n\n\n\n\n\n";

			Action = KeysInput();                                 // Take Input From Keys

			switch (Action)
			{
			case APPS:
				break;

			case DOWN:
			{
				if (op < static_cast<int> (SIZE - 1))
				{
					++op;

					if (OS.GetType() == _DRIVE)              // To show selected options on Drive
						while (true)
							if ((op == 0) || (op == 3) || (op == 4) || (op == 6))
								break;
							else
								++op;
					else if (OS.GetList().empty())           // To show selected options on Empty Folder
						while (true)
							if ((op == 1) || (op == 2) || (op == 6))
								break;
							else
								++op;
					else                                 // To show selected options
						while (true)
							if (op != 4)
								break;
							else
								++op;
				}
			}
			break; 

			case ENTER:                                         // To break through the loop.
				break;

			case UP:
			{
				if (op > 0)
				{
					--op;

					if (OS.GetType() == _DRIVE)              // To show selected options on Drive
						while (true)
							if ((op == 0) || (op == 3) || (op == 4) || (op == 6))
								break;
							else
								--op;
					else if (OS.GetList().empty())           // To show selected options on Empty Folder
						while (true)
							if ((op == 1) || (op == 2) || (op == 6))
								break;
							else if (op == 0)              // To stop getting it out of bound
								++op;
							else
								--op;
					else                                   // To show selected options
						while (true)
							if (op != 4)
								break;
							else
								--op;
				}
			}
			}
			system("CLS");
		}

		if (Action == ENTER)
			switch (op)		                                     // Options Selection
			{
			case 0:
				OS.MoveIn();
				break;

			case 1:
				NewFolder(OS);
				break;

			case 2:
				NewFile(OS);
				break;

			case 3:
				ReName(OS);
				break;

			case 4:
				//Format();
				break;

			case 5:
				if (OS.GetType() != _DRIVE)
					OS.TempDelete();
				break;

			case 6:
				system("CLS");
				Sleep(20);
			}
		Action = EXIT;                                     // Clearing Action.
		system("CLS");
	}
}

void ChangeCredential(OperatingSystem& OS)
{
	string NewLines = "\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t\t\t\t";
	string Pass;
	string Hint;
	string Credentials = " >> | Change Credentials |";

	cout << CPANEL << UserControls << Credentials << NewLines << Tabs << "Type New Password : ";
	getline(cin, Pass);

	system("CLS");

	cout << CPANEL << UserControls << Credentials << NewLines << Tabs 
		 << "Type New Password : " << Pass << "\n\n" << Tabs << "Type Password Hint : ";
	getline(cin, Hint);

	system("CLS");

	cout << CPANEL << UserControls << Credentials << NewLines << Tabs << "Type New Password : " << Pass
		 << "\n\n" << Tabs << "Type Password Hint : " << Hint << NewLines << "\n\n\n" << Tabs 
		 << " User Credentials Updated \n\n\n\n";

	OS.ChangeCredentials(Pass, Hint);

	Sleep(600);
	system("CLS");
}

void ControlPanel(OperatingSystem& OS)
{
	void DrivesControls(OperatingSystem& OS);
	void UsersControls(OperatingSystem& OS);

	int Action = -1;
	int op = 0;
	const size_t SIZE = 2;
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t";
	string Controls[SIZE] = { "Users Controls", "Drives Controls" };

	while (Action != BACK)
	{
		cout << CPANEL << "\n\n\n\n";

		for (size_t i = 0; i < SIZE; ++i)
			if (op == i)
				cout << Tabs << "  --> " << Controls[i] << " <--\n\n\n";
			else
				cout << Tabs << Controls[i] << "\n\n\n";

		cout << NewLines << "\t" << SIZE << " Items    1 Item selected \n";

		Action = KeysInput();                                 // Take Input From Keys

		switch (Action)
		{
		case BACK:
			break;

		case DOWN:
			if (op < (SIZE - 1))
				++op;
			break;

		case ENTER:
			system("CLS");

			switch (op)
			{
			case 0:
				UsersControls(OS);
				break;

			case 1:
				DrivesControls(OS);
			}
			break;

		case UP:
			if (op > 0)
				--op;
		}
		system("CLS");
	}
}

void DeleteDrive(OperatingSystem& OS)        // TODO: there is an error in Presentation
{
	int Action = -1;
	size_t op = 0;
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t";
	vector<string> Name;
	string Del = " >> | Delete Partition |";
	size_t Size;

												   //Moving to start then skipping [(C):] and [(D):] Drive.
	OS.MoveStart();
	OS.MoveNext();
	OS.MoveNext();

	while (Action != BACK)
	{
		Name = OS.GetList();
	    Size = Name.size() - 3;                                   // Adjusting the Size for format.

		cout << CPANEL << DriveControls << Del << "\n\n\n\n";

		for (size_t i = 0; i < Size; ++i)
			cout << Tabs << Name[i+2] << "\n\n\n";               // Not Printing the [C] and [D] Drives
		if (Size != 0)
		{
			for (size_t i = 0; i < (24 - (Size * 3)); ++i)
				cout << "\n";

			cout << "\t" << OS.ItemsCount() - 2 << " Items    1 Item selected \n";
		}
		else
		{
			cout << "\n\n\n\n" << Tabs << "There are No user Created Partitions to Delete.\n";
			cout << Tabs << "You can't Delete [(C):] and [(D):] Partition but you can Format them.";

			for (size_t i = 0; i < 19; ++i)
				cout << "\n";

			cout << "\t0 Items    0 Item selected \n";
		}

		Action = KeysInput();

		switch (Action)
		{
		case DOWN:
			if (op < Size)
			{
				OS.MoveNext();
				++op;
			}
			break;

		case DEL:
		case ENTER:
			if(Size != 0)
			{
				system("CLS");

				cout << CPANEL << DriveControls << Del;
				cout << NewLines << Tabs << "Partition Deleted and All Data with it..."
					 << NewLines << "\n\n\n\n";

				Sleep(600);
				OS.PermanentDelete();
			}
			break;

		case UP:
			if (op > 1)
			{
				OS.MovePrev();
				--op;
			}
		}
		system("CLS");
	}
}

void DrivesControls(OperatingSystem& OS)
{
	void DeleteDrive(OperatingSystem& OS);
	void ViewDrives(OperatingSystem& OS);
	void Format(OperatingSystem& OS);

	int Action = -1;
	int op = 0;
	const size_t SIZE = 4;
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t";
	string Controls[SIZE] = {"View Partitions", "Add New Partition", "Delete Partition", "Format Partition"};

	while (Action != BACK)
	{
		cout << CPANEL << DriveControls << "\n\n\n\n";

		for (size_t i = 0; i < SIZE; ++i)
			if (op == i)
				cout << Tabs << "  --> " << Controls[i] << " <--\n\n\n";
			else
				cout << Tabs << Controls[i] << "\n\n\n";

		cout << NewLines << "\t" << SIZE << " Items    1 Item selected \n";

		Action = KeysInput();                                 // Take Input From Keys

		switch (Action)
		{
		case BACK:
			break;

		case DOWN:
			if (op < (SIZE - 1))
				++op;
			break;

		case ENTER:
			system("CLS");

			switch (op)
			{
			case 0:
				ViewDrives(OS);
				break;

			case 1:
				NewDrive(OS);
				break;

			case 2:
				DeleteDrive(OS);
				break;

			case 3:
				Format(OS);
				break;
			}
			break;

		case UP:
			if (op > 0)
				--op;
		}
		system("CLS");
	}
}

void DriveCredentials(string& name, OperatingSystem& OS)
{
	string Report = "";
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t\t\t\t";
	string Drive = " | New Partition |";
	string Account = "---Adding New Drive---";

	cout << CPANEL << DriveControls << Drive << "\n\n";
	cout << Tabs << Account << NewLines;
	cout << Tabs << " Type Drive Name : ";
	getline(cin, name);
	Sleep(400);
	system("CLS");

	Trim(name);
	                                                          // Final View With Report
	cout << CPANEL << DriveControls << Drive << "\n\n";
	cout << Tabs << Account << NewLines;
	cout << Tabs << " Type Drive Name : " << name << "\n\n\n";
	cout << NewLines;

	if (name.empty())                                        // Test to check Empty String.
		Report = " Drive Can't be Added. (Name Is Empty)";

	if (InvalidChar(name))                                   // Test to check Invalid Characters.
	{
		name = "";                                           // As a sign that action was not completed;
		Report = " Name contains Invalid Characters. (\\/*?\"<>|)";
	}

	if (Report.empty())                                       // If none of above Conditions fulfilled.
		Report = " Drive Added. (Go to This PC of Current User)";

	cout << Tabs << Report << "\n\n";

	Sleep(2000);
	system("CLS");
}

string FileType()
{
	int Action = -1;
	size_t File = 0;
	const size_t SIZE = 6;                     // Files Array size.
	string Access = "Microsoft Access Database";
	string Word = "Microsoft Word Document";
	string Point = "Microsoft PowerPoint Presentation";
	string Publisher = "Microsoft Publisher Document";
	string Text = "Text Document";
	string Excel = "Microsoft Excel Worksheet";
	string Files[SIZE] = {Access, Word, Point, Publisher, Text, Excel};

	while (!((Action == ENTER) || (Action == APPS)))
	{
		cout << "\n\t\t\t\t\t New " << Files[File] << "\n";

		for (int i = 0; i < SIZE; ++i)
			if (i == File)
				cout << "\n\n\n       --> " << Files[i] << " <--";
			else
				cout << "\n\n\n     " << Files[i];
		cout << "\n\n\n\n\n\n\n\n\n";

		Action = KeysInput();                                 // Take Input From Keys

		switch (Action)
		{
		case APPS:
			break;

		case DOWN:
			if (File < (SIZE - 1))
				++File;
			break;

		case ENTER:
			switch (File)                                        // File Selection.
			{
			case 0:
				return Files[File] + ".accdb";
			case 1:
				return Files[File] + ".docx";
			case 2:
				return Files[File] + ".pptx";
			case 3:
				return Files[File] + ".pub";
			case 4:
				return Files[File] + ".txt";
			case 5:
				return Files[File] + ".xlsx";
			}
			break;

		case UP:
			if (File > 0)
				--File;
		}
		system("CLS");
	}
	return "";                                                // To show nothing is selected.
}

void LogInWindow(OperatingSystem& OS)
{
	string NewLines = "\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t\t\t\t\t";
	string Pass = "";

	while (true)
	{
		system("CLS");

		cout << "\n\n" <<  Tabs << OS.GetName() << NewLines << Tabs << "Hint : " << OS.GetHint() << "\n\n";
		cout << Tabs << "Type Password : ";
		getline(cin, Pass);
		Sleep(200);

		if (Pass == OS.GetPass())
		{
			system("CLS");
			cout << NewLines << "\n\n\n\n\n" << Tabs << "      Welcome " << NewLines;
			Sleep(1000);
			break;
		}
		
		cout << "\n\n\n\n\n" << Tabs << " Wrong Password. \n\n\n";
		Sleep(600);
	}
}

void RecycleBin(OperatingSystem& OS)
{

}

void ThisPC(OperatingSystem& OS)
{
	void Apps(OperatingSystem & OS);

	int Action = -1;
	bool KeepRuning = true;
	vector<string> Name;
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	size_t Size;
	string Tabs = "\t\t\t";

	OS.MoveStart();

	while ((Action != EXIT) && KeepRuning)
	{
		Name = OS.GetList();                              // Getting Drives/Files/Folder names.
		Size = Name.size() - 1;                           // As last element is a number.

		cout << "\n\n";

		if (Name.empty())                                // Name will be empty if there will be no Item.
			cout << "\n" << Tabs << Tabs << " This Is Empty." << NewLines << "\t0 Items    0 Item selected \n";
		else
		{
			if (OS.GetType() == _DRIVE)                  // For Drives.
			{
				for (size_t i = 0; i < Size; ++i)
					cout << "\n\n" << Tabs << "\t" << Name[i] << "\n";

				for (size_t i = 0; i < (26 - (Size * 3)); ++i)
					cout << "\n";
			}
			else
			{
				for (size_t i = 0; i < Size; ++i)
					cout << "\t\t" << Name[i] << "\n\n";

				for (size_t i = 0; i < (26 - (Size * 2)); ++i)
					cout << "\n";
			}
			cout << "\t" << Name[Size] << " Items    1 Item selected \n";
		}
		Action = KeysInput();                                   // Take Input From Keys

		switch (Action)
		{
		case APPS:
				Apps(OS);
			break;

		case BACK:
			if (OS.GetType() == _DRIVE)
				KeepRuning = false;
			else
				OS.MoveOut();
			break;

		case DEL:
			if(OS.GetType() != _DRIVE)
				OS.TempDelete();
			break;

		case DOWN:
			OS.MoveNext();
			break;

		case EXIT:
			//Exit:
			break;

		case ENTER:
			OS.MoveIn();
			break;

		case F2:
			ReName(OS);
			break;

		case F5:
			system("CLS");
			Sleep(25);
			break;

		case UP:
			OS.MovePrev();
		}
		system("CLS");
	}
}

void Time()
{
	time_t CurrTime = time(NULL);
	char NewTime[26];
	string Divider = "      |  ";
	string Tabs = "\t\t\t";

	ctime_s(NewTime, sizeof NewTime, &CurrTime);
	                                                          // Print Screen
	for (int i = 0; i < 3; ++i)
		cout << Tabs << Tabs << Divider << "\n";

	cout << Tabs << "Date" << Tabs << Divider << Tabs << "Time" << "\n";

	for (int i = 0; i < 4; ++i)
		cout << Tabs << Tabs << Divider << "\n";
	                                                        // Day and Hours
	cout << "\t\t  Day :  " << NewTime[0] << NewTime[1] << NewTime[2] << " / " << NewTime[8] << NewTime[9];
	cout << "\t\t" << Divider;
	cout << "\t\t    Hours :  " << NewTime[11] << NewTime[12] << "\n";

	for (int i = 0; i < 2; ++i)
		cout << Tabs << Tabs << Divider << "\n";
	                                                         // Month and Mints
	cout << "\t\t Month :  " << NewTime[4] << NewTime[5] << NewTime[6];
	cout << "\t\t\t" << Divider;
	cout << "\t\t    Mints :  " << NewTime[14] << NewTime[15] << "\n";

	for (int i = 0; i < 2; ++i)
		cout << Tabs << Tabs << Divider << "\n";
	                                                        // Year and Sec
	cout << "\t\t Year :  " << NewTime[20] << NewTime[21] << NewTime[22] << NewTime[23];
	cout << "\t\t\t" << Divider;
	cout << "\t\t    Sec :  " << NewTime[17] << NewTime[18] << "\n";

	for (int i = 0; i < 5; ++i)
		cout << Tabs << Tabs << Divider << "\n";
	                                                         // Formated
	cout << "\t\t" << NewTime[8] << NewTime[9] << "-" << NewTime[4] << NewTime[5] << NewTime[6]
		 << "-" << NewTime[20] << NewTime[21] << NewTime[22] << NewTime[23];
	cout << "\t\t\t" << Divider;
	cout << "\t\t   " << NewTime[11] << NewTime[12] << " : " << NewTime[14] << NewTime[15]
		<< " : " << NewTime[17] << NewTime[18] << "\n";

	for (int i = 0; i < 8; ++i)
		cout << Tabs << Tabs << Divider << "\n";
}

void UsersControls(OperatingSystem& OS)
{
	void ChangeCredential(OperatingSystem& OS);
	bool Verification(OperatingSystem& OS);
	void ViewUsers(OperatingSystem& OS);

	int Action = -1;
	int op = 0;
	const size_t SIZE = 5;
	string NewLines = "\n\n\n\n\n\n";
	string Tabs = "\t\t";
	string Controls[SIZE] = {"View Users", "Change Credentials", "Add New User", "Delete User", "Switch User"};
 

	while (Action != BACK)
	{
		cout << CPANEL << UserControls << "\n\n\n\n";

		for (size_t i = 0; i < SIZE; ++i)
			if (op == i)
				cout << Tabs << "  --> " << Controls[i] << " <--\n\n\n";
			else
				cout << Tabs << Controls[i] << "\n\n\n";

		cout << NewLines << "\t" << SIZE << " Items    1 Item selected \n";

		Action = KeysInput();                                 // Take Input From Keys

		switch (Action)
		{
		case BACK:
			break;

		case DOWN:
			if (op < (SIZE - 1))
				if (OS.Administrator())
					while (true)
						if ((op == 0) || (op == 1) || (op == 5))
							break;
						else
							++op;
				else
					++op;
			break;

		case ENTER:
			system("CLS");

			switch (op)
			{
			case 0:
				ViewUsers(OS);
				break;

			case 1:
				if (Verification(OS))
					ChangeCredential(OS);
				break;

			case 2:
				if (Verification(OS))
					NewUser(OS);
				break;

			case 3:
				if (Verification(OS))
					//DELETEUSER()
				break;

			case 4:
				//Switch User
				break;
			}
			break;

		case UP:
			if (op > 0)
				if (OS.Administrator())
					while (true)
						if ((op == 0) || (op == 1) || (op == 5))
							break;
						else
							--op;
				else
					--op;
		}
		system("CLS");
	}
}

void UserCredentials(string& name, string& pass, string& hint, OperatingSystem& OS)
{
	string Report = "";
	string NewLines = "\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t\t\t\t";
	string Account = " >> | Adding New Account |";
	string Acc = "---Adding New Account---";
														// Name Input
	cout << CPANEL << UserControls << Account << "\n" << Tabs << Acc << NewLines;
	cout << Tabs << " Type User Name : ";
	getline(cin, name);
	Sleep(400);
	system("CLS");

	Trim(name);
														// Password Input
	cout << CPANEL << UserControls << Account << "\n" << Tabs << Acc << NewLines;
	cout << Tabs << " Type User Name : " << name << "\n\n";
	cout << Tabs << " Type Password : ";
	getline(cin, pass);
	Sleep(400);
	system("CLS");
														// Hint Input / Final View with Report
	cout << CPANEL << UserControls << Account << "\n" << Tabs << Acc << NewLines;
	cout << Tabs << " Type User Name : " << name << "\n\n";
	cout << Tabs << " Type Password : " << pass << "\n\n";

	if (!(pass.empty()))
	{
		cout << Tabs << " Type Password Hint : ";
		getline(cin, hint);
		Sleep(400);
		system("CLS");
														// Final View with Report
		cout << CPANEL << UserControls << Account << "\n" << Tabs << Acc << NewLines;
		cout << Tabs << " Type User Name : " << name << "\n\n";
		cout << Tabs << " Type Password : " << pass << "\n\n";
		cout << Tabs << " Type Password Hint : " << hint << "\n\n";
	}
	else
		cout << "\n\n";

	cout << NewLines;

	if (name.empty())                                        // Test to check Empty String.
		Report = " User Can't be Added. (Name Is Empty)";

	if (InvalidChar(name))                                   // Test to check Invalid Characters.
	{
		name = "";                                           // As a sign of action is not completed;
		Report = " Name contains Invalid Characters. (\\/*?\"<>|)";
	}

	if (OS.Exist(name))                                      // Test to check Pre-Existence of User.
	{
		name = "";                                           // As a sign of action is not completed;
		Report = " User with this Name Already Exists.";
	}

	if (Report.empty())                                       // If none of above Conditions fulfilled.
		Report = " User Added. (Go to Control Panel to Switch User)";

	cout << Tabs << Report << "\n\n";

	Sleep(1300);
	system("CLS");
}

void ViewDrives(OperatingSystem& OS)
{
	int Action = -1;
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t";
	vector<string> Name;
	string View = " >> | View Partitions |";
	size_t Size;

	OS.MoveStart();

	while (Action != BACK)
	{
		Name = OS.GetList();
		Size = Name.size() - 1;

		cout << CPANEL << DriveControls << View  << "\n\n\n\n";
		
		for (size_t i = 0; i < Size; ++i)
			cout << Tabs << Name[i] << "\n\n\n";

		for (size_t i = 0; i < (24 - (Size * 3)); ++i)
			cout << "\n";

		cout << "\t" << OS.ItemsCount() << " Items    1 Item selected \n";
		
		Action = KeysInput();

		switch (Action)
		{
		case DOWN:
			OS.MoveNext();
			break;

		case UP:
			OS.MovePrev();
		}
		system("CLS");
	}
}

bool Verification(OperatingSystem& OS)
{
	string Report = "";
	string NewLines = "\n\n\n\n\n\n\n";
	string Tabs = "\t\t\t\t\t";
	string Pass;

	cout << "\n\n" << Tabs << " Verification" << NewLines << Tabs << "Hint : "
		 << OS.GetHint() << "\n\n" << Tabs << "Type Password : ";
	getline(cin, Pass);

	system("CLS");

	cout << "\n\n" << Tabs << " Verification" << NewLines << Tabs << "Hint : "
		 << OS.GetHint() << "\n\n" << Tabs << "Type Password : " << Pass;

	if (OS.GetPass() == Pass)
	{
		cout << NewLines << NewLines << Tabs << " Verified \n\n\n\n";

		Sleep(600);
		system("CLS");

		return true;
	}
	cout << NewLines << NewLines << Tabs << "  Invalid \n\n\n\n";

	Sleep(600);
	system("CLS");

	return false;
}

void ViewUsers(OperatingSystem& OS)
{
	int Action = -1;
	string NewLines = "\n\n\n\n\n\n\n\n\n\n\n\n";
	string Tabs = "\t\t";
	vector<string> Name;
	string View = " >> | View Users |";
	size_t Size;

	while (Action != BACK)
	{
		Name = OS.GetUserList();
		Size = Name.size() - 1;

		cout << CPANEL << UserControls << View << "\n\n\n\n";

		for (size_t i = 0; i < Size; ++i)
			cout << Tabs << Name[i] << "\n\n\n";

		for (size_t i = 0; i < (24 - (Size * 3)); ++i)
			cout << "\n";

		cout << "\t" << OS.ItemsCount() << " Items    1 Item selected \n";

		Action = KeysInput();

		switch (Action)
		{
		case DOWN:
			OS.MoveNext();
			break;

		case UP:
			OS.MovePrev();
		}
		system("CLS");
	}
}
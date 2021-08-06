/* assess4.cpp - Assesssment 4 - Ethan Davis
 * This program allows the user to catalog
 *   and maintain a collection of video games.
 *   Updated to use dynamic memory c strings
 *   and added a Collector class
 */

// For constants, includes and function prototypes
#include "main.h"

int main()
{
	int menuChoice = 0;
	// define collector class
	Collector collector;

	cout << "\nWelcome to Ethan's Video Game Catalog Program!\n";
	// loop until user selects 4 (Exit)
	while(menuChoice != 6)
	{
		DisplayMenu();
		// Prompt user and validate input
		menuChoice = GetIntInput(1, 6);
		cout << endl;
		// Call function based on menu choice
		switch(menuChoice)
		{
		case 1:
			// Add games to collection
			collector.AddEntry();
			break;	
		case 2:
			// Show all games in collection
			collector.DisplayEntries();
			break;	
		case 3:
			// Remove game from ocllection
			collector.DeleteEntry();
			break;
		case 4:
			// Write collection to file
			collector.WriteFile();
			break;
		case 5:
			// Read collection in from file
			collector.ReadFile();
			break;
		case 6:
			// Exit program
			cout << "Goodbye!" << endl;
			break;
		}
	}
        return 0;
}

// Purpose: Displays the main menu.
void DisplayMenu()
{
	cout << "---------------------------\n";
	cout << "|        Main Menu        |\n";
	cout << "---------------------------\n";
	cout << " 1) Add Game to Collection\n";
	cout << " 2) Show all Games\n";
	cout << " 3) Delete from Collection\n";
	cout << " 4) Write Collection to a File\n";
	cout << " 5) Add Games from a File\n";
	cout << " 6) Exit\n";
	cout << " Please Enter your Choice: ";
}

/* Purpose: Get a c-string from user input.
 *   Makes sure input is less than MAX_CHAR.
 * Parameters: variable to assign c-string
 *   to.
 */
void GetStringInput(char varName[])
{
	// load c-string into temp variable
	char tmpStr[MAX_CHAR];
	cin.getline(tmpStr, MAX_CHAR - 1);
	// Show error and prompt again if string is
	// too long.
	while(cin.fail())
	{
		// clear error state and remove \n
		// from buffer.
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Input to long! Limit to " << MAX_CHAR << " letter: ";
		cin.getline(tmpStr, MAX_CHAR - 1);
	}
	// copy c-string to varName
	strcpy(varName, tmpStr);
}

/* Purpose: Get an integer from the user.
 *   Validates input as int and within min/max range.
 * Parameters: the minimum and maximum allowed 
 *   integer input.
 * Return: Valid integer
 */
int GetIntInput(int min, int max)
{
	int num = 0;
	cin >> num;
	// Display error and prompt again if input
	// is not a int or within valid range.
	while(cin.fail() || num < min || num > max)
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Please enter numbers only (";
		cout << min << "-" << max << "). Try again: ";
		cin >> num;
	}
	// Remove leftover newline from buffer
	cin.ignore(200,'\n'); 
	return num;
}

/* Purpose: Gets a double from the user.
 *   Validates input as double and within
 *   min/max range.
 * Parameters: the minimum and maximum allowed 
 *   double input.
 * Return: Valid double
 */
double GetDoubleInput(double min, double max)
{
	double num = 0;
	cin >> num;
	while(cin.fail() || num < min || num > max)
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Please enter a number only (";
		cout << fixed << showpoint << setprecision(1);
		cout << min << "-" << max << "). Try again: ";
		cin >> num;
	}
	cin.ignore(200,'\n'); 
	return num;
}

/* Purpose: Gets a yes/no repsonse from user.
 *   validates input as y or n. 
 * Parameters: users answer variable name.
 */
void Confirm(char& userChar)
{
	cin >> userChar;
	// Makes sure input is a char and either y or n.
	while(cin.fail() || (userChar != 'y' && userChar != 'n'))
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Invalid input! Try again (y/n): ";
		cin >> userChar;
	}
	cin.ignore(200,'\n'); 
}

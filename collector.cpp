/* collector.cpp - Assessment 4 - Ethan Davis
 * This file is the implementation file for
 *  the Collector class.
 */

#include "collector.h"

// Default constructor 
Collector::Collector()
{
	count = 0;
}

/* Purpose: Allows user to add new entries to
 *   game collection. Validate each input with
 *   variable type specific functions.
 * Parameters: game collection, number of games
 *  in collection.
 */
void Collector::AddEntry()
{
        // Temporary variables
        char tTitle[MAX_CHAR], tPlatform[MAX_CHAR], tGenre[MAX_CHAR];
        int tYear;
        double tRating;
        char addAnother = 'y';
        // loop until they select n at the prompt
        do
        {
                // Use setter functions to assign temp
                // variables to class members
                cout << "Enter Game Title: ";
                GetStringInput(tTitle);
                aGame[count].setTitle(tTitle);
                cout << "Enter Platform: ";
                GetStringInput(tPlatform);
                aGame[count].setPlatform(tPlatform);
                cout << "Enter Genre: ";
                GetStringInput(tGenre);
                aGame[count].setGenre(tGenre);
                cout << "Enter Release Year (1970-2021): ";
                // get int input with range of 1970 to 2021
                tYear = GetIntInput(1970, 2021);
                aGame[count].setYear(tYear);
                cout << "Enter Rating (5.0 Scale): ";
                // get int input with range of 1.0 to 5.0
                tRating = GetDoubleInput(1.0, 5.0);
                aGame[count].setRating(tRating);
                ++count;
                cout << "\n==Entry Saved!==\n";
                // Check if user wants to continue adding to collection
                cout << "Would you like to add another (y/n)? ";
                Confirm(addAnother);
                cout << endl;
        } while(addAnother == 'y');
}

/* Purpose: Displays a list of all games.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void Collector::DisplayEntries()
{
        // Show message and return if collection is empty
        if(count <= 0)
        {
                cout << "== No Games in Collection! ==\n" << endl;
                return;
        }
        cout << "---------------------------\n";
        cout << "|    Showing All Games    |\n";
        cout << "---------------------------\n";
        for(int i = 0; i < count; ++i)
        {
                // Include index for deletion
                cout << "\n=== Index " << i << " ===\n";
                cout << "Title: " << aGame[i].getTitle() << "\n";
                cout << "Platform: " << aGame[i].getPlatform() << "\n";
                cout << "Genre: " << aGame[i].getGenre() << "\n";
                cout << "Release Year: " << aGame[i].getYear() << "\n";
                cout << "Rating: " << aGame[i].getRating() << "\n";
        }
        cout << endl;
}

/* Purpose: Allows user to delete from collection.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void Collector::DeleteEntry()
{
        int deleteIndex = 0;
        char confirmDelete = 'n';
        // Alert user if there are no games to remove
        if(count == 0)
        {
                cout << "There are no games to delete!" << endl;
                return;
        }
        // Prompt user with valid range of indexes
        cout << "Enter index to delete (0-" << count - 1 << "): ";
        deleteIndex = GetIntInput(0, count - 1);
        // Confirm game title with user before deletion
        cout << "Are you sure you want to delete " << aGame[deleteIndex].getTitle();
        cout << " (y/n)? ";
        Confirm(confirmDelete);
        if(confirmDelete == 'y')
        {
                cout << aGame[deleteIndex].getTitle() << " deleted from Catalog.\n";
                cout << endl;
                // loop from deletion index
                for(int i = deleteIndex; i < count - 1; ++i)
                {
                        // set value at each index to
                        // value of index ahead of it.
                        aGame[i] = aGame[i + 1];
                }
                // Decrease count by 1 to reflect deletion
                --count;
        }
}

/* Purpose: Allows user to specify a file to write game
 *  collection to.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void Collector::WriteFile()
{
        char fileName[MAX_CHAR];
        ofstream outFile;
        // Prompt user for file name
        cout << "Enter a file name to create: ";
        GetStringInput(fileName);
        // Attempt to open file
        outFile.open(fileName);
        // Display error if file did not open
        if(!outFile.is_open())
        {
                cout << "Unable to open file for writing!" << endl;
                return;
        }
        // Loop through array of class objects and write
        // member variables to file.
        for(int i = 0; i < count; ++i)
        {
                outFile << aGame[i].getTitle() << endl;
                outFile << aGame[i].getGenre() << endl;
                outFile << aGame[i].getPlatform() << endl;
                outFile << aGame[i].getYear() << endl;
                outFile << aGame[i].getRating() << endl;
        }
        cout << "== Game collection saved to: " << fileName << " ==\n";
        cout << endl;
        outFile.close();
}

/* Purpose: Allows user to specify a file to load contents
 *  into game collection.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void Collector::ReadFile()
{
        char fileName[MAX_CHAR];
        ifstream inFile;
        //Temporary Variables
        char tTitle[MAX_CHAR], tGenre[MAX_CHAR], tPlatform[MAX_CHAR];
        int tYear;
        double tRating;

        cout << "Enter the file name to read in: ";
        GetStringInput(fileName);
        inFile.open(fileName);
        while(!inFile.is_open())
        {
                cout << "Unable to open file! Check the file name and try again.";
                cout << endl;
                return;
        }
        // Loop while first C String Title is found
        while(inFile.getline(tTitle, MAX_CHAR-1))
        {
                // Assign contents of file to temp variables
                inFile.getline(tGenre, MAX_CHAR-1);
                inFile.getline(tPlatform, MAX_CHAR-1);
                inFile >> tYear;
                inFile.ignore(100, '\n');
                inFile >> tRating;
                inFile.ignore(100, '\n');
                // Use setter functions to assign temp
                // variables to class members
                aGame[count].setTitle(tTitle);
                aGame[count].setGenre(tGenre);
                aGame[count].setPlatform(tPlatform);
                aGame[count].setYear(tYear);
                aGame[count].setRating(tRating);
                ++count;
        }
        inFile.close();
        cout << "== Games loaded from " << fileName << " into collection! == \n" << endl;
}


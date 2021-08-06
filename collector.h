#pragma once
#include "main.h"
#include "game.h"

/*  Class:  Information for list collector
    Members:
    *   variables:
    *      aGame: object array: collection of games
    *   functions:
    *      Collector(): default constructor
    *      AddEntry(): Add game to collection
    *      DisplayEntries(): Prints all games
    *      DeleteEntry(): Remove game from list
    *      WriteFile(): Writes all games to file
    *      ReadFile(): Adds games from file to collection
    */
class Collector
{
        public:
                // Constructors
                Collector();
		
		void AddEntry();
		void DisplayEntries();
		void DeleteEntry();
		void WriteFile();
		void ReadFile();

        private:
		Game aGame[MAX_ENTRIES];
		int count;
};

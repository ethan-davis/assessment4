/* game.cpp - Assessment 4 - Ethan Davis
 * This file is the implementation file for
 *  the Game class.
 */
#include "game.h"

/* Purpose: Default Constructor to load game class.
 *   Initialize member variables.
 */
Game::Game()
{
	title = NULL;
	platform = NULL;
	genre = NULL;
	year = 0;
	rating = 0.0;
}

// Deconstructor
Game::~Game()
{
	if(title != NULL)
	{
		delete [] title;
	}
	if(platform != NULL)
	{
		delete [] platform;
	}
	if(genre != NULL)
	{
		delete [] genre;
	}
}

//Copy constructor
Game::Game(const Game& cpy)
{
	*this = cpy;
}

// Operator Overload
const Game& Game::operator=(const Game& rhs)
{
	if(this != &rhs)
	{
		setTitle(rhs.title);
		setPlatform(rhs.platform);
		setGenre(rhs.genre);
		setYear(rhs.year);
		setRating(rhs.rating);
	}	
	return *this;
}

// Getter and Setter Game Class functions
char * Game::getTitle()
{
	return title;
}

char * Game::getPlatform()
{
	return platform;
}

char * Game::getGenre()
{
	return genre;
}

int Game::getYear()
{
	return year;
}

double Game::getRating()
{
	return rating;
}

void Game::setTitle(const char* sTitle)
{
	// Set c string to null
	if(title != NULL)
	{
		delete [] title;
	}
	// assign memory of input length + 1 
	title = new char[strlen(sTitle) + 1];
	// Copy input into dynamic memory
	strcpy(title, sTitle);
}

void Game::setPlatform(const char* sPlatform)
{
	if(platform != NULL)
	{
		delete [] platform;
	}
	platform = new char[strlen(sPlatform) + 1];
	strcpy(platform, sPlatform);
}

void Game::setGenre(const char* sGenre)
{
	if(genre != NULL)
	{
		delete [] genre;
	}
	genre = new char[strlen(sGenre) + 1];
	strcpy(genre, sGenre);
}

void Game::setYear(int sYear)
{
	year = sYear;
}

void Game::setRating(double sRating)
{
	rating = sRating;
}

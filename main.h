#pragma once
#include <iomanip>
#include <fstream>
using namespace std;

// Constants
const int MAX_ENTRIES = 100;

// For Class definition
#include "collector.h"
#include "game.h"

// Function Prototypes
void DisplayMenu();
void GetStringInput(char varName[]);
int GetIntInput(int min, int max);
double GetDoubleInput(double min, double max);
void Confirm(char& addAnother);

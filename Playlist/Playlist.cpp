/********************************************************************
 * Playlist.cpp :  
 * Program that randomly picks a song from a playlist; makes use of
 * string, vector, and random from the Standard Library.
 *
 * NOTE: This version of the program has numerous errors.
 * Your job is to...
 *	1.) fix all bugs
 *	2.) commit your changes to your local Git repository
 *	3.) push your changes to your remote Git respository
 *	4.) submit a Pull Request to your instructor's Git project
 *
 ********************************************************************
 */

 // Preprocessor directives
#include "pch.h"
#include <random>
#include <string>
#include <iostream> //FIXED: add #include iostream
using std::vector; //FIXED: add std::string
using std:string; //FIXED: add std::string
using namespace std; //FIXED: add namespace standard to deal with cout, cin, endl, etc.

int main()
{
	// Create a vector of strings; add items using a list initializer
	//FIXED: correct line to proper vector initialization
	vector<string> songs = { "Happy Birthday", "Back to Life", "The Song from the Skyrizi Commercial", "Baby Shark" };

	// Add a 5th string to the end of the vector
	songs.push_back("Axel F"); //FIXED: instead of "put" use "push_back" 

	// Print the playlist to the screen
	cout << "Your Playlist:" << endl; //FIXED: replaced ">>" with the correct stream operator "<<"

	// Loop through the vector of songs; print each vector element to console.
	for ( int i = 0; i < songs.size(); i++) //FIXED: matched to proper for() loop syntax
	{
		cout << songs[i] << endl; //FIXED: matched to array syntax, instead of "song.get()" do "songs[i]"
	}

	// Set up a random number generator seeder
	std::random_device seed;

	// Create a random integer generator; chooses random ints from 0 to 4 (inclusive)
	std::uniform_int_distribution<int> rand_dist(0, 4);

	// Get the next random integer
	int index = rand_dist(seed);

	// Get the item from the vector at the randomly-selected index
	string currentSong = songs[index]; //FIXED: lowercase the "s" in "String" and instead of "song.get()" again, do "songs[index]"

	// Convert each charcter of the 'currentSong' string to UPPERCASE
	std::for_each(currentSong.begin(), currentSong.end(), [](char& c)//FIXED: used a different for() loop function to convert 'currentSong' to uppercase using for_each()
		{
			c = ::toupper(c);
		});

	// Print the UPPERCASE 'currentSong' string
	cout << "Now playing: " << currentSong << endl; //FIXED: placed "endl" to the end of the line

	return 0;
}

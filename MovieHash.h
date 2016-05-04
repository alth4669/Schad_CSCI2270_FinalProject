#ifndef MOVIEHASH_H
#define MOVIEHASH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct conflict
{
    string description;
    int startTime;
    int endTime;

    conflict(){};
    conflict(string init_desc, int init_start, int init_end)
    {
        description = init_desc;
        startTime = init_start;
        endTime = init_end;
    }
};

struct HashElem{
	std::string title;
	int startTime;
	int endTime;
	HashElem *next;
    HashElem *previous;

	HashElem(){};
	HashElem(std::string in_title, int in_startTime, int in_endTime)
	{
		title = in_title;
		startTime = in_startTime;
		endTime = in_endTime;
		next = NULL;
		previous = NULL;
	}

};

class MovieHash
{
    public:
        MovieHash();
        ~MovieHash();
        void insertMovie(std::string title, int startTime, int endTime, int index);
        void printTableContents();
        void findMovie(std::string name);
        void doubleFeature(std::string inputString1, std::string inputString2);
        void addTime(int z, int startTime, int endTime, bool SoE);
        bool timeCompare(int compareOne, int compareTwo, int compareThree, int compareFour);
        void randomMovie();
        void randomDouble();
        void randomDoubleFeature(std::string inputString1, std::string inputString2);
        void atThisTime(int time);
        void enterConflict(string desc, int startTime, int endTime);
        void listConflicts();
    protected:
    private:
        int s = 5;
        int movieOne[6];
        int movieTwo[6];
        HashElem* hashTable[5];
        vector <conflict> conflictList;
        bool conflictCheck(HashElem* movie);
};

#endif // MOVIEHASH_H

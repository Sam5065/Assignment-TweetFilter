#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//UCLan CO1409 Programming
//Assessment 2 - Tweet Filter
//G20938631 - Samual Hilland

bool readFile(string tweetFile) //checks if file can be read
{
	ifstream infile(tweetFile);
	
	if (!infile)
	{
		cout << tweetFile << " could not be accessed!" << endl; //error message
		return false;
	}
	else
	{
		return true;
	}
}

void storeBannedWords(string badWordFile, bool canBannedFileBeRead, string bannedWordList[], int bannedListSize)//reads then stores the banned word list.
{
	if (canBannedFileBeRead == true) //stores badwords
	{
		ifstream infile(badWordFile); //inputs tweet list

		string currentBadWord; //current badword to be stored.

		while (!infile.eof())
		{
			for (int i = 0; i < bannedListSize; i++)
			{
				getline(infile, currentBadWord); //reads line, stores it as var
				bannedWordList[i] = currentBadWord; //stores word
			}
		}
	}
	else
	{
		cout << "Error. File(s) not found." << endl; //backup error message
	}
}

void badWordsReport(int badWordsTally[])//prints out how many banned words are found
{
	//Number relates to the location in the array
	// layout example:
	// Banned word     = [array location]
	int wordAwesomeLoc = 0;
	int wordEasyLoc = 1;
	int wordBackLoc = 2;
	int wordCarLoc = 3;
	int wordOneLoc = 4;
	int wordDogLoc = 5;
	int wordAbleLoc = 6;
	int wordMeaningLoc = 7;
	int wordWouldLoc = 8;
	int wordGreatLoc = 9;

	//banned word report:
	cout << "Banned word report" << endl;
	cout << "===================" << endl;
	cout << "'Awesome' found: " << badWordsTally[wordAwesomeLoc] << endl;
	cout << "'Easy' found: " << badWordsTally[wordEasyLoc] << endl;
	cout << "'Back' found: " << badWordsTally[wordBackLoc] << endl;
	cout << "'Car' found: " << badWordsTally[wordCarLoc] << endl;
	cout << "'One' found: " << badWordsTally[wordOneLoc] << endl;
	cout << "'Dog' found: " << badWordsTally[wordDogLoc] << endl;
	cout << "'Able' found: " << badWordsTally[wordAbleLoc] << endl;
	cout << "'Meaning' found: " << badWordsTally[wordMeaningLoc] << endl;
	cout << "'Would' found: " << badWordsTally[wordWouldLoc] << endl;
	cout << "'Great' found: " << badWordsTally[wordGreatLoc] << endl;
	cout << "===================" << endl;
}

int main()
{
	bool canTweetFileBeRead = false; //stores if the .txt file can be accessed or not,
	bool canBannedFileBeRead = false; //stores if the banned words can be accessed or not.

	const string tweetFile1 = "tweets1.txt"; //file name for tweets 1 file
	const string tweetFile1out = "tweets1Filtered.txt"; //tweet 1 output file name
	const string badWordFile = "banned.txt"; //file name for the banned words
	string currentTxtFile = ""; //stores which txt file is being currently filtered.

	const int bannedListSize = 10; //the amount of banned words in "banned.txt"
	const int tweets1Amount = 38; //the amount of words in tweetsfile 1.
	int tweetsAmount; //the amount of tweets to be filtered.

	string bannedWordList[bannedListSize]; //arrary - stores the banned words
	string tweetList[tweets1Amount]; //array - stores the tweets
	int badWordsTally[bannedListSize]; //stores the amount of times a banned word shows up

	//Number relates to the location in the array
	// layout example:
	// Banned word  = [array location]
	const int wordAwesomeLoc = 0;
	const int wordEasyLoc = 1;
	const int wordBackLoc = 2;
	const int wordCarLoc = 3;
	const int wordOneLoc = 4;
	const int wordDogLoc = 5;
	const int wordAbleLoc = 6;
	const int wordMeaningLoc = 7;
	const int wordWouldLoc = 8;
	const int wordGreatLoc = 9;
	const int tallyDefault = 0; //default value to reset array

	for (int i = 0; i < bannedListSize; i++) //prepares the tally array to count the amount of badwords which appear.
	{
		badWordsTally[i] = tallyDefault; //sets each array (tally) value to 0.
	}

	currentTxtFile = tweetFile1; //sets the current tweet file to the 1st .txt file

	if (currentTxtFile == tweetFile1) //sets the amount of tweets to be filtered
	{
		tweetsAmount = tweets1Amount;
	}

	canBannedFileBeRead = readFile(badWordFile); //checks if the banned words file can be accessed.
	canTweetFileBeRead = readFile(currentTxtFile);//checks if the tweet file can be accessed.
	storeBannedWords(badWordFile, canBannedFileBeRead, bannedWordList, bannedListSize); //calls function to read & store the banned words

	//if files (banned & tweets) can be read, continue:
	if (canTweetFileBeRead == true && canBannedFileBeRead == true) 
	{
		ifstream infile(currentTxtFile); //inputs tweet list 

		ofstream outfile(tweetFile1out); //sets the filtered output file

		string tweet; //the current tweet stored.

		while (!infile.eof())//while the end of the file isnt reached:
		{
			for (int i = 0; i < tweets1Amount; i++) //for every tweet, store it.
			{
				infile >> tweet; //inputs the tweet char

				for (int i = 0; i < tweets1Amount ; i++) //checks if word is banned. if banned, output "***"
				{	
					if (tweet == bannedWordList[wordAwesomeLoc])//word = awesome
					{
						badWordsTally[wordAwesomeLoc]++;//increase the tally by 1
						outfile << "*** ";//output "***" to the filtered file.
						break;//end search
					}
					else if (tweet == bannedWordList[wordEasyLoc])//word = easy
					{
						badWordsTally[wordEasyLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordBackLoc])//word = back
					{
						badWordsTally[wordBackLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordCarLoc])//word = car
					{
						badWordsTally[wordCarLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordOneLoc])//word = one
					{
						badWordsTally[wordOneLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordDogLoc])//word = dog
					{
						badWordsTally[wordDogLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordAbleLoc])//word = able
					{
						badWordsTally[wordAbleLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordMeaningLoc])//word = meaning
					{
						badWordsTally[wordMeaningLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordWouldLoc])//word = wold
					{
						badWordsTally[wordWouldLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
					else if (tweet == bannedWordList[wordGreatLoc])//word = great
					{
						badWordsTally[wordGreatLoc]++;//increase the tally by 1
						outfile << "*** ";
						break;//end search
					}
				
					else //if char isnt banned, output normal word to the output file.
					{
						outfile << tweet << " ";
						break;
					}
				}
			}
		}

		badWordsReport(badWordsTally);//calls the bad words report (shows the tally)
	}
	else
	{
		cout << "Error. File(s) not found." << endl; //backup error message if the files cannot be read.
	}
}
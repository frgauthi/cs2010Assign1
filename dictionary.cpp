//########################################################################################//
//##											##//
//##  A program to create a dictionary from a text file and provide frequency analysis	##//
//##  		     Frankie Gauthier - 4213091 - cs2010 - Assign1*/			##//
//##											##//
//########################################################################################//

#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

// Function Prototypes
void Dump(void);
int strLength(int);
bool wordCompare(int,int);
bool wordExists(int);
void clearRow(int);
void addWord();
int locateWord(int);


const int maxRows = 10;			// maximum number of words in the dictionary
const int maxLength = 20;		// max number of characters in a word
char dictionary[maxRows][maxLength]={0}; // init the char array with all zero's
int frequency[10] = {0};		// create int array to track the frequency of words
int ptr = 0; 				// init the row pointer as 0


// clears a row number that is passed to the function
void clearRow(int row){
	int i =0;
	while(dictionary[row][i] != 0){
		dictionary[row][i] = 0;
		i++;
	}
}


// returns the location of the word passed to the function based on its row number
// if the word isnt found returns 0;
int locateWord(int row){
	for(int i = 0; i < ptr; i++){
        	if (wordCompare(row,i)) return i;
        }
        return 0;

}


// searches the dictionary for the word passed into the function by its row number
bool wordExists(int row){
	for(int i = 0; i < ptr; i++){
		if (wordCompare(row,i)) return true;
	}
	return false;
}

 
// compare two rows to determine if the words are the same
bool wordCompare(int row1, int row2){
		
	if (strLength(row1) != strLength(row2)) return false;
	for( int i = 0; i<strLength(row1); i++)
	{
		if (dictionary[row1][i] != dictionary[row2][i]) return false;
	}
		
return true;
}

// strLength determines the length of a particular row in the dictionary
int strLength(int row){
	int count = 0;
	while(dictionary[row][count] != 0)
	{
		count++;
	}
return count;
}

// Dump takes a 2d array of chars and prints it with each row on a seperate line
// and prints the frequency next to the word
void Dump(){
	
	for(int i = 0; i< ptr; i++)
	{
		for(int j = 0; j<maxLength; j++)
		{
			if(dictionary[i][j] == 0) break;
			cout << dictionary[i][j];
			
		}
	cout << "\t\t\t" << frequency[i]  <<  endl;
	}
	 
}


// main function
int main() {

char ch;
int newWord= 0;
int ltrCount = 0;
 
// while there is input valid input put words into the dictionary
while( cin.good() )
{

// if there are too many words for the array warn user and break out of the loop
if(ptr > maxRows-1){	
cout << endl << "* Too many words in the file.. dictionary contains the first 10 words" << endl;
break;
}

 ch = tolower(cin.get()); // convert the characters that are read into lowercase

 if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
    {
		if(ltrCount < maxLength){
       		dictionary[ptr][ltrCount] = ch;  	// while there is room to input more chars add next char
       		newWord = 1;				// to dictionary
		ltrCount += 1; 
		}
		
			
		
	}
	
 else
       if (newWord) 	
          {
		if (ltrCount >= maxLength) cout << endl <<  "* Some words have exceeded the maximum length and have been truncated!";
		
		if(wordExists(ptr)){
			frequency[locateWord(ptr)]++;
			clearRow(ptr);				// clear the row and reset to input next word
			ltrCount =0;
			newWord =0;
		}
		else{
			frequency[ptr]++;	
			ptr += 1; 			//increase the pointer and reset to read next word
			ltrCount = 0; 		
              		newWord = 0; 
        	}  
	}

}

 cout << endl  << "Word\t\t    Frequency" << endl << "-----------------------------" << endl;
	 
 Dump();   // dump dictionary 
 

return 0;
}
 

/*A program to create a dictionary from a text file and provide frequency analysis
  Frankie Gauthier - 4213091 - cs2010 - Assign1*/

#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

//prototype functions
void Dump(void);
int strLength(int);
bool wordCompare(int,int);


const int maxRows = 10;
const int maxLength = 132;
char dictionary[maxRows][maxLength]={0}; // init the char array with all zero's
int ptr = 0; 				// init the row pointer as 0
 
// compare two rows to determine if the words are the same
bool wordCompare(int row1, int row2){
	
	int col = 0;
	if(strLength(row1) == strLength(row2))
	{
		while(dictionary[row1][col] != 0)
		{
			if(dictionary[row1][col] =! dictionary[row2][col]) return false; 
		}
		return true;
		
	}
	else return false;
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
void Dump(){
	
	for(int i = 0; i< ptr; i++)
	{
		for(int j = 0; j<maxLength; j++)
		{
			if(dictionary[i][j] == 0) break;
			cout << dictionary[i][j];
		}
	cout << endl;
	}
	 
}


// main function
int main() {

char ch;
int newWord= 0;
int ltrCount = 0;
 

while( cin.good() )
{
 ch = cin.get();
 if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
    {
       	dictionary[ptr][ltrCount] = ch;
       	newWord = 1;
	ltrCount += 1; // increment the column pointer

	}
 else
       if (newWord) 	
          {
		ptr += 1; // set ptr location to the next word in the array
		ltrCount = 0; // set col pointer for loop back to 0 to start a new word
              	newWord = 0; // 
          }

}
 Dump();   // dump dictionary
 cout << "length of first string : " << strLength(0) << endl;
 cout << "length of second string: " << strLength(1) << endl;
 cout << wordCompare(0,0) << endl;
 return 0;
}
 

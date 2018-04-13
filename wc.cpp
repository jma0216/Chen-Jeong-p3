#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <string>

using namespace std;

/*
 * This main function is able to compute the number of words, bytes and lines given a file or multiple files.
 * One can specify the output given options -w, -l, -c.
 * @param argc
 * @param argv
 */
int main(int argc, char** argv){
  int fd;
  int n = 0;
  char buffer[1];
  int newLineCount = 0;
  int wordCount = 0;
  int byteCount = 0;
  int totalLines = 0;
  int totalWords = 0;
  int totalBytes = 0;
  bool isC = false; 
  bool isL = false;
  bool isW = false;
  int c;

  while((c = getopt(argc, argv, "l:c:w:")) != -1){  //Determines the option wither -l, -c, -w
      switch (c){ 
      case 'l': 
	isL = true;
	break;

      case 'c': 
	isC = true;
	break;
	
      case 'w': 
	isW = true;
	break;
      }
    }//while

  for(int i = 1; argv[i] != NULL; i++){ //Goes through the arguments
    if(*argv[i] == '-'){    //If one of the arguments start with '-'
	
	if(isL){
	  continue;
	}
	else if(isC){
	  continue;
	}
	else if(isW){
	  continue;
	}
	else if(isL == false || isC == false || isW == false){ //Read from standard input 
	  while (true){
	  string message;
	  getline(cin, message);
	  }
	}//if
    }
	fd = open(argv[i], O_RDONLY);
      // check if fd is good                                                                                                                           
      if(fd < 0){
	cout << "error opening" << endl;
      } 

      bool onChar = false;

      //Computes bytes, newLines and spaces
      while((n = read(fd, buffer, 1)) > 0){
	byteCount++;  
	if(*buffer == '\n'){ //If you see a newline character
	  newLineCount++;
	}
	
	if(isspace(*buffer)){ //If you read a space in buffer
	  onChar = false;  //Then it is not on a character
	}
	else if(onChar == false){ //If you didnt read a space, and the previous buffer read was not a character
	  wordCount++;     //Then increment word
	  onChar = true;  //Set to true
	}
      }//while
      
      totalLines += newLineCount; //Total lines
      totalWords += wordCount;    //Total words
      totalBytes += byteCount;    //Total Bytes
       
      //Prints Bytes
      if(isC == true){
	cout << byteCount << " " << argv[i];
	cout << endl;
	byteCount = 0;
      }
      
      //Prints New Lines
      if(isL){
	cout << newLineCount << " " << argv[i];
	cout << endl;
	newLineCount = 0;
      }
      
      //Prints Word counts
      if(isW){
	cout << wordCount << " " << argv[i];
	cout << endl;
	wordCount = 0;
      }

      //Prints Lines, Words, and Bytes for each Argument
      else if (isC == false && isL == false && isW == false){
      cout << newLineCount << " ";
      newLineCount = 0;
      cout << wordCount << " ";
      wordCount = 0;
      cout << byteCount;
      byteCount = 0;
      cout << " " << argv[i];
      cout << endl;
      }//else
  }//for

  //Prints the total amount of bytes, lines, and total words.
      if(isL){
	cout << totalLines << " total" << endl;
      }
      if(isC){
	cout << totalBytes << " total" << endl;
      }
      if(isW){
	cout << totalWords << " total" << endl;
      }
      else if (isL == false && isC == false && isW == false){
	if(totalLines == 0 && totalWords == 0 && totalBytes == 0){
	  while (true){
	    string message;
	    getline(cin, message);
	  }//while true
	}//if
	else{
	cout << totalLines << " " << totalWords << " " << totalBytes << " total" << endl;
	}//else
      }
      
  }//main

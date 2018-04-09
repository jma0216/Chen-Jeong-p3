
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>

using namespace std;

int main(int argc, char** argv){
  int fd;
  int n = 0;
  char buffer[1];
  int newLineCount = 0;
  int wordCount = 0;
  int byteCount = 0;
  bool inSpace = true;
  int totalLines = 0;
  int totalWords = 0;
  int totalBytes = 0;
  bool isC = false; 
  bool isL = false;
  bool isW = false;

    int c;
    while((c = getopt(argc, argv, "l:c:w:")) != -1){
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


  for(int i = 1; argv[i] != NULL; i++){  //Reads all the files and computes the lines, bytes and words       
    if(*argv[i] == '-'){
      continue;
    }
    
    fd = open(argv[i], O_RDONLY);
    // check if fd is good                                                                                                                           
      if(fd < 0) cout << "error opening " << argv[i] << endl;     
    //Computes bytes, newLines and spaces
      while((n = read(fd, buffer, 1)) > 0){
	byteCount++;
	if(*buffer == '\n'){
	  newLineCount++;
	}
	
	if(isspace(*buffer)){
	  inSpace = true;
	}
	
	else if(inSpace){
	  wordCount++;
	  inSpace = false;
	}
      }//while
        
      totalLines += newLineCount;
      totalWords += wordCount;
      totalBytes += byteCount;
     
      if(isC == true){
	cout << byteCount << endl;
	byteCount = 0;
	
      }
      
      if(isL){
	cout << newLineCount << endl;
	newLineCount = 0;
      }
      
      if(isW){
	cout << wordCount << endl;
	wordCount = 0;
      }

      else{
      cout << "New Line Counts:" <<  newLineCount << endl;
      newLineCount = 0;
      cout << "Word counts:" << wordCount<< endl;
      wordCount = 0;
      cout << "Byte Counts: " << byteCount << endl;
      byteCount = 0;
      cout << argv[i] << endl;
      }//else
  }//for
      if(isL){
	cout << totalLines << " total" << endl;
      }
      if(isC){
	cout << totalBytes << " total" << endl;
      }
      if(isW){
	cout << totalWords << " total" << endl;
      }
      else {
	cout << "L W B: " << totalLines << " " << totalWords << " " << totalBytes << " total" << endl;
      }
      
  }//main






   /*
      if(*argv[i] == '-' && *argv[i+1] == 'c'){
	cout << byteCount << endl;
      }//if
      
      else if(*argv[i] == '-' && *argv[i+1] == 'l'){
	 cout << newLineCount << endl;
      }//if else
      
      else if(*argv[i] == '-' && *argv[i+1] == 'w'){
	cout << wordCount << endl;
      }//else if
     
    */
 


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <string>

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

    for(int i = 1; argv[i] != NULL; i++){

      if(*argv[i] == '-'){
	if(isL){
	  continue;
	}
	else if(isC){
	  continue;
	}
	else if(isW){
	  continue;
	}
	else if(isL == false || isC == false || isW == false){
	  string message;
	  getline(cin, message);
	  cout << message << endl;
	}
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
	cout << byteCount << " " << argv[i];
	cout << endl;
	byteCount = 0;
      }
      
      if(isL){
	cout << newLineCount << " " << argv[i];
	cout << endl;
	newLineCount = 0;
      }
      
      if(isW){
	cout << wordCount << " " << argv[i];
	cout << endl;
	wordCount = 0;
      }

      else if (isC == false && isL == false && isW == false){
      cout << newLineCount << " ";
      newLineCount = 0;
      cout << wordCount<< " ";
      wordCount = 0;
      cout << byteCount;
      byteCount = 0;
      cout << " " << argv[i];
      cout << endl;
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
      else if (isL == false && isC == false && isW == false) {
	cout << totalLines << " " << totalWords << " " << totalBytes << " total" << endl;
      }
      
  }//main

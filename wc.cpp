#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

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
  for(int i = 1; argv[i] != NULL; i++){ 
    fd = open(argv[i], O_RDONLY);
    // check if fd is good                                                                                                                           
    if(fd < 0) cout << "error opening " << argv[1] << endl;     
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
      cout << "New Line Counts:" <<  newLineCount << endl;
      totalLines += newLineCount;
      newLineCount = 0;
      cout << "Word counts:" << wordCount<< endl;
      totalWords += wordCount;
      wordCount = 0;
      cout << "Byte Counts: " << byteCount << endl;
      totalBytes += byteCount; 
      byteCount = 0;
      cout << argv[i] << endl;
  }//for                          
  cout << "L W B: " << totalLines << " " << totalWords << " " << totalBytes << " total" << endl;
}






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
 

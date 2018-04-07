#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv){
  
  int fd;
  fd = open(argv[1], O_RDONLY);
  
  // check if fd is good                                                                                                                                  
  if(fd < 0) cout << "error opening " << argv[1] << endl;
  
  int n = 0;
  char buffer[1];
  int newLineCount = 0;
  int wordCount = 0;
  int byteCount = 0;
  bool inSpace = true;
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
  cout << "Word counts:" << wordCount<< endl;
  cout << "Byte Counts: " << byteCount << endl;
 
  }
 

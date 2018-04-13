#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
using namespace std;

/**
 *read function that is called to receive input and print out to standard output
 */
void read(){
  string message;
  getline(cin,message);
  cout << message << endl;
}

/**
 *the main function reads the files sequentially, writing them to standard output  
 *when run ./cat [files], it will return all the files' contents   
 *when - is in the list of files, then start reading from standard input
 *if no files are specified, cat reads from standard input only   
 * 
 * @param argc
 * @param argv
 */
int main(int argc, char** argv){
  int fd, n;
  char buffer[1];
  string message;
  while(argv[1]==NULL){
    read();
  }//when no filename is given

  for(int i = 1; argv[i]!=NULL;i++){
    if(*argv[i] == '-') {
      while(true){
	read();
      }//while
    }//if a hyphen is found in the list of filenames
    fd = open(argv[i], O_RDONLY);
    while((n = read(fd, buffer, 1)) > 0){
      cout << buffer;
    }
    //cout << endl;
  }//for, until it reaches no more files 

  return 0;
}

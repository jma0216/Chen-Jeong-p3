#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

/*
 * read() takes no parameters and gets message from standard input
 * and calculates the length of the message.
 */
void read(){
  string message;
  getline(cin, message);
  cout << "input size: " << message.length() << endl;
}

/*
 * The main function calculates the size of a file
 * @param argc
 * @param argv
 */
int main(int argc, char** argv){
  int fd;
  struct stat f_stat;
  off_t totalsize = 0; 
  while(argv[1] == NULL) read(); //If no arguments, read from standard input.
  for(int i = 1; argv[i]!=NULL;i++){
    if((fd = open(argv[i], O_RDONLY)) < -1) return 1;  //Open the file
    if(fstat(fd, &f_stat) < 0) return 1;
    off_t filesize = f_stat.st_size;       //get the file size
    cout << "file size: " << filesize << " " <<argv[i] << endl; //file size for the files. 
    totalsize += filesize;   //calculates total filesize.
    filesize = 0; 
  }
  if(argv[2]!=NULL)  cout << "total size: " << totalsize << endl;
 
  
}

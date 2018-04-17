#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

void read(){
  string message;
  getline(cin, message);
  cout << "input size: " << message.length() << endl;
}

int main(int argc, char** argv){
  char buffer[1];
  int fd;
  struct stat f_stat;
  off_t totalsize = 0; 
  while(argv[1] == NULL) read();
  for(int i = 1; argv[i]!=NULL;i++){
    if((fd = open(argv[i], O_RDONLY)) < -1) return 1; 
    if(fstat(fd, &f_stat) < 0) return 1;
    off_t filesize = f_stat.st_size;
    cout << "file size: " << filesize << " " <<argv[i] << endl; 
    totalsize += filesize;  
    filesize = 0; 
  }
  if(argv[2]!=NULL)  cout << "total size: " << totalsize << endl;
 
  
}

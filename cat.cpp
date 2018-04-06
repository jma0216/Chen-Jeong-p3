#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
using namespace std;

void read(){
  string message;
  cin >> message;
  cout << message << endl;
}

int main(int argc, char** argv){
  int fd, n;
  char buffer[1];
  string message;
  while(argv[1]==NULL){
    read();
  }

  for(int i = 1; argv[i]!=NULL;i++){
    if(*argv[i] == '-') {
      while(true){
	read();
      }
    }
    cout << open(argv[i], O_RDONLY) << endl;
  }
  return 0;
}

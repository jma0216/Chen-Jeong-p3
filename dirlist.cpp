#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <dirent.h>

using namespace std;

int main(){
  DIR* dirptr;

  dirptr = opendir(".");
  if(dirptr == nullptr){
    perror("error opening directory");
    exit(1);
  }

  struct dirent * direntptr;
  direntptr = readdir(dirptr);
  while(direntptr != nullptr){
    cout << direntptr->d_name << endl;
    direntptr = readdir(dirptr);
  }
}

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <dirent.h>

using namespace std;

/*
 *  lists all of the files in the current working directory, printing one per each line
 *
 */
int main(){
  DIR* dirptr;
  
  //Open the directory
  dirptr = opendir(".");
  if(dirptr == nullptr){
    perror("error opening directory");
    exit(1);
  }

  struct dirent * direntptr;

  //Prints all of the files in the pwd
  direntptr = readdir(dirptr); 
  while(direntptr != nullptr){ 
    cout << direntptr->d_name << endl; 
    direntptr = readdir(dirptr); 
  }
}

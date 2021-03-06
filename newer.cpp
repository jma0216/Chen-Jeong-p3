#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h> 
#include <time.h> 
#include <iostream>

using namespace std;

/*
 * The main method in newer.cpp determines which file is newer according to the requested component of stat time.
 * @param argc
 * @param argv
 */
int main(int argc, char** argv){

  struct stat s;
  struct stat str;
  int fd2 = 0;
  int fd = 0;
  bool isA = false;
  bool isC = false;
  bool isM = false;
  int c;
  double d;
  while((c = getopt(argc, argv, "a:m:c:")) != -1){  //Determines the option wither -a, -m, -c
    switch (c){
    case 'a':
      isA = true;
      break;
      
    case 'm':
      isM = true;
      break;
      
    case 'c':
      isC = true;
      break;
    }//switch
  }//while          
  
   fd = open(argv[2], O_RDONLY);
    fd2 = open(argv[3], O_RDONLY);
    // check if fd and fd2 is good                                                                                                                                                                       
    if(fd < 0) cout << "error opening" << endl;
    if(fd2 < 0) cout << "error opening" << endl;

    errno = 0;
    if(fstat(fd, &s)){
      cout << "error" << endl;
      close(fd); 
      return -1; 
    }
    errno = 0;
    if(fstat(fd2, &str)){
      cout << "error" << endl;	  
      close(fd2);
      return -1;
    }

    if(isA){
      d = difftime(s.st_atime, str.st_atime);
      cout << "Most recent file: " << endl;
      if (d > 0.0){
	cout << ctime(&s.st_atime) << argv[2] << endl;
      }
      else{
	cout << ctime(&str.st_atime) << argv[3] << endl;
      }//else
      cout << endl;
      cout << "The times for each of the files" << endl;
      cout << ctime(&s.st_atime) << argv[2] << endl;
      cout << ctime(&str.st_atime) << argv[3] << endl;
    }//isA
    
    if(isM){
      d = difftime(s.st_mtime, str.st_mtime);
      cout << "Most recent file: " << endl;
      if(d > 0.0){
	cout << ctime(&s.st_mtime) << argv[2] << endl;
      }
      else{
	cout << ctime(&str.st_mtime) << argv[3] << endl;
      }//else
      cout << endl;
      cout << "The times for each of the files" << endl;
      cout << ctime(&s.st_mtime) << argv[2] << endl;
      cout << ctime(&str.st_mtime) << argv[3] << endl;
    }//isM
    
    if(isC){
      d = difftime(s.st_ctime, str.st_ctime);
      cout << "Most recent file: " << endl;
      if(d > 0.0){
	cout << ctime(&s.st_ctime) << argv[2] << endl;
      }
      else{
	cout << ctime(&s.st_ctime) << argv[3] << endl;
      } 
      cout << endl;
      cout << "The times for each of the files" << endl;
      cout << ctime(&s.st_ctime) << argv[2] << endl;
      cout << ctime(&s.st_ctime) << argv[3] << endl;
    }//isC  

}//main

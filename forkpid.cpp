#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
  
  pid_t pid;
  pid_t ppid;

  cout << "before fork";
  
  if ((pid = fork()) == -1) { // error
    perror("FORK ERROR");
  } 
  else if (pid == 0) {    // in child process  
    cout << " in child process id =  " << getpid();
  } 
  else {                  // in parent process
    sleep(3);
    cout << " in parent process id = " << getppid();
  } // if

  cout << endl;
  cout << "After fork: " << "mypid = " << getpid() << ", " 
       << "myppid = " << getppid() << endl;
 
  return EXIT_SUCCESS;


}

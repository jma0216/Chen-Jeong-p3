#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
  
  pid_t pid;

  cout << "This is process id: " << getpid() << endl;
  cout << "This is parent process id: " << getppid() << endl;

  
  if ((pid = fork()) == -1) { // error
    perror("FORK ERROR");
  } 
  else if (pid == 0) {    // in child process  
    cout << " Process id after fork=  " << getpid() << endl;
    cout << " Parent process id after  fork= " << getppid() << endl;
  } 
  else {                  // in parent process
    sleep(3);
  } // if

  return EXIT_SUCCESS;
}

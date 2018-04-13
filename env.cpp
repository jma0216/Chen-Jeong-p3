#include <iostream>

using namespace std;

/**
 *the main function prints the environment variables to standard output 
 */
int main (int argc, char** argv, char** envp) {
  int i = 0;
  while(envp[i] != nullptr){
    cout << envp[i] << endl; //print the environment variables to standard output
    i++;//increment to keep reading through all the env variables
  }  
}//main

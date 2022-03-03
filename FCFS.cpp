#include <queue>
#include <chrono>

#include <stdexcept>
#include <stdio.h>
#include <string>

#include "FCFS.hpp"

#include <iostream>
using namespace std;

FCFS::FCFS(string command,int processId){
    this->command = command;
    this->processId = processId;
}

FCFS::~FCFS() { }

int FCFS::getPid(){
    return processId;
}

string FCFS::getCMD(){
    return command;
}

/*
* Recuperado de
* https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po
*/
string FCFS::exec(string command) {
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   return result;
}

#include <chrono>

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <queue>
#include <fstream>
#include "FCFS.hpp"
using namespace std;
using namespace std::chrono;


string exec(string command) {
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = _popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   _pclose(pipe);
   return result;
}

int main(int argc, char *argv[]){
    //string ls = argv[1];
    
    queue<FCFS> processes;

    string CMD;

    ifstream commandList("commands.txt");
    int id=0;
    while (getline (commandList, CMD)) {
        string command = CMD;
        processes.push(FCFS (command,id));
        id++; 
    }

    commandList.close();

    //cout<<test->exec(test->getCMD())<<endl;
    auto start = high_resolution_clock::now();
    while (!processes.empty()) {
        FCFS process = processes.front(); 
        string command = process.getCMD();

        cout<<"Running process id "<<process.getPid()<<endl;

        cout<<exec(command)<<endl;

        cout<<"Process id "<<process.getPid()<<" ended"<<endl;
        auto current = high_resolution_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current - start);

        std::cout<<"Execution time "<< elapsed.count() << "ms\n";

        start = current;
        process.~FCFS();

        processes.pop();
    }

    return 0;
}
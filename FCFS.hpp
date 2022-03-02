#include <iostream>
#include <string>
using namespace std;

class FCFS{
    private:
        int processId;
        string command;
        double arrivalTime;
        double finishTime;
    public:
        FCFS(string command,int processId);
        ~FCFS();
        string exec(string command);
        int getPid();
        string getCMD();
};
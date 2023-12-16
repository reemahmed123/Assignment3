//fileName: A3_Sheetpb5_20221063.cpp
//Author: Reem Ahmed Abdallah
//ID: 20221063
//Section: s7 / s8
//Purpose: this program use system(tasklist > filename)to store iformation of command tasklist from cmd in file
//and parse file , store information of each process in processlist and display it
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  //sort()
#include <iomanip>   //setw()
#include<string>
using namespace std;
struct Process {
    string name;
    int pid;
    string sessionName;
    int sessionNumber;
    string memoryUsage;
};

class ProcessList {
private:
    vector<Process> processes;

public:
    void partition_TasklistOutput( string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return ;
    }

    string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        Process process;

        int pos = line.find_first_not_of(" "); // Skip leading whitespaces
        line = line.substr(pos);

        pos = line.find("  "); // Find the first occurrence of double space
        if (pos == string::npos) {
            continue; // Skip the line if the format is incorrect
        }

        process.name = line.substr(0, pos);
        line = line.substr(pos);

        istringstream iss(line);
        if (!(iss >> process.pid >> process.sessionName >> process.sessionNumber >> process.memoryUsage)) {
            continue; // Skip the line if partitioning fails
        }

        processes.push_back(process);
    }
}

    void sort_by_name() {
        sort(processes.begin(), processes.end(), []( Process a, Process b) {
            return a.name < b.name;
        });
    }

    void sort_by_PID() {
        sort(processes.begin(), processes.end(), []( Process a,  Process b) {
            return a.pid < b.pid;
        });
    }

    void sort_by_memory_usage() {
        sort(processes.begin(), processes.end(), []( Process a, Process b) {
            return a.memoryUsage < b.memoryUsage;
        });
    }

    void displayProcesses() {
        cout << setw(25) << "Name" << setw(25) << "PID" << setw(25) << "Session"
                  << setw(25) << "Session#" << setw(25) << "Memory Usage" << endl;
cout<<"==========================================================================================================="<<endl;

        for ( auto process : processes) {
cout<<setw(25)<<process.name<<setw(25)<<process.pid<<setw(25)<<process.sessionName<<setw(25)<<process.sessionNumber;
                     cout << setw(25) << process.memoryUsage <<"  k"<<endl;
        }
    }
};

int main() {
    string filename = "tasklist_output.txt";

    // Run tasklist command and store the output in a file
    string command = "tasklist > " + filename;
    int result =system(command.c_str());
    if (result != 0) {
        cerr << "Failed to execute tasklist command." << endl;
        return 1;
    }

    // Create an instance of ProcessList and parse the tasklist output file
    ProcessList processList;
    processList.partition_TasklistOutput(filename);
    int choice;
cout<<"display sorted according to: "<<endl;
cout<<"(1)sorted by name "<<endl;cout<<"(2) sorted by PID"<<endl;cout<<"(3) sorted by memory useage"<<endl;
cout<<"(0) leave it same:"<<endl;
cin>>choice;
switch(choice){
    case 1:
    processList.sort_by_name();
    cout <<"Processes Sorted by name"<<endl;
    cout << "-----------------------------------------------------------------------------------------------------\n";
        break;
    case 2:
    processList.sort_by_PID();
    cout << "Processes Sorted by PID" <<endl;
    cout << "-----------------------------------------------------------------------------------------------------\n";
        break;
    case 3:
    processList.sort_by_memory_usage();
    cout << "Processes Sorted by memory usage"<<endl;
    cout << "---------------------------------------------------------------------------------------------------\n";
        break;
}
    processList.displayProcesses();
}
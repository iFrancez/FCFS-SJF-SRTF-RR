
#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid; // process ID
    int arrival_time; // arrival time of the process
    int burst_time; // CPU burst time of the process
};

void fcfs_scheduling(Process processes[], int n) {
    queue<Process> ready_queue; // a queue to store the ready processes
    int current_time = 0; // the current time
    int total_waiting_time = 0; // the total waiting time of all processes
    int total_turnaround_time = 0; // the total turnaround time of all processes
    // save waiting and size 
    int wait[100], count = 0;

    //save turn - around
    int around[100], countR = 0;

    // loop through all processes
    for (int i = 0; i < n; i++) {
        // if the current time is less than the arrival time of the process, set the current time to the arrival time of the process
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        // add the process to the ready queue
        ready_queue.push(processes[i]);

        // process the processes in the ready queue
        while (!ready_queue.empty()) {
            Process current_process = ready_queue.front();
            ready_queue.pop();

            // calculate the waiting time and turnaround time of the process
            int waiting_time = current_time - current_process.arrival_time;
            int turnaround_time = waiting_time + current_process.burst_time;

            // add the waiting time and turnaround time to the total waiting time and total turnaround time
            total_waiting_time += waiting_time;

            //save and size waiting
            wait[i] = waiting_time;
            count++;

            total_turnaround_time += turnaround_time;

            // save an size around
            around[i] = turnaround_time;
            countR++;

            // set the current time to the completion time of the process
            current_time += current_process.burst_time;
        }
    }

    // calculate the average waiting time and average turnaround time
    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    // print the results
    cout << endl;
    cout << "Average waiting time: ";
    for (int i = 0; i < count - 1; i++) {
        cout << wait[i] << " + ";
    }
    cout << wait[count - 1] << " / " << n << " = " << avg_waiting_time << endl;


    cout << "Average turnaround time: ";
    for (int i = 0; i < countR - 1; i++) {
        cout << around[i] << " + ";
    }
    cout << around[countR - 1] << " / " << n << " = " << avg_turnaround_time << endl;
}

int main() {
    int n; // number of processes
    cout << "Enter the number of processes: " << endl;
    cin >> n;

    Process processes[100]; // an array to store the processes

    // get the arrival time and burst time of each process
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i << ": " << endl;
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].pid = i;
    }

    // perform FCFS scheduling
    fcfs_scheduling(processes, n);

    return 0;
}


/*
5
0 10
1 1
2 2
3 1
4 5
*/
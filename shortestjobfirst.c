#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int remaining_time; // Remaining time
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_arrival_time(struct Process processes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int find_min_burst_time(struct Process processes[], int n, int current_time) {
    int min_burst_time = 9999; // A large initial value
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_burst_time && processes[i].remaining_time > 0) {
            min_burst_time = processes[i].remaining_time;
            min_index = i;
        }
    }

    return min_index;
}

void sjf_preemptive(struct Process processes[], int n) {
    int current_time = 0;
    int total_burst_time = 0;

    for (int i = 0; i < n; i++) {
        total_burst_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    sort_by_arrival_time(processes, n);

    printf("Gantt Chart:\n");
    printf("0");
    while (current_time < total_burst_time) {
        int min_index = find_min_burst_time(processes, n, current_time);
        if (min_index == -1) {
            current_time++;
            continue;
        }

        processes[min_index].remaining_time--;

        // Print process execution
        printf(" -> P%d", processes[min_index].pid);

        current_time++;

        if (processes[min_index].remaining_time == 0) {
            processes[min_index].remaining_time = -1;
            processes[min_index].burst_time = current_time - processes[min_index].arrival_time;
        }
    }
    printf("\n");

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    float total_turnaround_time = 0, total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].burst_time, processes[i].burst_time - processes[i].arrival_time);
        total_turnaround_time += processes[i].burst_time;
        total_waiting_time += (processes[i].burst_time - processes[i].arrival_time);
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }

    sjf_preemptive(processes, n);

    return 0;
}


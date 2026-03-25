#include <iostream>
#include <algorithm>
using namespace std;

/* -------- FRACTIONAL KNAPSACK -------- */
struct Item {
    int weight;
    int profit;
    float ratio;
};

bool cmpItem(Item a, Item b) {
    return a.ratio > b.ratio;
}

void fractionalKnapsack() {
    int n;
    float capacity, totalProfit = 0;

    cout << "\nEnter number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, cmpItem);

    cout << "\nTracing Table (Fractional Knapsack)\n";
    cout << "Wt\tProfit\tRatio\tTaken\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            cout << items[i].weight << "\t" << items[i].profit
                 << "\t" << items[i].ratio << "\t1\n";
        } else {
            float frac = capacity / items[i].weight;
            totalProfit += items[i].profit * frac;
            cout << items[i].weight << "\t" << items[i].profit
                 << "\t" << items[i].ratio << "\t" << frac << endl;
            capacity = 0;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;
}

/* -------- JOB SEQUENCING -------- */
struct Job {
    char id;
    int deadline;
    int profit;
};

bool cmpJob(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing() {
    int n;
    cout << "\nEnter number of jobs: ";
    cin >> n;

    Job jobs[n];
    cout << "Enter job id, deadline, profit:\n";
    for (int i = 0; i < n; i++)
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    sort(jobs, jobs + n, cmpJob);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    char slot[maxDeadline + 1];
    for (int i = 1; i <= maxDeadline; i++)
        slot[i] = '-';

    cout << "\nTracing Table (Job Sequencing)\n";
    cout << "Job\tDeadline\tProfit\tSlot\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == '-') {
                slot[j] = jobs[i].id;
                cout << jobs[i].id << "\t"
                     << jobs[i].deadline << "\t\t"
                     << jobs[i].profit << "\t"
                     << j << endl;
                break;
            }
        }
    }

    cout << "\nJob Sequence: ";
    for (int i = 1; i <= maxDeadline; i++)
        if (slot[i] != '-')
            cout << slot[i] << " ";
    cout << endl;
}

/* -------- MAIN -------- */
int main() {
    int choice;

    cout << "Greedy Algorithms\n";
    cout << "1. Fractional Knapsack\n";
    cout << "2. Job Sequencing with Deadlines\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            fractionalKnapsack();
            break;
        case 2:
            jobSequencing();
            break;
        default:
            cout << "Invalid choice!";
    }

    return 0;
}


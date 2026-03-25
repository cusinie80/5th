#include <iostream>
using namespace std;

/* ---------- GREEDY ---------- */
void greedyKnapsack(int w[], int p[], int n, int W) {
    int profit = 0, weight = 0;

    cout << "\nTracing Table (Greedy Method):\n";
    cout << "Item\tWeight\tProfit\tStatus\n";

    for (int i = 0; i < n; i++) {
        if (weight + w[i] <= W) {
            weight += w[i];
            profit += p[i];
            cout << i + 1 << "\t" << w[i] << "\t" << p[i] << "\tSelected\n";
        } else {
            cout << i + 1 << "\t" << w[i] << "\t" << p[i] << "\tRejected\n";
        }
    }

    cout << "Total Profit (Greedy) = " << profit << endl;
}

/* ---------- DYNAMIC PROGRAMMING ---------- */
void dpKnapsack(int w[], int p[], int n, int W) {
    int dp[20][60] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (w[i - 1] <= j)
                dp[i][j] = max(p[i - 1] + dp[i - 1][j - w[i - 1]],
                               dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "\nTracing Table (DP Table):\n";
    cout << "Items\\Cap\t0\t10\t20\t30\t40\t50\n";

    for (int i = 0; i <= n; i++) {
        cout << i << "\t\t";
        for (int j = 0; j <= W; j += 10)
            cout << dp[i][j] << "\t";
        cout << endl;
    }

    cout << "Total Profit (DP) = " << dp[n][W] << endl;
}


/* ---------- BACKTRACKING ---------- */
int maxProfit = 0;

void backtrack(int w[], int p[], int n, int i, int W, int currW, int currP) {
    if (i == n) {
        if (currP > maxProfit)
            maxProfit = currP;
        return;
    }

    if (currW + w[i] <= W)
        backtrack(w, p, n, i + 1, W, currW + w[i], currP + p[i]);

    backtrack(w, p, n, i + 1, W, currW, currP);
}

void backtrackingKnapsack(int w[], int p[], int n, int W) {
    maxProfit = 0;
    backtrack(w, p, n, 0, W, 0, 0);
    cout << "\nTotal Profit (Backtracking) = " << maxProfit << endl;
}

/* ---------- MAIN ---------- */
int main() {
    int n, W;
    int w[20], p[20];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    greedyKnapsack(w, p, n, W);
    dpKnapsack(w, p, n, W);
    backtrackingKnapsack(w, p, n, W);

    return 0;
}



#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printPlan(const string& title, const vector<int>& bills, const vector<int>& plan, int taxDue) {    // function to print payment plan
    int currentTotal = 0;                                                                               // initializes variable to keep track of total
    cout << title << endl;                                                                              // prints plan title
    cout << "Tax Due: $" << setw(7) << taxDue << endl;                                               // prints total tax due
    cout << "                    Bills                Num                  Subtotal" << endl;           // output headers

    for (size_t i = 0; i < plan.size(); i++) {                                                          // loops through each bill with corresponding plan
        currentTotal += plan[i] * bills[i];                                                             // calculates subtotal for each denomination
        cout << setw(23) << "$" << setw(5) << bills[i] << "   x";                                // prints bill amount
        cout << setw(6) << plan[i] << " = $" << setw(7) << plan[i] * bills[i];                   // prints number of bills and subtotal
        cout << setw(20) << "$" << setw(7) << currentTotal << endl;                              // prints total
    }

    int totalBills = 0;                                                                                 // initializes variable to count total number of bills
    for (int count : plan) {
        totalBills += count;                                                                            // sum all bills
    }
    cout << "\nTotal number of bills needed: ";
    for (size_t i = 0; i < plan.size(); ++i) {
        if (i > 0) cout << " + ";                                                                       // prints plus sign symbols
        cout << plan[i];                                                                                // prints number of bills
    }
    cout << " = " << totalBills << endl;                                                                 // prints total number of bills
    cout << "—-----------------------------------------------------------------" << endl;
}

vector<int> calculateGreedyPlan(const vector<int>& bills, int amount) {                                  // function to calculate payment plan using greedy algorithm
    vector<int> result(bills.size(), 0);                                                           // initializes result vector
    int currentAmount = 0;                                                                               // initializes amount
    for (size_t i = 0; i < bills.size(); i++) {                                                          // loops through each bill denomination
        while (currentAmount + bills[i] <= amount) {                                                     // while adding another bill won't exceed the total amount due, add bill
            result[i]++;                                                                                 // increments count for bill
            currentAmount += bills[i];                                                                   // adds bill's value to the current amount
        }
    }
    return result;                                                                                       // returns list of counts
}

vector<int> calculateDynamicPlan(const vector<int>& bills, int amount) {                                 // function to calculate payment plan using dynamic programming
    vector<int> dp(amount + 1, 1000000);                                                           // initializes DP array with a high value
    vector<vector<int>> plan(amount + 1, vector<int>(bills.size(), 0));                     // initializes plan matrix
    dp[0] = 0;                                                                                           // base case: 0 amount requires 0 bills
    for (int i = 1; i <= amount; ++i) {                                                                  // calculates minimum bills required for each amount from 1 to total amount due
        for (size_t j = 0; j < bills.size(); ++j) {
            if (i >= bills[j] and dp[i - bills[j]] + 1 < dp[i]) {                                        // if using this bill results in less bills
                dp[i] = dp[i - bills[j]] + 1;                                                            // updates minimum count
                plan[i] = plan[i - bills[j]];                                                            // copy plan from the previous amount
                plan[i][j]++;                                                                            // uses one more bill of plan type
            }
        }
    }
    return plan[amount];                                                                                 // returns plan for the full amount
}

int main() {                                                                                             // main
    vector<int> denominations = {95000, 32001, 5001, 701, 101, 1};                                       // list of bill denominations
    string name;                                                                                         // variable for user name
    int taxDue;                                                                                          // variable for tax due amount
    cout << "Welcome to the IR$ of Banana Republic! " << endl;                                           // welcome message
    cout << "Please enter your name: ";                                                                  // prompts for user's name
    getline(cin, name);                                                                           // reads user's name

    cout << "What is your tax $$$ due? ";                                                                // asks for amount of tax due
    cin >> taxDue;                                                                                       // reads tax due

    vector<int> greedyPlan = calculateGreedyPlan(denominations, taxDue);                    // calculates greedy plan
    vector<int> dynamicPlan = calculateDynamicPlan(denominations, taxDue);                  // calculates dynamic plan

    cout << endl;
    printPlan("Plan 1: The Greedy Approach", denominations, greedyPlan, taxDue);                // prints greedy plan
    printPlan("Plan 2: The Dynamic Programming Approach", denominations, dynamicPlan, taxDue);  // prints dynamic plan

    int choice;                                                                                                 // variable for user's plan choice
    cout << "Which payment plan do you want to choose (1 or 2)? ";                                              // prompt to choose a plan
    cin >> choice;                                                                                              // reads the user's choice

    cout << "Dear " << name << ", thank you for paying your tax ON TIME!" << endl;
    cout << "—-----------------------------------------------------------------" << endl;

    return 0;
}

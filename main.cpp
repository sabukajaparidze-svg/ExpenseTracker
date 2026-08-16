#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<string> categories;
    vector<double> amounts;
    ifstream file("expenses.txt");

string savedCategory;
double savedAmount;

while (file >> savedCategory >> savedAmount) {
    categories.push_back(savedCategory);
    amounts.push_back(savedAmount);
}

file.close();

    int choice;

    while (true) {
        cout << "\n=== Expense Tracker ===\n";
        cout << "1. Add expense\n";
        cout << "2. View expenses\n";
        cout << "3. Show total\n";
        cout << "4. Exit\n";
        cout << "\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            string category;
            double amount;

            cout << "Enter category: ";
            cin >> category;

            cout << "Enter amount: $";
            cin >> amount;

            categories.push_back(category);
            amounts.push_back(amount);
            ofstream file("expenses.txt", ios::app);
file << category << " " << amount << "\n";
file.close();
            cout << "Expense added!\n";
        }
        else if (choice == 2) {
            cout << "\n=== Your Expenses ===\n";

            if (categories.empty()) {
                cout << "No expenses yet.\n";
            }
            else {
                for (int i = 0; i < categories.size(); i++) {
                    cout << i + 1 << ". "
                         << categories[i]
                         << " - $"
                         << amounts[i] << "\n";
                }
            }
        }
        else if (choice == 3) {
            double total = 0;

            for (double amount : amounts) {
                total += amount;
            }

            cout << "\nTotal spending: $" << total << "\n";
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}

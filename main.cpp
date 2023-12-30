#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Task {
    string description;
    bool completed;

    // Constructor to initialize a task
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "There are no tasks here yet!\n";
            return;
        }
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " (Completed)";
            }
            cout << endl;
        }
    }

    void markTaskComplete(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true; // Adjusting index to 0-based
            cout << "Task " << index << " marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1); // Adjusting index and removing
            cout << "Task " << index << " removed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

void printMenu() {
    cout << "\nTask Manager:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ToDoList myList;
    int choice = 0;

    while (true) {
        printMenu();
        cin >> choice;

        // Check for invalid input
        if(cin.fail()) {
            cin.clear(); // Clears the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the input buffer
            cout << "Invalid input. Please enter a number 1-5." << endl;
            continue;
        }

        if (choice == 5) {
            cout << "Exiting Task Manager." << endl;
            break;
        }

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore(); // ignore the newline character left in the buffer
                string description;
                getline(cin, description);
                myList.addTask(description);
                break;
            }
            case 2:
                myList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                myList.markTaskComplete(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task number to remove: ";
                cin >> index;
                myList.removeTask(index);
                break;
            }
            default:
                cout << "Invalid option. Please enter a number between 1-5." << endl;
        }
    }

    return 0;
}

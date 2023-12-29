#include <iostream>
#include <vector>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h> // For Windows system
#else
#include <unistd.h>  // For UNIX system
#endif

using namespace std;

struct Task {
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display. Your list is empty!\n";
            return;
        }
        cout << "\nYour Tasks:\n";
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description << (tasks[i].completed ? " (Completed)" : "") << endl;
        }
    }

    void markTaskComplete(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task " << index << " marked as completed." << endl;
        } else {
            cout << "Invalid task number. Please try again." << endl;
        }
    }

    void removeTask(int index) {
        if (index > 0 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task number. Please try again." << endl;
        }
    }
};

void clearScreen() {
    // Clear the screen for better readability
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

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
        clearScreen();
        myList.viewTasks();
        printMenu();
        cin >> choice;

        // Robust input handling
        while (cin.fail()) {
            cin.clear(); // Clears the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the input buffer
            cout << "Invalid input. Please enter a number 1-5: ";
            cin >> choice;
        }

        if (choice == 5) {
            cout << "Exiting Task Manager." << endl;
            break;
        }

        switch (choice) {
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Prepare for getline
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                myList.addTask(description);
                break;
            }
            case 2:
                // Viewing tasks is handled at the start of the loop
                break;
            case 3: {
                cout << "Enter task number to mark as completed: ";
                int index;
                cin >> index;
                myList.markTaskComplete(index);
                break;
            }
            case 4: {
                cout << "Enter task number to remove: ";
                int index;
                cin >> index;
                myList.removeTask(index);
                break;
            }
            default:
                cout << "Invalid option. Please enter a number between 1-5." << endl;
        }
        sleep(2); // Pause to let the user read the console output
    }

    return 0;
}

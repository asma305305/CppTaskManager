#include <iostream>
#include <vector>
#include <string>

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
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1); // Adjusting index and removing
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList myList;
    // Example usage:
    myList.addTask("Learn C++");
    myList.addTask("Make a ToDo List");
    myList.viewTasks();

    myList.markTaskComplete(1);
    myList.viewTasks();

    myList.removeTask(2); // Removes
    myList.viewTasks();

    return 0;
}

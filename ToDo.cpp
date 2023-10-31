#include <iostream>
#include <vector>

using namespace std; // This allows you to use cout, cin, vector, and other std functions directly

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Consume newline character
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter the task number to mark as completed: ";
                cin >> index;
                toDoList.markTaskCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the task number to remove: ";
                cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

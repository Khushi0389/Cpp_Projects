// main.cpp
#include "todo.h"
#include <iostream>

int main() {
    ToDoList todo;
    todo.loadFromFile("tasks.txt");

    int choice;
    std::string task;
    while (true) {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Save & Exit\nChoose: ";
        std::cin >> choice;
        std::cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::getline(std::cin, task);
                todo.addTask(task);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                int index;
                std::cout << "Enter task number to delete: ";
                std::cin >> index;
                todo.deleteTask(index);
                break;
            case 4:
                todo.saveToFile("tasks.txt");
                std::cout << "Tasks saved. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}

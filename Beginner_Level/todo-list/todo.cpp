// todo.cpp
#include "todo.h"
#include <iostream>
#include <fstream>

void ToDoList::addTask(const std::string& task) {
    tasks.push_back(task);
}

void ToDoList::viewTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

void ToDoList::deleteTask(int index) {
    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
}

void ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task << "\n";
    }
}

void ToDoList::loadFromFile(const std::string& filename) {
    tasks.clear();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        tasks.push_back(line);
    }
}

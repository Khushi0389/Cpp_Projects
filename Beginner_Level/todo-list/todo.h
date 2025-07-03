// todo.h
#ifndef TODO_H
#define TODO_H

#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;
public:
    void addTask(const std::string& task);
    void viewTasks() const;
    void deleteTask(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif

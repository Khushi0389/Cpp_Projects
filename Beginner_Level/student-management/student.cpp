#include "student.h"
#include <iostream>
#include <sstream>

Student::Student() : name(""), roll(0), marks(0.0f) {}

Student::Student(std::string name, int roll, float marks)
    : name(name), roll(roll), marks(marks) {}

void Student::input() {
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter roll: ";
    std::cin >> roll;
    std::cout << "Enter marks: ";
    std::cin >> marks;
    std::cin.ignore(); // clear input buffer
}

void Student::display() const {
    std::cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << "\n";
}

int Student::getRoll() const {
    return roll;
}

std::string Student::serialize() const {
    return name + "," + std::to_string(roll) + "," + std::to_string(marks);
}

void Student::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::getline(ss, name, ',');
    std::string rollStr, marksStr;
    std::getline(ss, rollStr, ',');
    std::getline(ss, marksStr, ',');
    roll = std::stoi(rollStr);
    marks = std::stof(marksStr);
}

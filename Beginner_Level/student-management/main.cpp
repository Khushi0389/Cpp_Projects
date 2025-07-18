#include "student.h"
#include <iostream>
#include <vector>
#include <fstream>

void saveToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& s : students) {
        file << s.serialize() << "\n";
    }
}

void loadFromFile(std::vector<Student>& students, const std::string& filename) {
    students.clear();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        Student s;
        s.deserialize(line);
        students.push_back(s);
    }
}

int main() {
    std::vector<Student> students;
    const std::string filename = "students.txt";
    loadFromFile(students, filename);

    int choice;
    while (true) {
        std::cout << "\n1. Add Student\n2. View All Students\n3. Search by Roll\n4. Save & Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            Student s;
            s.input();
            students.push_back(s);
        } else if (choice == 2) {
            for (const auto& s : students)
                s.display();
        } else if (choice == 3) {
            int r;
            std::cout << "Enter roll number to search: ";
            std::cin >> r;
            std::cin.ignore();
            bool found = false;
            for (const auto& s : students) {
                if (s.getRoll() == r) {
                    s.display();
                    found = true;
                }
            }
            if (!found)
                std::cout << "Student not found.\n";
        } else if (choice == 4) {
            saveToFile(students, filename);
            std::cout << "Data saved. Exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}

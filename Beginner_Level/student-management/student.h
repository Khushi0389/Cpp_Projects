#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int roll;
    float marks;
public:
    Student();
    Student(std::string name, int roll, float marks);

    void input();
    void display() const;

    int getRoll() const;
    std::string serialize() const;
    void deserialize(const std::string& line);
};

#endif

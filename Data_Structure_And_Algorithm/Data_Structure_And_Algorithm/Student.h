#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>
class Student
{
friend std::ostream& operator<<(std::ostream& os, const Student& student) {
	os << student.name << " " << student.score << std::endl;
	return os;
}
public:
	std::string name;
	int score;
	bool operator< (const Student& otherStudent) {
		return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
	}
};
#endif // !STUDENT_H

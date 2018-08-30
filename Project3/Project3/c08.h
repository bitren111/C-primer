#pragma once
#ifndef C08_H
#define C08_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using std::istream; using std::string;
using std::fstream; using std::ifstream; 
using std::vector; using std::istringstream;
using std::ostringstream;
void ReadFileToVector(const string&, vector<string>&);

std::iostream& rd(std::iostream& );
#endif // !C08_H

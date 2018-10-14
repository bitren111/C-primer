#pragma once
#ifndef C09_H
#define C09_H
#include<vector>
using namespace std;
#define random(a,b) (rand()%(b-a+1)+a)
int random_select(vector<int>&, const int, const int, int);
int random_partion(vector<int>&, const int, const int);
class Base;
class D1;
class D2;
#endif // !C09_H

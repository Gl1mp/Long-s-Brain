#pragma once
#include <iostream>
using namespace std;
class Point {
public:
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
private:
	int m_x;
	int m_y;
};
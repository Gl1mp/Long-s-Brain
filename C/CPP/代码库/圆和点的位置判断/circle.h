#pragma once
#include "point.h"
#include <iostream>
using namespace std;

class Circle {
public:
	void SetCenter(Point center);
	void SetR(int r);
	Point GetCenter();
	int GetR();
private:
	Point m_center;
	int m_r;
};
#include "circle.h"
#include "point.h"
#include <iostream>
using namespace std;
int Judge(Point point, Circle circle) {
	double dis = (point.GetX() - circle.GetCenter().GetX()) * (point.GetX() - circle.GetCenter().GetX())
	+ (point.GetY() - circle.GetCenter().GetY()) * (point.GetY() - circle.GetCenter().GetY());
	double rr = circle.GetR() * circle.GetR();
	if (dis < rr) return -1;
	if (dis == rr) return 0;
	return 1;
}
int main() {
	Point pt;
	pt.SetX(2);
	pt.SetY(3);
	Point center;
	center.SetX(3);
	center.SetY(5);
	Circle cir;
	cir.SetCenter(center);
	cir.SetR(2);
	std::cout << Judge(pt, cir) << std::endl;
}
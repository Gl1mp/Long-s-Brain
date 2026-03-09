#include "point.h"
#include "circle.h"
void Circle::SetCenter(Point center) {
	m_center = center;
}
void Circle::SetR(int r) {
	m_r = r;
}
Point Circle::GetCenter() {
	return m_center;
}
int Circle::GetR() {
	return m_r;
}
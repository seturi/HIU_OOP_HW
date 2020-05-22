#include <iostream>
#include "Rectangle.h"
using namespace std;

/* PointArray 기본 생성자 */
PointArray::PointArray()
{
	size = 0;
	points = new Point[size];
}

/* Point 배열과 그 크기를 받아 PointArray 생성 */
PointArray::PointArray(const Point pts[], const int size)
{
	this->size = size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = pts[i];
	}
}

/* 다른 PointArray를 인자로 받아 복사해서 PointArray생성 */
PointArray::PointArray(const PointArray& pv)
{
	size = pv.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = pv.points[i];
	}
}

/* pos를 인자로 받아 PointArray에서 pos번째 index에 해당하는 Point 반환 */
Point* PointArray::get(const int pos)
{
	return points + pos;
}
const Point* PointArray::get(const int pos) const
{
	return points + pos;
}

/* PointArray 소멸자*/
PointArray::~PointArray()
{
	delete[] points;
}

int Polygon::numPolygons = 0; // 생성된 다각형의 개수 numPolygons = 0으로 초기화

/* PointArray를 인자로 받아 numPolygons를 1 늘리면서 Polygon 생성 */
Polygon::Polygon(const PointArray& pa) 
	: points(points) {++numPolygons;}

/* Point 배열과 Point의 개수를 인자로 받아 numPolygons를 1 늘리면서 Polygon 생성 */
Polygon::Polygon(const Point points[], const int numPoints) 
	: points(points, numPoints) {++numPolygons;}

/* 인자로 받은 Point들을 배열로 반환해 직사각형의 꼭짓점으로 설정하는 함수 */
Point* pointSetting(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
	Point* parr = new Point[4];
	parr[0] = p1;
	parr[1] = p2;
	parr[2] = p3;
	parr[3] = p4;
	return parr;
}

/* Point a, b를 인자로 받아 pointSetting 함수를 이용해 각 꼭짓점을 가지는 직사각형 생성 */
Rectangle::Rectangle(const Point& a, const Point& b)
	:Polygon(pointSetting(a, Point(a.getX(), b.getY()), b, Point(b.getX(), a.getY())), 4) {	}

/* (a,b), (c,d) 점의 x, y 좌표를 인자로 받아 pointSetting 함수를 이용해 꼭짓점으로 설정해 직사각형 생성 */
Rectangle::Rectangle(const int a, const int b, const int c, const int d)
	:Polygon(pointSetting(Point(a, b), Point(a, d), Point(c, d), Point(c, b)), 4) {	}		

/* points에 저장되어있는 Point를 이용해 직사각형의 넓이를 계산해 반환 */
double Rectangle::area() const
{
	// 직사각형의 가로, 세로 길이를 계산
	double width = abs(points.get(2)->getX() - points.get(1)->getX());
	double height = abs(points.get(0)->getY() - points.get(1)->getY());

	return abs(width * height);		// 넓이에 해당하는 가로, 세로 길이의 곱을 반환
}

// main 함수
int main()
{
	/* 직사각형 1이 가질 두 꼭짓점에 해당하는 Point p1, p2 생성 */
	Point p1 = Point(2, 4);
	Point p2 = Point(4, 2);

	Rectangle rect1 = Rectangle(p1, p2);		// p1, p2를 인자로 받아 직사각형 1 생성
	cout << "--------------------직사각형 1 생성--------------------" << endl;
	cout << "직사각형 1의 넓이는 " << rect1.area() << "입니다." << endl;
	cout << "직사각형 1의 변의 개수는 " << rect1.getNumSides() << "개 입니다." << endl;

	Rectangle rect2 = Rectangle(1, 1, 2, 2);	// (1, 1), (2, 2)를 두 꼭짓점으로 하는 직사각형 2 생성
	cout << "--------------------직사각형 2 생성--------------------" << endl;
	cout << "직사각형 2의 넓이는 " << rect2.area() << "입니다." << endl;
	cout << "직사각형 2의 변의 개수는 " << rect2.getNumSides() << "개 입니다." << endl;

	cout << "직사각형의 개수는 " << rect2.getNumPolygons() << "개 입니다." << endl;
	
	return 0;
}
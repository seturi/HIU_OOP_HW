#include <iostream>
#include "Rectangle.h"
using namespace std;

/* PointArray �⺻ ������ */
PointArray::PointArray()
{
	size = 0;
	points = new Point[size];
}

/* Point �迭�� �� ũ�⸦ �޾� PointArray ���� */
PointArray::PointArray(const Point pts[], const int size)
{
	this->size = size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = pts[i];
	}
}

/* �ٸ� PointArray�� ���ڷ� �޾� �����ؼ� PointArray���� */
PointArray::PointArray(const PointArray& pv)
{
	size = pv.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
	{
		points[i] = pv.points[i];
	}
}

/* pos�� ���ڷ� �޾� PointArray���� pos��° index�� �ش��ϴ� Point ��ȯ */
Point* PointArray::get(const int pos)
{
	return points + pos;
}
const Point* PointArray::get(const int pos) const
{
	return points + pos;
}

/* PointArray �Ҹ���*/
PointArray::~PointArray()
{
	delete[] points;
}

int Polygon::numPolygons = 0; // ������ �ٰ����� ���� numPolygons = 0���� �ʱ�ȭ

/* PointArray�� ���ڷ� �޾� numPolygons�� 1 �ø��鼭 Polygon ���� */
Polygon::Polygon(const PointArray& pa) 
	: points(points) {++numPolygons;}

/* Point �迭�� Point�� ������ ���ڷ� �޾� numPolygons�� 1 �ø��鼭 Polygon ���� */
Polygon::Polygon(const Point points[], const int numPoints) 
	: points(points, numPoints) {++numPolygons;}

/* ���ڷ� ���� Point���� �迭�� ��ȯ�� ���簢���� ���������� �����ϴ� �Լ� */
Point* pointSetting(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
	Point* parr = new Point[4];
	parr[0] = p1;
	parr[1] = p2;
	parr[2] = p3;
	parr[3] = p4;
	return parr;
}

/* Point a, b�� ���ڷ� �޾� pointSetting �Լ��� �̿��� �� �������� ������ ���簢�� ���� */
Rectangle::Rectangle(const Point& a, const Point& b)
	:Polygon(pointSetting(a, Point(a.getX(), b.getY()), b, Point(b.getX(), a.getY())), 4) {	}

/* (a,b), (c,d) ���� x, y ��ǥ�� ���ڷ� �޾� pointSetting �Լ��� �̿��� ���������� ������ ���簢�� ���� */
Rectangle::Rectangle(const int a, const int b, const int c, const int d)
	:Polygon(pointSetting(Point(a, b), Point(a, d), Point(c, d), Point(c, b)), 4) {	}		

/* points�� ����Ǿ��ִ� Point�� �̿��� ���簢���� ���̸� ����� ��ȯ */
double Rectangle::area() const
{
	// ���簢���� ����, ���� ���̸� ���
	double width = abs(points.get(2)->getX() - points.get(1)->getX());
	double height = abs(points.get(0)->getY() - points.get(1)->getY());

	return abs(width * height);		// ���̿� �ش��ϴ� ����, ���� ������ ���� ��ȯ
}

// main �Լ�
int main()
{
	/* ���簢�� 1�� ���� �� �������� �ش��ϴ� Point p1, p2 ���� */
	Point p1 = Point(2, 4);
	Point p2 = Point(4, 2);

	Rectangle rect1 = Rectangle(p1, p2);		// p1, p2�� ���ڷ� �޾� ���簢�� 1 ����
	cout << "--------------------���簢�� 1 ����--------------------" << endl;
	cout << "���簢�� 1�� ���̴� " << rect1.area() << "�Դϴ�." << endl;
	cout << "���簢�� 1�� ���� ������ " << rect1.getNumSides() << "�� �Դϴ�." << endl;

	Rectangle rect2 = Rectangle(1, 1, 2, 2);	// (1, 1), (2, 2)�� �� ���������� �ϴ� ���簢�� 2 ����
	cout << "--------------------���簢�� 2 ����--------------------" << endl;
	cout << "���簢�� 2�� ���̴� " << rect2.area() << "�Դϴ�." << endl;
	cout << "���簢�� 2�� ���� ������ " << rect2.getNumSides() << "�� �Դϴ�." << endl;

	cout << "���簢���� ������ " << rect2.getNumPolygons() << "�� �Դϴ�." << endl;
	
	return 0;
}
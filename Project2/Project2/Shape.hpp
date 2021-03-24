// Shape.hpp
// Hunter Barndt, Yali Wang, Rose Peters


#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <memory>
using std::unique_ptr;
#include <string>
using std::string;
#include <stdarg.h>

const float pi = 3.14159265359;

class Shape {
public:
	using Shape_ptr = std::shared_ptr<Shape>;
	virtual ~Shape() = default;
	virtual std::string getPostScript() const = 0;
	virtual double getWidth() const = 0;
	virtual double getHeight() const = 0;
};

class Circle : public Shape {
public:
	Circle(double rad);

	double getWidth() const noexcept override;
	double getHeight() const noexcept override;

	std::string getPostScript() const override;

private:
	double _radius;
	double _height;
	double _width;

};

class Polygon : public Shape {
public:
	Polygon(int numSides, double sideLength);
	double getWidth() const noexcept override;
	double getHeight() const noexcept override;
	std::string getPostScript() const override;

private:
	double _height;
	double _width;
	int _numSides;
	double _sideLength;

};

class Triangle : public Polygon {
public:
	explicit Triangle(double sideLength) :Polygon(3, sideLength) {};
	~Triangle() override = default;
};

class Square : public Polygon {
public:
	explicit Square(double sideLength) :Polygon(4, sideLength) {};
	~Square() override = default;
};

class Rectangle : public Shape {
public:
	Rectangle(double _width, double _height);

	double getHeight() const noexcept override;
	double getWidth() const noexcept override;

	std::string getPostScript() const override;

private:
	double _height;
	double _width;
};

class Spacer : public Shape
{
public:
	Spacer(double _width, double _height);

	double getWidth() const noexcept override;
	double getHeight() const noexcept override;

	std::string getPostScript() const;

private:
	double _height;
	double _width;
};

class Scaled : public Shape
{
	Scaled(Shape_ptr shape, double fx, double fy);
	double getScaleX() const noexcept;
	double getScaleY() const noexcept;
	//Shape_ptr getShape() const noexcept
	string getPostScript() const override;
private:
	double _fx;
	double _fy;
	Shape_ptr _shape;
};

class Rotated : public Shape
{
public:
	Rotated(Shape_ptr shape, int rotationAngle);
	int getRotationAngle() const noexcept;
	string getPostScript() const override;
private:
	Shape_ptr _shape;
	int _rotationAngle;
};

class Translate
{
public:
	Translate(int x, int y);
	double getTranslateX() const noexcept;
	double getTranslateY() const noexcept;
	string getPostScript() const;
private:
	double x_trans;
	double y_trans;
}
/*
class Layered : public Shape {
public:
	Layered(int num_shapes, ...);
	string getPostScript() const override;
private:
	va_list valist;
};
*/

//class Vertical : public Shape {
//	Vertical(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
//	string getPostScript() const override;
//};

//class Horizontal : public Shape {
//	Horizontal(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
//	string getPostScript() const override;
//};
#endif //!SHAPE_HPP
// Shape.hpp
// Hunter Barndt, Yali Wang, Rose Peters


#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <memory>
using std::unique_ptr;
#include <string>
using std::string;

const float pi = 3.14159265359;

class Shape {
public:
	using Shape_ptr = std::unique_ptr<Shape>;
	virtual ~Shape() = default;
	virtual std::string getPostScript() const = 0;

};

class Circle : public Shape {
public:
	Circle(double rad);

	double getWidth() const noexcept;
	double getHeight() const noexcept;

	std::string getPostScript() const override;

private:
	double _radius;
	double _height;
	double _width;

};

class Polygon : public Shape {
public:
	Polygon(int numSides, double sideLength);
	double getWidth() const noexcept;
	double getHeight() const noexcept;
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

	double getHeight() const noexcept;
	double getWidth() const noexcept;

	std::string getPostScript() const override;

private:
	double _height;
	double _width;

};

class Spacer : public Shape
{
public:
	Spacer(double _width, double _height);

	double getWidth() const noexcept;
	double getHeight() const noexcept;

	std::string getPostScript() const;

private:
	double _height;
	double _width;
};

class Rotated : public Shape {
public:
	Rotated(std::shared_ptr<Shape> shape, int rotationAngle) : _shape(*shape), _rotationAngle(rotationAngle)
	{}
	double getWidth() const noexcept;
	double getHeight() const noexcept;
	string getPostScript() const override;
private:
	double _height;
	double _width;
	Shape& _shape;
	int _rotationAngle;
};

class Scaled : public Shape {
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

//class Layered : public Shape {
//	Layered(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
//
//	string getPostScript() const override;
//};

//class Vertical : public Shape {
//	Vertical(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
//	string getPostScript() const override;
//};

//class Horizontal : public Shape {
//	Horizontal(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
//	string getPostScript() const override;
//};
#endif //!SHAPE_HPP

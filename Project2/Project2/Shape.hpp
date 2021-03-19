// Shape.hpp
// Hunter Barndt, Yali Wang, Rose Peters


#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <memory>
using std::unique_ptr;
#include <string>
using std::string;

class Shape {
public:
	virtual ~Shape() = default;
	[[nodiscard]] virtual string getPostScript() const = 0;

};

class Circle : public Shape {
public:
	Circle(double rad);

	[[nodiscard]] double getRadius() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	double _radius;
	// unique_ptr<DrawCircleStrategy> drawing; 
};

class Polygon : public Shape {
	Polygon(int sides, double length);

	[[nodiscard]] int getSides() const noexcept;
	[[nodiscard]] double getLength() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	int _numSides;
	double _sideLength;
};

class Rectangle : public Shape {
	Rectangle(double width, double height);
	[[nodiscard]] double getWidth() const noexcept;
	[[nodiscard]] double getHeight() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	double _width;
	double _height;
};

class Spacer : public Shape {
	Spacer(double width, double height);
	[[nodiscard]] double getWidth() const noexcept;
	[[nodiscard]] double getHeight() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	double _width;
	double _height;
};


class Square : public Shape {
	Square(double sideLength);
	[[nodiscard]] double getLength() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	double _length;
};

class Triangle : public Shape {
	Triangle(double sideLength);
	[[nodiscard]] double getLength() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	double _length;
};

class Rotated : public Shape {
	Rotated(Shape shape, RotationAngle angle);
	[[nodiscard]] string getPostScript() const override;
private:
};

class Scaled : public Shape {
	Scaled(Shape shape, double fx, double fy);
	[[nodiscard]] double getScalingX() const noexcept;
	[[nodiscard]] double getScalingY() const noexcept;
	[[nodiscard]] string getPostScript() const override;

private:
	double _fx;
	double _fy;
};

class Layered : public Shape { 
	Layered(Shape shape, Shape shape2 /*, shape3, ...*/);
	[[nodiscard]] string getPostScript() const override;
};

class Vertical : public Shape {
	Vertical(Shape shape, Shape shape2 /*, shape3, ...*/);
	[[nodiscard]] string getPostScript() const override;
};

class Horizontal : public Shape {
	Horizontal(Shape shape, Shape shape2 /*, shape3, ...*/);
	[[nodiscard]] string getPostScript() const override;
};
#endif //!SHAPE_HPP
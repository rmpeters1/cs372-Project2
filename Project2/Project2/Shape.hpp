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
	// unique_ptr<DrawCircleStrategy> drawing; 
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

class Spacer // : public Shape //A Shape?? 
{ 
	public:
	Spacer( double _width, double _height);

	double getWidth() const noexcept;
	double getHeight() const noexcept;

	std::string getPostScript() const;

private:
	double _height;
	double _width;
};

class Square : public Shape {
	Square(double sideLength);
	double getLength() const noexcept;
	string getPostScript() const override;

private:
	double _length;
};

class Triangle : public Shape {
	Triangle(double sideLength);
	double getLength() const noexcept;
	string getPostScript() const override;

private:
	double _length;
};

/*class Rotated : public Shape {
	Rotated(Shape_ptr shape, RotationAngle angle);
	string getPostScript() const override;
private:
};*/

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

class Layered : public Shape {
	Layered(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
	
	string getPostScript() const override;
};

class Vertical : public Shape {
	Vertical(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
	string getPostScript() const override;
};

class Horizontal : public Shape {
		Horizontal(Shape_ptr shape, Shape shape2 /*, shape3, ...*/);
	string getPostScript() const override;
};
#endif //!SHAPE_HPP
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

#endif //!SHAPE_HPP
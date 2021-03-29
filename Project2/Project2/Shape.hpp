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
#include<vector>
using std::vector;

const float pi = 3.14159265359;

class Shape {
public:
	using Shape_ptr = std::shared_ptr<Shape>;
	virtual ~Shape() = default;
	Shape() = default;
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

class ScaledShape : public Shape
{
public:
	ScaledShape(Shape_ptr shape, double fx, double fy);
	double getWidth() const noexcept;
	double getHeight() const noexcept;
	//Shape_ptr getShape() const noexcept
	string getPostScript() const override;
private:
	double _fx;
	double _fy;
	double _width;
	double _height;
	Shape_ptr _shape;
};

class RotatedShape : public Shape
{
public:
	RotatedShape(Shape_ptr shape, int rotationAngle);
	double getWidth() const noexcept override;
	double getHeight() const noexcept override;
	string getPostScript() const override;
private:
	Shape_ptr _shape;
	int _rotationAngle;
	double _width;
	double _height;
};

class TranslatedShape : public Shape
{
public:
	TranslatedShape(int x, int y);
	double getTranslateX() const noexcept;
	double getTranslateY() const noexcept;
	string getPostScript() const override;
private:
	double x_trans;
	double y_trans;
};
/*
// Layered Shape
class LayeredShape : public Shape 
{
public:
	LayeredShape(std::vector<Shape_ptr> shapes);
	double getWidth() const noexcept override;
	double getHeight() const noexcept override;
	string getPostScript() const override;
private:
	std::vector<Shape_ptr> _shapes;
	double _width;
	double _height;
};

//Vertical Shape
class VerticalShape : public Shape 
{
public:
	VerticalShape(std::vector<Shape_ptr> shapes);
	string getPostScript() const override;
private:
	std::vector<Shape_ptr> _shapes;
};

//Horizontal Shape
class HorizontalShape : public Shape 
{
	HorizontalShape(std::vector<Shape_ptr> shapes);
	string getPostScript() const override;

private:
	std::vector<Shape_ptr> _shapes;
};

std::string getPostScript(std::vector<std::unique_ptr<Shape>> const& shapes);
*/
#endif //!SHAPE_HPP

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
using std::shared_ptr;
using std::make_shared;

const float pi = 3.14159265359;
string translate(int x, int y);

class Shape {
public:
	using Shape_ptr = std::shared_ptr<Shape>;
	virtual ~Shape() = default;
	Shape() = default;
	virtual std::string getPostScript() const = 0;
	virtual double getWidth() const = 0;
	virtual double getHeight() const = 0;
private:
	double _width = 0;
	double _height = 0;
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
	double getWidth() const noexcept;
	double getHeight() const noexcept;
	string getPostScript() const override;
private:
	Shape_ptr _shape;
	int _rotationAngle;
	double _width;
	double _height;
};

/*
class TranslatedShape : public Shape
{
public:
	TranslatedShape(int x, int y);
	double getTranslateX() const;
	double getTranslateY() const;
	string getPostScript() const override;
private:
	double x_trans;
	double y_trans;
};*/

// CompoundShape Class
class CompoundShape : public Shape
{
public:
	CompoundShape() = default;
	CompoundShape(vector<shared_ptr<Shape>> shapes);
	virtual ~CompoundShape() = default;
	virtual double getWidth() const noexcept;
	virtual double getHeight() const noexcept;
	virtual string getPostScript() const = 0;
protected:
	vector<shared_ptr<Shape>> _shapes;
	virtual string translate(shared_ptr<Shape> shape) const;
	double _width;
	double _height;
};


// Layered Shape
class LayeredShape : public CompoundShape
{
public:
	LayeredShape(vector<shared_ptr<Shape>> shapes);
	string getPostScript() const;
private:
	std::vector<Shape_ptr> _shapes;
	double _width;
	double _height;
};

//Vertical Shape
class VerticalShape : public Shape 
{
public:
	VerticalShape(vector<shared_ptr<Shape>> shapes);
protected:
	std::vector<Shape_ptr> _shapes;
	string translate(shared_ptr<Shape> shape) const;
private:
	double _width;
	double _height;
};

//Horizontal Shape
class HorizontalShape : public Shape 
{
public:
	HorizontalShape(std::vector<Shape_ptr> shapes);
protected:
	std::vector<Shape_ptr> _shapes;
	string translate(shared_ptr<Shape> shape) const;
private:
	double _width;
	double _height;
};


#endif //!SHAPE_HPP

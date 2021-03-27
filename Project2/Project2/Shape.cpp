// Shape.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include <sstream>
using std::string;
#include <cmath>
using std::cos;
using std::sin;

#include "shape.hpp"
#include <algorithm>
#include <random>
#include <functional>

// Circle Class
Circle::Circle(double rad)
{
	_radius = rad;
	_width = 2 * rad;
	_height = 2 * rad;
}

double Circle::getWidth() const noexcept
{
	return _width;
}
double Circle::getHeight() const noexcept
{
	return _height;
}

std::string Circle::getPostScript() const
{
	return std::string("%Circle\n 100 100 " + std::to_string(_radius) + " 0 360 arc stroke\n\n");
}



// Polygon Class
Polygon::Polygon(int numSides, double sideLength)
{
	_numSides = numSides;
	_sideLength = sideLength;

	if (numSides % 2 != 0)
	{
		_height = sideLength * ((1.0 + cos(pi / numSides)) / (2.0 * sin(pi / numSides)));
		_width = ((sideLength * sin(pi * (numSides - 1) / (2 * numSides))) / sin(pi / numSides));
	}
	else if (numSides % 4 == 0)
	{
		_height = sideLength * (cos(pi / numSides)) / (sin(pi / numSides));
		_width = (sideLength * (cos(pi / numSides)) / (sin(pi / numSides)));

	}
	else
	{
		_height = sideLength * ((cos(pi / numSides)) / (sin(pi / numSides)));
		_width = sideLength / sin(pi / numSides);
	}
}

double Polygon::getWidth() const noexcept
{
	return _width;
}
double Polygon::getHeight() const noexcept
{
	return _height;
}

std::string Polygon::getPostScript() const
{
	return std::string("%Polygon\n/length " + std::to_string(_sideLength) + " def\n"
		+ "/nSides " + std::to_string(_numSides) + " def\n"
		+ "/angle { 360 nSides div } def\n" + "gsave\n"
		+ "newpath\n" + "300 300 moveto\n"
		+ "0 angle 360 {\n" + "length 0 lineto\n"
		+ "length 0 translate\n" + "angle rotate\n" + "} for\n"
		+ "closepath\n" + "stroke\n" + "grestore\n");
}



// Rectangle Class
Rectangle::Rectangle(double width, double height)
{
	_width = width;
	_height = height;
}

double Rectangle::getHeight() const noexcept
{
	return _height;
}

double Rectangle::getWidth() const noexcept
{
	return _width;
}

std::string Rectangle::getPostScript() const
{
	return std::string("%Rectangle\n newpath \n 200 200 moveto\n 0 " + std::to_string(_height)
		+ " rlineto\n " + std::to_string(_width) + " 0 rlineto\n 0 "
		+ std::to_string(-_height) + " rlineto\n closepath\n stroke\n\n");
}



// Spacer Class
Spacer::Spacer(double width, double height)
{
	_width = width;
	_height = height;
}

double Spacer::getHeight() const noexcept
{
	return _height;
}

double Spacer::getWidth() const noexcept
{
	return _width;
}

std::string Spacer::getPostScript() const
{
	return std::string("%Spacer\n 255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 "
		+ std::to_string(_height) + " lineto\n " + std::to_string(_width)
		+ " 0 lineto\n 0 " + std::to_string(-_height) + " lineto\n closepath\n stroke\n");
}



// Scaling function
ScaledShape::ScaledShape(Shape_ptr shape, double fx, double fy)
{
	_fx = fx;
	_fy = fy;
	_shape = shape;
	_width = _fx * shape->getWidth();
	_height = _fy * shape->getHeight();
}

double ScaledShape::getWidth() const noexcept
{
	return _width;
}

double ScaledShape::getHeight() const noexcept
{
	return _height;
}

string ScaledShape::getPostScript() const
{
	return std::string("gsave\n" + std::to_string(_fx) + " "
		+ std::to_string(_fy) + " scale\n" + _shape->getPostScript()
		+ "grestore\n");
}



// Rotation function
RotatedShape::RotatedShape(Shape_ptr shape, int rotationAngle)
{
	if (rotationAngle == 90 || rotationAngle == 270)
	{
		_height = shape->getWidth();
		_width = shape->getHeight();
	}
	else if (rotationAngle == 180)
	{
		_width = shape->getWidth();
		_height = shape->getHeight();
	}

	_rotationAngle = rotationAngle;
	_shape = shape;
}

double RotatedShape::getHeight() const noexcept
{
	return _height;
}

double RotatedShape::getWidth() const noexcept
{
	return _width;
}

string RotatedShape::getPostScript() const
{
	return std::string("gsave\n" + std::to_string(_rotationAngle) + " rotate\n"
		+ _shape->getPostScript() + "grestore\n");
}



// TranslatedSpace class
TranslatedShape::TranslatedShape(int x, int y)
{
	x_trans = x;
	y_trans = y;
}
double TranslatedShape::getTranslateX() const noexcept
{
	return x_trans;
}
double TranslatedShape::getTranslateY() const noexcept
{
	return y_trans;
}
string TranslatedShape::getPostScript() const
{
	return std::string("%Translate\n" + std::to_string(x_trans) + " " + std::to_string(y_trans) + " translate\n");
}



// LayeredShape class
LayeredShape::LayeredShape(std::vector<Shape_ptr> shapes)
{
	_shapes = shapes;
}

string LayeredShape::getPostScript() const 
{
	std::string ps;
	for (int i = 0; i < _shapes.size(); i++)
	{
		ps += _shapes[i].get().getPostScript();
	}
	return std::string("%Layered Shape\n") + ps;
}

/*
VerticalShape::VerticalShape(std::vector<Shape_ptr>* shapes) 
{
	_shape = shape;
}
string VerticalShape::getPostScript() const {
	return std::string("%Vertical Shape\n" + _shape->getPostScript() +
		"0 " + std::to_string(_shape->getHeight()) + " translate\n");
}

HorizontalShape::HorizontalShape(std::vector<Shape_ptr>* shapes) 
{
	_shape = shape;
}
string HorizontalShape::getPostScript() const {
	return std::string("%Horizontal Shape\n" + _shape->getPostScript() +
		std::to_string(_shape->getWidth()) + "0 translate\n");
}
*/

/*
string getPostScript(std::vector<std::unique_ptr<Shape>> const& shapes)
{
	for (auto const& s : shapes) {
		return s->getPostScript();
	}
}
*/

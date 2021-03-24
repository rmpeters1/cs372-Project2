// Shape.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include <sstream>
using std::stringstream;
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
	return std::string("%Circle\n 0 0 " + std::to_string(_radius) + " 0 360 arc stroke\n\n");
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
	return std::string("%Polygon\n /length " + std::to_string(_sideLength) + " def\n"
		+ "/nSides " + std::to_string(_numSides) + " def\n"
		+ "/angle { 360 nSides div } def\n" + "gsave\n"
		+ "newpath\n" + "0 0 moveto\n"
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
	return std::string("%Rectangle\n newpath \n 0 0 moveto\n 0 " + std::to_string(_height)
		+ " rlineto\n " + std::to_string(_width) + " 0 rlineto\n 0 "
		+ std::to_string(-_height) + " rlineto\n closepath\n stroke\n \n");
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
	/*return std::string("255 255 255 setrgbcolor\n newpath\n 0 0 moveto\n 0 "
		+ std::to_string(_height) + " lineto\n " + std::to_string(_width)
		+ " 0 lineto\n 0 " + std::to_string(-_height) + " lineto\n closepath\n stroke\n");*/
	return std::string("%Spacer\n" + std::to_string(_width) + " " + std::to_string(_height) + " translate\n");
}



// Scaling function
Scaled::Scaled(Shape_ptr shape, double fx, double fy)
{
	_fx = fx;
	_fy = fy;
	_shape = shape;
}

double Scaled::getScaleX() const noexcept
{
	return _fx;
}

double Scaled::getScaleY() const noexcept
{
	return _fy;
}

string Scaled::getPostScript() const
{
	return std::string("gsave\n  " + std::to_string(_fx) + " "
		+ std::to_string(_fy) + " scale\n  " + _shape->getPostScript()
		+ " grestore");
}



// Rotation function
Rotated::Rotated(Shape_ptr shape, int rotationAngle)
{
	_rotationAngle = rotationAngle;
	_shape = shape;
}

int Rotated::getRotationAngle() const noexcept
{
	return _rotationAngle;
}

string Rotated::getPostScript() const
{
	return std::string("0 10 360 {\n   newpath\n   gsave\n     rotate\n     -" +
		std::to_string(_shape->getWidth() / 2) + " -" + std::to_string(_shape->getHeight() / 2) +
		" newpath\n moveto\n " + _shape->getPostScript() + "   grestore\n } for\n");
}



// Translate class
/*Translate::Translate(int x, int y)
{
	x_trans = x;
	y_trans = y;
}
double Translate::getTranslateX() const noexcept
{
	return x_trans;
}
double Translate::getTranslateY() const noexcept
{
	return y_trans;
}
string Translate::getPostScript() const
{
	return std::string(" " + std::to_string(getTranslateX()) + " " + std::to_string(getTranslateY()) + " translate\n \n");
}*/

/*
// Layering function
Layered::Layered(int num_shapes, ...)
{
	va_start(valist, num_shapes);
}
string Layered::getPostScript() const
{
}
*/

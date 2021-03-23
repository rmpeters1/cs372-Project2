// BasicShape.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include <sstream>
using std::stringstream;
#include <cmath>
using std::cos;
using std::sin;

#include "shape.hpp"
#include <string>
using std::string;
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
	return std::string("0 0 " + std::to_string(_radius) + " 0 360 arc stroke\n");
}



// Polygon Class

////////////////



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
	return std::string("newpath 0 0 moveto 0 " + std::to_string(_height) + " lineto " + std::to_string(_width) + " 0 lineto 0 " + std::to_string(-_height) + " lineto closepath stroke\n");
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
	return std::string("255 255 255 setrgbcolor newpath 0 0 moveto 0 " + std::to_string(_height) + " lineto " + std::to_string(_width) + " 0 lineto 0 " + std::to_string(-_height) + " lineto closepath stroke\n");
}

Scaled::Scaled(Shape_ptr shape, double fx, double fy)  {

	_fx = fx;
	_fy = fy;
	//_shape = std::move(shape);

}



double Scaled::getScaleX() const noexcept {
	return _fx;
}

double Scaled::getScaleY() const noexcept {
	return _fy;
}

string Scaled::getPostScript() const {
	return std::string(/*shape*/ + " " +std::to_string(_fx) + " " + std::to_string(_fy) + " scale \n");
}


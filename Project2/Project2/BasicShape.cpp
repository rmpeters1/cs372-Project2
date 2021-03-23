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
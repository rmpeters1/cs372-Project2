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
	[[nodiscard]] virtual int getHeight() const = 0;
	[[nodiscard]] virtual int getWidth() const = 0;
	[[nodiscard]] virtual string getPostScript() const = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape { // Circle(radius)
public:
	[[nodiscard]] int getHeight() const override;
	[[nodiscard]] int getWidth() const override;
	[[nodiscard]] string getPostScript() const override;
	Circle(unique_ptr<Shape> lhs, unique_ptr<Shape> rhs);
private:
	unique_ptr<Shape> _lhs;
	unique_ptr<Shape> _rhs;

};

class Polygon : public Shape { // Polygon(sides, length)
	[[nodiscard]] int getHeight() const override;
	[[nodiscard]] int getWidth() const override;
	[[nodiscard]] string getPostScript() const override;
	Polygon(unique_ptr<Shape> lhs, unique_ptr<Shape> rhs);
private:
	unique_ptr<Shape> _lhs;
	unique_ptr<Shape> _rhs;
};

class Rectangle : public Shape { // Rectangle(width,height)
	[[nodiscard]] int getHeight() const override;
	[[nodiscard]] int getWidth() const override;
	[[nodiscard]] string getPostScript() const override;
};

class Spacer : public Shape { // Spacer(width,height)
	[[nodiscard]] int getHeight() const override;
	[[nodiscard]] int getWidth() const override;
	[[nodiscard]] string getPostScript() const override;
};


class Square : public Shape { // Square(length)
	[[nodiscard]] int getHeight() const override;
	[[nodiscard]] int getWidth() const override;
	[[nodiscard]] string getPostScript() const override;
};

class Triangle : public Shape { // Triangle(length)
	[[nodiscard]] int getHeight() const override;
	[[nodiscard]] int getWidth() const override;
	[[nodiscard]] string getPostScript() const override;
};

class RotatedShape : public Shape { // RotatedShape(shape,angle)

	[[nodiscard]] string getPostScript() const override;
};

class ScaledShape : public Shape { // ScaledShape(shape,sx,sy)
	[[nodiscard]] string getPostScript() const override;
};

class LayeredShape : public Shape { // LayeredShape(shape1, shape2,...)
	[[nodiscard]] string getPostScript() const override;
};

class VerticalShape : public Shape { // VerticalShape(shape1, shape2,...)
	[[nodiscard]] string getPostScript() const override;
};

class HorizontalShape : public Shape { // HorizontalShape(shape1, shape2,...)
	[[nodiscard]] string getPostScript() const override;
};
#endif //!SHAPE_HPP
// draw.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include "Shape.hpp"

#include <fstream>
#include <iostream>

int main() {
	std::ofstream psfile;
	psfile.open("shapes.ps");
	
	// Container for all shapes that we will draw;
	Shapes shapes;

	// Shapes Created
	Shape_ptr c1 = std::make_unique<Circle>(2);						// Circle
	Shape_ptr s1 = std::make_unique<Square>(5);						// Square
	Shape_ptr t1 = std::make_unique<Polygon>(3);					// Triangle
	Shape_ptr ts1 = std::make_unique<TranslatedShape>(200, 200);
	Shape_ptr ts2 = std::make_unique<TranslatedShape>(500, 500);

	std::vector<Shape_ptr> layeredshapes;
	layeredshapes.push_back(c1);
	layeredshapes.push_back(t1);
	Shape_ptr ls1 = std::make_unique<LayeredShape>(layeredshapes);	// Circle on Triangle

	// Pushing back all shapes that we want drawn
	shapes.push_back(ts1);
	shapes.push_back(c1);
	shapes.push_back(s1);
	shapes.push_back(ts2);
	shapes.push_back(ls1);

	//Drawing all shapes
	for (auto const& s : shapes) {
		psfile << s.get().getPostScript(shapes);
	}

}

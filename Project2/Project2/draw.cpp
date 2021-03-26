// draw.cpp
// Hunter Barndt, Yali Wang, Rose Peters

#include "Shape.hpp"

#include <fstream>
#include <iostream>

int main() {
	std::ofstream psfile;
	psfile.open("shapes.ps");
	using Shapes = std::vector<std::unique_ptr<Shape>>;
	Shapes shapes;
	shapes.push_back(std::make_unique<Circle>(2));
	shapes.push_back(std::make_unique<Square>(5));
	

	//Drawing all shapes
	psfile << getPostScript(shapes);




	
}

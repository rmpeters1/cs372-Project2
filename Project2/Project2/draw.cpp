// draw.cpp
// Hunter Barndt, Yali Wang, Rose Peters


#include "Shape.hpp"
#include "CompoundShape.h"

#include <iostream>
using std::endl;
#include <fstream>

int main() {
	Circle c1(50);
	Spacer s1(50,50);
	Triangle t1(50);
	Rectangle r1(50, 50);
	std::ofstream psfile;
	psfile.open("shape.ps");
	psfile << c1.getPostScript() << s1.getPostScript();
	psfile << r1.getPostScript();
	psfile << std::endl << "showpage";

}
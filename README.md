# cs372-Project2
CPS to PostScript translator.
## Files
**Shape.cpp**: Run execuables to implement both basic and compound shape classes.\
**Shape.hpp**: Contains an virtual class base for all shapes and the getPostScript() function.\
**TestShape.cpp**: Contains test cases for all the shapes and our test strategy.\
**draw.cpp**: Print the shapes. \
**shapes.ps**: Contains the PostScript codes for shapes generated by draw.cpp.
## Designs
We accidentally found that since polygons including square and triangle starting from the same point on a page, they can form a good pattern. So far the shapes are not showing properly in Texmaker but they look fine in NetRun. Gonna make more designs later.

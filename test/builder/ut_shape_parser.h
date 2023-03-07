#include <gtest/gtest.h>
#include"../../src/builder/shape_parser.h"
TEST(CaseParser ,BuildCircle){
std::string input="./test/data/circle.txt";
ShapeParser parser(input);
//std::cout<<parser.gettext()<<endl;
parser.parse();
 Shape* result = parser.getShape();
 ASSERT_NEAR(3.14159,result->area(),0.001);
 delete result;
}
TEST(CaseParser ,BuildRectangle){
std::string input="./test/data/rectangle.txt";
ShapeParser parser(input);
//std::cout<<parser.gettext()<<endl;
parser.parse();
 Shape* result = parser.getShape();
 ASSERT_NEAR(3.14*4.0,result->area(),0.001);
 delete result;
}
TEST(CaseParser ,BuildTriangle){
std::string input="./test/data/triangle.txt";
ShapeParser parser(input);
parser.parse();
 Shape* result = parser.getShape();
 ASSERT_NEAR(3*4/2,result->area(),0.001);
 delete result;
}
TEST(CaseParser ,BuildEmptyCompound){
std::string input="./test/data/empty_compound.txt";
ShapeParser parser(input);
parser.parse();
 Shape* result = parser.getShape();
 ASSERT_NEAR(0,result->area(),0.001);
 delete result;
}
TEST(CaseParser ,BuildSimpleCompound){
std::string input="./test/data/simple_compound.txt";
ShapeParser parser(input);
parser.parse();
 Shape* result = parser.getShape();
 ASSERT_NEAR(3.14159+(3.14*4)+6,result->area(),0.001);
 delete result;
}
TEST(CaseParser ,BuildComplexCompound){
std::string input="./test/data/complex_compound.txt";
ShapeParser parser(input);
parser.parse();
 Shape* result = parser.getShape();
 ASSERT_NEAR((3.14159+(3.14*4)+6)*2,result->area(),0.001);
  delete result;
}
TEST(CaseParser ,ReadFileFail){
std::string input="./test/data2/complex_compound.txt";
ASSERT_ANY_THROW(ShapeParser parser(input));
}

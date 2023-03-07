#include <gtest/gtest.h>
#include"../../src/builder/scanner.h"
TEST(CaseScanner ,IgnoreIllegalWord){
std::string input = "I Circle eee ,tt{t3.14159a";
Scanner scanner(input);
std::string first = scanner.next(); 
ASSERT_EQ("Circle",first);
}
TEST(CaseScanner ,ScanCircle){
std::string input = "Circle(1.0)";
Scanner scanner(input);
//std::string first;
std::string first = scanner.next(); 
first += scanner.next(); 
first += scanner.next(); 
ASSERT_EQ("Circle()",first);
}
TEST(CaseScanner ,ScanRectangle){
std::string input = "Rectangle(1.0,2.0)";
Scanner scanner(input);
std::string first = scanner.next(); 
first += scanner.next(); 
first += scanner.next(); 
first += scanner.next(); 
ASSERT_EQ("Rectangle(,)",first);
}
TEST(CaseScanner ,ScanTriangle){
std::string input = "Triangle([3, 0] [0.000, 4.0])";
Scanner scanner(input);
std::string first = scanner.next(); 
for(int i=0;i<8;i++){
first += scanner.next(); 
}
ASSERT_EQ("Triangle([,][,])",first);
}
TEST(CaseScanner ,ScanCompound){
std::string input = "CompoundShape {}";
Scanner scanner(input);
std::string first = scanner.next(); 
first += scanner.next(); 
first += scanner.next(); 
ASSERT_EQ("CompoundShape{}",first);
}
TEST(CaseScanner ,NextThrow){
std::string input = " Circle";
Scanner scanner(input);
scanner.next();
ASSERT_ANY_THROW(scanner.next());
}
TEST(CaseScanner ,NextDouble){
std::string input = " a3.14159 aa 99 3.5";
Scanner scanner(input);
double value = scanner.nextDouble();
ASSERT_EQ(3.14159,value);
}
TEST(CaseScanner ,NextDoubleTwotimes){
std::string input = " a3.14159 aa 99 ";
Scanner scanner(input);
double value = scanner.nextDouble();
//std::cout<<value<<std::endl;
value=scanner.nextDouble();
//std::cout<<value<<std::endl;
ASSERT_EQ(99,value);
}
TEST(CaseScanner ,nextDoublethrow){
std::string input = "123";
Scanner scanner(input);
scanner.nextDouble();
ASSERT_ANY_THROW(scanner.nextDouble());
}
TEST(CaseScanner ,IsDone){
std::string input = " ";
Scanner scanner(input);
ASSERT_TRUE(scanner.isDone());
}
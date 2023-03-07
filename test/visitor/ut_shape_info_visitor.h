#include <gtest/gtest.h>
#include"../../src/visitor/shape_visitor.h"
#include"../../src/visitor/shape_info_visitor.h"
#include"../../src/circle.h"
#include"../../src/rectangle.h"
#include"../../src/triangle.h"
#include"../../src/compound_shape.h"
TEST(CaseInfoVisitor,circle){
 Circle* c1=new Circle(1.0); 
 ShapeInfoVisitor* visitor =new ShapeInfoVisitor();
visitor->visitCircle(c1);
 ASSERT_EQ(c1->info()+"\n",visitor->getResult());
delete c1 ,visitor;
}
TEST(CaseInfoVisitor,rectangle){
 Rectangle* r1 = new Rectangle(1.0,2.0);
 ShapeInfoVisitor* visitor =new ShapeInfoVisitor();
visitor->visitRectangle(r1);
 ASSERT_EQ(r1->info()+"\n",visitor->getResult());
delete r1 ,visitor;
}
TEST(CaseInfoVisitor,triangle){
TwoDimensionalVector v1(3,0);
TwoDimensionalVector v2(3,4);
 Triangle* t1 = new Triangle(v1,v2);
 ShapeInfoVisitor* visitor =new ShapeInfoVisitor();
 visitor->visitTriangle(t1);
 ASSERT_EQ(t1->info()+"\n",visitor->getResult());
delete t1 ,visitor;
}
TEST(CaseInfoVisitor,compound){
 Shape* r1 = new Rectangle(1.0,2.0);
  Shape* r2 = new Rectangle(1.0,2.0);
 Shape* c1=new Circle(1.0);
 CompoundShape* cs1 = new CompoundShape();
 CompoundShape* cs2 = new CompoundShape();
 
 cs1->addShape(r1);
 cs1->addShape(c1);
 cs2->addShape(r2);
 cs2->addShape(cs1);
 ShapeInfoVisitor* visitor =new ShapeInfoVisitor();
visitor->visitCompoundShape(cs2);
 std::cout<<visitor->getResult()<<std::endl;
 ASSERT_EQ("CompoundShape {\n  Rectangle (1.00 2.00)\n  CompoundShape {\n    Rectangle (1.00 2.00)\n    Circle (1.00)\n  }\n}\n",visitor->getResult());
delete cs2 ,visitor;
}
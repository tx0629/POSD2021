#include <gtest/gtest.h>
#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
TEST(Casecompoundshape ,area){
       CompoundShape* cs1 = new CompoundShape();
        Shape* c=new Circle(10.0);
        Shape* r=new Rectangle(3.0,4.0);
        cs1->addShape(c);
         cs1->addShape(r);

    ASSERT_NEAR(314.159+12,cs1->area(),0.001); 
    delete cs1;
}
TEST(Casecompoundshape ,perimeter){
    CompoundShape* cs1 = new CompoundShape();
        Shape* c=new Circle(5);
        Shape* r=new Rectangle(4.0,4.0);
        cs1->addShape(c);
        cs1->addShape(r);

    ASSERT_NEAR(31.415+16,cs1->perimeter(),0.001); 
    delete cs1;
}
TEST(Casecompoundshape ,info){
    CompoundShape* cs1 = new CompoundShape();
        Shape* c=new Circle(1.1);
        Shape* r=new Rectangle(3.14,4.00);
        cs1->addShape(c);
        cs1->addShape(r);

  CompoundShape* cs2 = new CompoundShape();
    Shape* c2=new Circle(12.34567);
  cs2->addShape(c2);
  cs2->addShape(cs1);

    std::cout<<cs2->info()<<std::endl;
    ASSERT_EQ("CompoundShape",cs2->info()); 
    delete cs2;
}
TEST(Casecompoundshape ,addshape){
    CompoundShape* cs1 = new CompoundShape();
        Shape* c=new Circle(10);
        Shape* r=new Rectangle(5.0,4.0);
        cs1->addShape(c);
        cs1->addShape(r);
    //ASSERT_EQ("CompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}",cs1->info()); 
     ASSERT_NEAR(20+314.159,cs1->area(),0.001);
    delete cs1;
}
TEST(Casecompoundshape ,deleteshape){
    CompoundShape* cs1 = new CompoundShape();
    Shape* c=new Circle(10);
    Shape* r=new Rectangle(5 ,4);
    CompoundShape* cs2 = new CompoundShape();
    Shape* r2=new Rectangle(5,4);
  cs1->addShape(c);
  cs1->addShape(r);
  //cs1->deleteShape(r);
  cs2->addShape(r2);
  cs2->addShape(cs1);
  cs2->deleteShape(c);
   //ASSERT_EQ("CompoundShape\n{\nCircle (1.10)\n}",cs1->info()); 
   ASSERT_NEAR(40,cs2->area(),0.001);
    delete cs2;
}
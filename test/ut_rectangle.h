#include <gtest/gtest.h>
#include "../src/rectangle.h"
#include"../src/visitor/shape_visitor.h"
#include"../src/visitor/shape_info_visitor.h"
TEST(Caserectangle ,area){
    try
    {
    Rectangle r(10.00,5.0);
     ASSERT_NEAR(50.0,r.area(),0.001);
    }
    catch(const char* msg)
    {
        ADD_FAILURE()<<msg;
    }
}
TEST(Caserectangle ,perimeter){
   try
    {
    Rectangle r(10.0,5.0);
     ASSERT_NEAR(30.0,r.perimeter(),0.001);
    }
    catch(const char* msg)
    {
        ADD_FAILURE()<<msg;
    }
}
TEST(Caserectangle ,info){
    try{
    Rectangle r(3.14159,4.126);
    ASSERT_EQ("Rectangle (3.14 4.13)",r.info());
    }
    catch(const char* msg)
    {
        ADD_FAILURE()<<msg;
    }
}
TEST(Caserectangle ,LengthNeedtobePositive){
   
    ASSERT_ANY_THROW(Rectangle r(-10.0,5.0)) ;
     
}
TEST(Caserectangle ,WidthNeedtobePositive){
    ASSERT_ANY_THROW(Rectangle r(10.0,-5.0)) ; 
}
TEST(Caserectangle ,LengthCannotEqualto0){
    ASSERT_ANY_THROW(Rectangle r(0.0,1.0)) ; 
}
TEST(Caserectangle ,WidthCannotEqualto0){
    ASSERT_ANY_THROW(Rectangle r(10.0,0.0)) ; 
}
TEST(Caserectangle ,rectangleCannotAddShape){
   Rectangle r(10.0,10.0);
   Rectangle* r2=new Rectangle(10.0,5.0);
   ASSERT_ANY_THROW( r.addShape(r2)) ;
   delete r2;
}
TEST(Caserectangle ,rectangleCannotDeleteShape){
  Rectangle r(10.0,10.0);
  Rectangle* r2=new Rectangle(10.0,5.0);
   ASSERT_ANY_THROW( r.deleteShape(r2)) ;
   delete r2;
}
TEST(Caserectangle , RectangleNullIteratorfirst){
 Rectangle r(1.0,2.0);
Iterator* n=r.createIterator();
ASSERT_ANY_THROW(n->first());
delete n;
}
TEST(Caserectangle ,RectangleNullIteratorCurrentItem){
 Rectangle r(1.0,2.0);
Iterator* n=r.createIterator();
ASSERT_ANY_THROW(n->currentItem());
delete n;
}
TEST(Caserectangle ,RectangleNullIteratorNext){
 Rectangle r(1.0,2.0);
Iterator* n=r.createIterator();
ASSERT_ANY_THROW(n->next());
delete n;
}
TEST(Caserectangle ,RectangleNullIteratorisDone){
 Rectangle r(1.0,2.0);
Iterator* n=r.createIterator();
ASSERT_EQ(true,n->isDone());
delete n;
}
TEST(Caserectangle ,RectangleAccept){
Rectangle r(1.0,2.0);
ShapeInfoVisitor* visitor =new ShapeInfoVisitor();
r.accept(visitor);
ASSERT_EQ(r.info()+"\n",visitor->getResult());
delete visitor;
}
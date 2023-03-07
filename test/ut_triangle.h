#include "../src/triangle.h"
#include <gtest/gtest.h>
#include"../src/visitor/shape_visitor.h"
#include"../src/visitor/shape_info_visitor.h"
TEST(TriangleCase,area){
    try
    {
        TwoDimensionalVector v1(3,0);
        TwoDimensionalVector v2(3,4);
        Triangle t(v1,v2);
        ASSERT_NEAR(6,t.area(),0.001);
    }
    catch(const char* msg)
    {
       ADD_FAILURE()<<msg;
    }
}
TEST(TriangleCase,perimeter){
    try
    {
        TwoDimensionalVector v1(3,0);
        TwoDimensionalVector v2(3,4);
        Triangle t(v1,v2);
        ASSERT_NEAR(12,t.perimeter(),0.001);
    }
   catch(const char* msg)
    {
       ADD_FAILURE()<<msg;
    }
    

}
TEST(TriangleCase,info){
try
{
TwoDimensionalVector v1(3.000,12.4333);
TwoDimensionalVector v2(17.568,-4.000);
Triangle t(v1,v2);
ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])",t.info());
}
catch(const char* msg)
{
  ADD_FAILURE()<<msg;
}
}
TEST(TriangleCase,TwoVectorShouldNotParallel){
    
    TwoDimensionalVector v1(0,1);
    TwoDimensionalVector v2(0,2);
    ASSERT_ANY_THROW(Triangle t(v1,v2));
}
TEST(TriangleCase ,TriangleCannotAddShape){
   TwoDimensionalVector v1(8,1);
   TwoDimensionalVector v2(4,2);
    Triangle t(v1,v2);
    Triangle* t2=new  Triangle(v1,v2);
   ASSERT_ANY_THROW( t.addShape(t2)) ;
   delete t2;
}
TEST(TriangleCase ,TriangleCannotDeleteShape){
  TwoDimensionalVector v1(8,1);
   TwoDimensionalVector v2(4,2);
    Triangle t(v1,v2);
    Triangle* t2=new  Triangle(v1,v2);
   ASSERT_ANY_THROW( t.deleteShape(t2)) ;
   delete t2;
}
TEST(TriangleCase, TriangleNullIteratorfirst){
TwoDimensionalVector v1(8,1);
 TwoDimensionalVector v2(4,2);
    Triangle t(v1,v2);
Iterator* n=t.createIterator();
ASSERT_ANY_THROW(n->first());
delete n;
}
TEST(TriangleCase,TriangleNullIteratorCurrentItem){
TwoDimensionalVector v1(8,1);
 TwoDimensionalVector v2(4,2);
    Triangle t(v1,v2);
Iterator* n=t.createIterator();
ASSERT_ANY_THROW(n->currentItem());
delete n;
}
TEST(TriangleCase ,TriangleNullIteratorNext){
TwoDimensionalVector v1(8,1);
 TwoDimensionalVector v2(4,2);
    Triangle t(v1,v2);
Iterator* n=t.createIterator();
ASSERT_ANY_THROW(n->next());
delete n;
}
TEST(TriangleCase ,TriangleNullIteratorisDone){
TwoDimensionalVector v1(8,1);
TwoDimensionalVector v2(4,2);
Triangle t(v1,v2);
Iterator* n=t.createIterator();
ASSERT_EQ(true,n->isDone());
delete n;
}
TEST(TriangleCase,TriangleAccept){
TwoDimensionalVector v1(8,1);
TwoDimensionalVector v2(4,2);
Triangle t(v1,v2);
ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
t.accept(visitor);
ASSERT_EQ(t.info()+"\n",visitor->getResult());
delete visitor;
}
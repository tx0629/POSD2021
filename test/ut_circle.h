#include <gtest/gtest.h>
#include "../src/circle.h"
#include"../src/visitor/shape_visitor.h"
#include"../src/visitor/shape_info_visitor.h"

TEST(Casecircle ,area){
    try
    {
        Circle c(10.0);
        ASSERT_NEAR(314.159,c.area(),0.001);
    }
    catch(const char* msg)
    {
       ADD_FAILURE()<<msg;
    }   
}
TEST(Casecircle ,perimeter){
    try
    {
       Circle c(5.0);
       ASSERT_NEAR(31.415,c.perimeter(),0.001);
    }
    catch(const char* msg)
    {
       ADD_FAILURE()<<msg;
    }  
}
TEST(Casecircle ,info){
    try
    {
       Circle c(1.1);
    ASSERT_EQ("Circle (1.10)",c.info());
    }
    catch(const char* msg)
    {
       ADD_FAILURE()<<msg;
    }  
    
}
TEST(Casecircle ,RadiusNeedtobePositive){
    ASSERT_ANY_THROW( Circle c(-10.0)) ;
}
TEST(Casecircle ,RadiusCannotEqualto0){
    ASSERT_ANY_THROW( Circle c(0.0)) ;
}
TEST(Casecircle ,CircleCannotAddShape){
   Circle c(10.0);
   Circle* c2=new Circle(10.0);
   ASSERT_ANY_THROW( c.addShape(c2)) ;
   delete c2;
}
TEST(Casecircle ,CircleCannotDeleteShape){
   Circle c(10.0);
   Circle* c2=new Circle(10.0);
   ASSERT_ANY_THROW( c.deleteShape(c2)) ;
   delete c2;
}
TEST(Casecircle ,CircleNullIteratorfirst){
Circle C(1.0);
Iterator* n=C.createIterator();
ASSERT_ANY_THROW(n->first());
delete n;
}
TEST(Casecircle ,CircleNullIteratorCurrentItem){
Circle C(1.0);
Iterator* n=C.createIterator();
ASSERT_ANY_THROW(n->currentItem());
delete n;
}
TEST(Casecircle ,CircleNullIteratorNext){
Circle C(1.0);
Iterator* n=C.createIterator();
ASSERT_ANY_THROW(n->next());
delete n;
}
TEST(Casecircle ,CircleNullIteratorisDone){
Circle C(1.0);
Iterator* n=C.createIterator();
ASSERT_EQ(true,n->isDone());
delete n;
}
TEST(Casecircle ,CircleAccept){
Circle C(1.0);
ShapeInfoVisitor* visitor =new ShapeInfoVisitor();
C.accept(visitor);
ASSERT_EQ(C.info()+"\n",visitor->getResult());
delete visitor;
}
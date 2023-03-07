#include"../../src/builder/shape_builder.h"
#include"../../src/shape.h"
#include"gtest/gtest.h"
TEST(CaseBuilder ,BuildCircle){
ShapeBuilder* builder = ShapeBuilder::getInstance();
    double radius = 1.0;
    builder->buildCircle(radius);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), 0.001);
    builder->reset();

    delete builder,result;

}
TEST(CaseBuilder ,BuildRectangle){
ShapeBuilder* builder = ShapeBuilder::getInstance();
    double w = 3.0;
    double h=4.0;

    builder->buildRectangle(w,h);
    Shape* result = builder->getShape();

    ASSERT_NEAR(12.0, result->area(), 0.001);
     builder->reset();
     delete builder,result;

}
TEST(CaseBuilder ,BuildTriangle){
ShapeBuilder* builder = ShapeBuilder::getInstance();
    double w = 3.0;
    double h=4.0;

    builder->buildRectangle(w,h);
    Shape* result = builder->getShape();

    ASSERT_NEAR(12.0, result->area(), 0.001);
    builder->reset();
     delete builder,result;

}
TEST(CaseBuilder ,BuildCompound){
ShapeBuilder* builder = ShapeBuilder::getInstance();
  

    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(2.0,3.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();

    ASSERT_NEAR(6.0+1.0*M_PI, result->area(), 0.001);
    builder->reset();
     delete builder,result;

}
TEST(CaseBuilder ,BuildEmptyCompound){
ShapeBuilder* builder = ShapeBuilder::getInstance();
  
    builder->buildCompoundBegin();
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();
    ASSERT_NEAR(0, result->area(), 0.001);
    builder->reset();
     delete builder,result;

}
TEST(CaseBuilder ,BuildCompoundContainOtherCompound){
ShapeBuilder* builder = ShapeBuilder::getInstance();
  
    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(2.0,3.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0,3.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();
    //std::cout<<result->createIterator()->currentItem()->area()<<endl;
    ASSERT_NEAR(6.0+1.0*M_PI,  result->createIterator()->currentItem()->area(), 0.001);
    builder->reset();
   delete builder,result;

}
TEST(CaseBuilder ,BuildCompoundContainOtherCompoundCheckAllArea){
ShapeBuilder* builder = ShapeBuilder::getInstance();
  

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(2.0,3.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0,3.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();
    ASSERT_NEAR(6.0+1.0*M_PI+9.0,  result->area(), 0.001);
     builder->reset();
   delete builder,result;

}

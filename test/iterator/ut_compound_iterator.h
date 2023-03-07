#include <gtest/gtest.h>
#include"../../src/iterator/compound_iterator.h"
#include"../../src/circle.h"
#include"../../src/rectangle.h"
#include"../../src/compound_shape.h"
TEST(CaseCompoundIterator ,CompoundIteratorfirst){
  CompoundShape* cs1 = new CompoundShape();
  Shape* c=new Circle(1.1);
  Shape* r=new Rectangle(3.14,4.00);
  std::string result;
  cs1->addShape(c);
    cs1->addShape(r);
Iterator* n= cs1->createIterator();
n->first();
ASSERT_EQ(n->currentItem(),c);
delete n,cs1;
}
TEST(CaseCompoundIterator ,CompoundIteratorCurrentItem){
CompoundShape* cs1 = new CompoundShape();
  Shape* c=new Circle(1.1);
  Shape* r=new Rectangle(3.14,4.00);
  cs1->addShape(c);
  cs1->addShape(r);
Iterator* n= cs1->createIterator();
n->next();
ASSERT_EQ(n->currentItem(),r);
delete n,cs1;
}
TEST(CaseCompoundIterator ,CompoundIteratorCurrentItemThrow){
CompoundShape* cs1 = new CompoundShape();
  Shape* c=new Circle(1.1);
  cs1->addShape(c);
Iterator* n= cs1->createIterator();
n->next();
ASSERT_ANY_THROW(n->currentItem());
delete n,cs1;
}
TEST(CaseCompoundIterator ,CompoundIteratorNext){
CompoundShape* cs1 = new CompoundShape();
  Shape* c=new Circle(1.1);
  Shape* r=new Rectangle(3.14,4.00);
  cs1->addShape(c);
    cs1->addShape(r);
Iterator* n= cs1->createIterator();

n->next();
ASSERT_EQ(n->currentItem(),r);
delete n,cs1;
}
TEST(CaseCompoundIterator ,CompoundIteratorNextThrow){
CompoundShape* cs1 = new CompoundShape();
  Shape* c=new Circle(1.1);
  cs1->addShape(c);
Iterator* n= cs1->createIterator();
n->next();
ASSERT_ANY_THROW(n->next());
delete n,cs1;
}
TEST(CaseCompoundIterator ,CompoundIteratorisDone){
  CompoundShape* cs1 = new CompoundShape();
  Shape* c=new Circle(1.1);
  cs1->addShape(c);
Iterator* n= cs1->createIterator();

n->next();
ASSERT_TRUE(n->isDone());
delete n,cs1;
}
#include <gtest/gtest.h>
#include"../../src/iterator/null_iterator.h"
TEST(CaseNullIterator ,NullIteratorfirst){
Iterator* n=new NullIterator;
ASSERT_ANY_THROW(n->first());
delete n;
}
TEST(CaseNullIterator ,NullIteratorCurrentItem){
Iterator* n=new NullIterator;
ASSERT_ANY_THROW(n->currentItem());
delete n;
}
TEST(CaseNullIterator ,NullIteratorNext){
Iterator* n=new NullIterator;
ASSERT_ANY_THROW(n->next());
delete n;
}
TEST(CaseNullIterator ,NullIteratorisDone){
Iterator* n=new NullIterator;
ASSERT_TRUE(n->isDone());
delete n;
}
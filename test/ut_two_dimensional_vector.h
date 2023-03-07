#include "../src/two_dimensional_vector.h"
TEST(Casetwodimensional ,Creation){
    TwoDimensionalVector t(10.0,12.5);
    ASSERT_NEAR(10.0,t.x(),0.001);
    ASSERT_NEAR(12.5,t.y(),0.001);
}
TEST(Casetwodimensional ,length){
    TwoDimensionalVector t(1,1.414);
    ASSERT_NEAR(1.732,t.length(),0.001);
}
TEST(Casetwodimensional ,dot){
    TwoDimensionalVector t(1,2);
     TwoDimensionalVector ve(3,4);

    ASSERT_NEAR(11,t.dot(ve),0.001);
}
TEST(Casetwodimensional ,cross){
    TwoDimensionalVector t(1,2);
     TwoDimensionalVector ve(3,4);

    ASSERT_NEAR(-2,t.cross(ve),0.001);
}
TEST(Casetwodimensional ,subtract){
    TwoDimensionalVector t(1,2);
     TwoDimensionalVector ve(3,4);

    ASSERT_NEAR(-2,t.subtract(ve).x(),0.001);
     ASSERT_NEAR(-2,t.subtract(ve).y(),0.001);
}
TEST(Casetwodimensional ,info){
    TwoDimensionalVector t(3.00,12.4333);

    ASSERT_EQ("[3.00,12.43]",t.info());
     
}
#include "shape.h"
#include "two_dimensional_vector.h"
#include "cmath"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2):_v1(vec1),_v2(vec2){
         if(_v1.cross(_v2)==0.0){
            throw "they are parallel vector,can't create triangle";
        }
     }

    double area() const override{
        if(_v1.cross(_v2)==0.0){
            throw "they are parallel vector,can't create triangle";
        }
        else{
        return abs(_v1.cross(_v2)/2);
        }
     }

    double perimeter() const override {
        if(_v1.cross(_v2)==0.0){
            throw "they are parallel vector,can't create triangle";
        }
        else{
        double  Side_length1, Side_length2, Side_length3;
        Side_length1=_v1.length();
        Side_length2=_v2.length();
        Side_length3=sqrt(pow(_v1.subtract(_v2).x(),2)+pow(_v1.subtract(_v2).y(),2));
        return Side_length1+Side_length2+Side_length3;
        }
     }

    std::string info() const override{ 
        if(_v1.cross(_v2)==0.0){
            throw "they are parallel vector,can't create triangle";
        }
        else{
        return ("Triangle ("+_v1.info()+" "+_v2.info()+")");
        }
    }
    Iterator* createIterator(){
        return new NullIterator;
    }
     void accept(ShapeVisitor* visitor) override {
        visitor->visitTriangle(this);
    }
private:
double _x1,_x2,_y1,_y2;
TwoDimensionalVector _v1 ,_v2;
};
#endif
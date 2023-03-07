#include "shape.h"
#include <cmath>
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"
#ifndef CIRCLE_H
#define CIRCLE_H
using namespace std;
class Circle : public Shape {
public:
    Circle(double radius):_radius(radius) { 
            if(_radius<=0){
            throw "radius should be positive value";
            }
    }
    double radius(){return _radius;}
    double area() const override{
        if(_radius<=0){
            throw "radius should be positive value";
        }
        else{
            return M_PI*pow(_radius,2); 
        }
        }

    double perimeter() const override{
        if(_radius<=0){
            throw "radius should be positive value";
        }
        else{
             return 2*_radius*M_PI ;
        }
       
        }

    std::string info() const override { 
        if(_radius<=0){
            throw "radius should be positive value" ;
        }
        else{
        double Process_radius;
        Process_radius=(int)((_radius* 100 + 0.5)) / (100 * 1.0);
        string Info_r=to_string(Process_radius);
        Info_r.erase(Info_r.end()-4,Info_r.end());
        return("Circle ("+Info_r+")");
        }
    }
    Iterator* createIterator(){
        return  new NullIterator;
    }
     void accept(ShapeVisitor* visitor) override {
        visitor->visitCircle(this);
    }
private:
double _radius;
};
#endif
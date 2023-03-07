#include "shape.h"
#include "cmath"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./visitor/shape_visitor.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std ;
class Rectangle : public Shape {
public: 
    Rectangle(double length, double width): _length(length) , _width(width) { 
         if(_length<=0||_width<=0){
            throw "length and width both should be positive value";
        }
        
    }
    double length() const{return _length;}
    double  width() const{return _width;} 

    double area() const override{
        if(_length<=0||_width<=0){
            throw "length and width both should be positive value";
        }
        return _length*_width ;
        }
    double perimeter() const override {
       if(_length<=0||_width<=0){
            throw "length and width both should be positive value";
        }
        else{
        return (_width+_length)*2; 
        }
        }
    
    std::string info() const override{ 
        if(_length<=0||_width<=0){
            throw "length and width both should be positive value";
        }
        else{
        double Process_length;
        double Process_width;
        Process_length = (int)((_length* 100 + 0.5)) / (100* 1.0);
        Process_width=(int)((_width* 100 + 0.5)) / (100 * 1.0);
        string Info_l=to_string(Process_length);
        Info_l.erase(Info_l.end()-4,Info_l.end());
        string Info_w=to_string(Process_width);
        Info_w.erase(Info_w.end()-4,Info_w.end());
        return ("Rectangle (" + Info_l+" "+Info_w+")");
        }
        }
        Iterator* createIterator(){
            return new NullIterator;
        }

        void accept(ShapeVisitor* visitor) override {
        visitor->visitRectangle(this);
    }


private:
    double _length;
    double _width;
};
#endif
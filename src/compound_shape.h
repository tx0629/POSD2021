#include "shape.h"
#include <list>
#include"./iterator/compound_iterator.h"
#include "./visitor/shape_visitor.h"
#pragma once
using namespace std;
class CompoundShape : public Shape {
public:
    ~CompoundShape() {
          for (list<Shape*>::const_iterator it = _compound_shape.begin(); it != _compound_shape.end(); it++) {
            delete *it;
        }
     }
     list<Shape*> get() const{return _compound_shape;}
    double area() const override { 
        double sum=0;
    for (list<Shape*>::const_iterator it = _compound_shape.begin(); it != _compound_shape.end(); it++) {
           sum+= (*it)->area();
        }
        return sum;
    }

    double perimeter() const override { 
           double sum=0;
    for (list<Shape*>::const_iterator it = _compound_shape.begin(); it != _compound_shape.end(); it++) {
           sum+= (*it)->perimeter();
        }
        return sum;
    }

    std::string info() const override {
        std::string result;
        result="CompoundShape";
        /* for (list<Shape*>::const_iterator it = _compound_shape.begin(); it != _compound_shape.end(); it++) {
            if(it !=-- _compound_shape.end()){
                result+= (*it)->info();
                result+="\n";
            }
           else{
               result+= (*it)->info();
               result+="\n}";
           }
        }*/
        return result;
     }

    Iterator* createIterator() override { 
        //ForwardIterator Forwarditbegin (_compound_shape.begin());
      //  ForwardIterator Forwarditend (_compound_shape.end());
        //Iterator* compoundit=new CompoundIterator(Forwarditbegin,Forwarditend);
       // compoundit->first();
       Iterator* compoundit=new CompoundIterator<std::list<Shape*>::iterator>(_compound_shape.begin(),_compound_shape.end());
       compoundit->first();
       return compoundit;
    }

    void addShape(Shape* shape) override { 
        _compound_shape.push_back(shape);

    }

    void deleteShape(Shape* shape) override {
        for(auto it = _compound_shape.begin() ; it != _compound_shape.end() ; it++){
            if(*it == shape){
                delete *it;
                _compound_shape.erase(it);
                break;
            }else{
                Iterator *shapeIt = (*it)->createIterator();
                if(!shapeIt->isDone())
                    (*it)->deleteShape(shape);
                delete shapeIt;
            }
        }
    }
        
        void accept(ShapeVisitor* visitor) override {
        visitor->visitCompoundShape(this);
    }
private:
 list<Shape*> _compound_shape;

};
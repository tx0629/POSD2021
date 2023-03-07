#pragma once
#include "../circle.h"
#include "../rectangle.h"
#include"../compound_shape.h"
#include"../triangle.h"
#include"../two_dimensional_vector.h"
#include<stack>
namespace{
 class ShapeBuilder {

public:

    static ShapeBuilder* getInstance() {
        if(_instance==0){
            _instance=new ShapeBuilder();
        }
        return _instance;
    }
    void buildCircle(double radius) {
         _shapes.push(new Circle(radius));
    }

    void buildRectangle(double length, double width) {
        _shapes.push(new Rectangle(length,width));
    }

    void buildTriangle(double x1, double y1, double x2, double y2) {
        TwoDimensionalVector v1(x1,y1);
        TwoDimensionalVector v2(x2,y2);
        _shapes.push(new Triangle(v1,v2));
    }

    void buildCompoundBegin() {
         _shapes.push(new CompoundShape());
    }

    void buildCompoundEnd() {
        std::list<Shape*> components;
        while(typeid(*_shapes.top()) != typeid(CompoundShape) || 
              (typeid(*_shapes.top()) == typeid(CompoundShape)
              &&!_shapes.top()->createIterator()->isDone() )){
            components.push_back(_shapes.top());
            _shapes.pop();
        }
        Shape* compound = _shapes.top();
        for(auto it = components.rbegin() ; it != components.rend() ; it++){
            compound->addShape(*it);
        }

    }
    ~ShapeBuilder(){
    }
    Shape* getShape() {
        return _shapes.top();
    }
    void reset() {
        _instance=0;
    }
    private:
     ShapeBuilder(){};
    static  ShapeBuilder* _instance;
     std::stack<Shape*> _shapes;
};
ShapeBuilder* ShapeBuilder::_instance =0;

}


// you should define a template class or type `ShapeConstraint`
#include"compound_shape.h"
#pragma once
template<class ShapeConstraint>
Shape* selectShape(Shape* shape, ShapeConstraint constraint) { 
    Iterator* it = shape->createIterator();
    Shape* result = nullptr;
    for(it->first() ; !it->isDone() ; it->next()){
        if(constraint(it->currentItem())){
            result = it->currentItem();
            break;
        }
    }
    delete it;
    return result;
}
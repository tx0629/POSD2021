// you don't have to modify this class
#include"../shape.h"
#pragma once
class Iterator {
public:
    virtual ~Iterator(){}
    
    virtual void first() = 0;

    virtual Shape* currentItem() const = 0;

    virtual void next() = 0;

    virtual bool isDone() const = 0;
};
#include "iterator.h"
#pragma once
class NullIterator : public Iterator {
public:
    void first() override { 
         throw("null_iterator can't call first");
    }

    Shape* currentItem() const override { 
        throw("null_iterator can't call next");
    }

    void next() override { 
        throw("null_iterator can't call next");
    }

    bool isDone() const override { 
        return true;
    }
};
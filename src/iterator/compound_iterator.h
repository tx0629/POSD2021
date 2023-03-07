// you should define a template class or type `ForwardIterator`
#include "iterator.h"
#include<list>
using namespace std;
#pragma once
template <class ForwardIterator >
/*class ForwardIterator
{
public:
    ForwardIterator( list<Shape*>::const_iterator it): _it(it) { }
   list<Shape*>::const_iterator iteratorget ()const
    {
     return _it;
    }
    ~ForwardIterator(){
    }
private:
   list<Shape*>::const_iterator _it;
};*/


class CompoundIterator : public Iterator{
public:
   CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin),_end(end) { 
   }

    void first() override { 
       _compoundit= _begin;
    }

    Shape* currentItem() const override { 
        if(_compoundit==_end)
        {
            throw("it is end");
        }
        else{
             return *_compoundit;
        }
       
    }
    void next() override {
        if(_compoundit==_end)
        {
            throw("it is end ,cant't next");
        }
        else
        {
            _compoundit++;
        }
     }

    bool isDone() const override { 
         if(_compoundit== _end)
        {
            return true;
        }
        else
        {
             return false;
        }
    }
private:
//list<Shape*>::const_iterator _compoundit;
ForwardIterator _begin,_compoundit;
ForwardIterator _end;
};
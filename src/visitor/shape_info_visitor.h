#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor {
   public:
    void visitCircle(Circle* circle) {
        result+=circle->info();
        result+="\n";
    }
    void visitRectangle(Rectangle* rectangle) {
        result+=rectangle->info();
        result+="\n";
    }
    void visitTriangle(Triangle* triangle) {
        result+=triangle->info();
        result+="\n";
    }
    void visitCompoundShape(CompoundShape* compoundShape) {
        result+="CompoundShape {\n";
        depth++;
     Iterator* it = compoundShape->createIterator();
           for (it->first(); !it->isDone(); it->next()) {
                for(int i=0;i<depth*2;i++){
                 result+=" "; }
            it->currentItem()->accept(this);
            }
            depth--;
            for(int i=0;i<depth*2;i++){
            result+=" ";
            }
            result+="}\n";
            delete it;
      }
    std::string getResult() {

        return result;
    }

   private:
    int depth = 0;
    std::string result = "";
    //Shape* _result;
};
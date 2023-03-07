#pragma once
#include "scanner.h"
#include "shape_builder.h"
#include <fstream>
#include<iostream>
#include <sstream>
class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) :_inputfile(filePath){
    ifstream myFile;
    myFile.open(_inputfile,ios::in);
    if(!myFile.is_open()){
        throw("file not found");
    }
     std::stringstream ss;
    ss << myFile.rdbuf();
    std::string str(ss.str());
    //cout << str;
    _filecontext=str;
    myFile.close();
    _builder=ShapeBuilder::getInstance();
    _scanner=new Scanner(_filecontext);
    }

    ~ShapeParser() {
        _builder->reset();
        delete _builder;
        delete _scanner;

    }

    void parse() {
         while(!_scanner->isDone()){
            std::string token = _scanner->next();
            if(token == "Circle"){
                _builder->buildCircle(_scanner->nextDouble());
            }else if(token == "Rectangle"){
                _builder->buildRectangle(_scanner->nextDouble(),_scanner->nextDouble());
            }else if(token == "Triangle"){
                _builder->buildTriangle(_scanner->nextDouble(),_scanner->nextDouble(),_scanner->nextDouble(),_scanner->nextDouble());
            }
            else if(token == "CompoundShape"){
                _scanner->next(); // ignore {
                _builder->buildCompoundBegin();
            }else if(token == "}"){
                _builder->buildCompoundEnd();
            }
        }

    }

    Shape* getShape() {
        return _builder->getShape();
    }
    std::string gettext() {
        return _filecontext;
    }
    private:
    ShapeBuilder* _builder;
    Scanner* _scanner;
    std::string _inputfile;
    std::string _filecontext="";
    
};

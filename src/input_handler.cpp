#include "input_handler.h"

void InputHandler::handle() {
    int _instruction=0;
    if (isContinued == true)
    {
       printEditorInstructions();
        std::cin>>_instruction;
       //_instruction=std::cin.get();
       handleEditorInstructions(_instruction);
    }
    
}

void InputHandler::printEditorInstructions() {
       std::cout<<"Please enter the following instruction number number to start building:"<<endl;
       std::cout<<"  1. 'add circle': to add a circle"<<endl;
       std::cout<<"  2. 'add rectangle': to add a rectangle"<<endl;
       std::cout<<"  3. 'add triangle': to add a triangle"<<endl;
       std::cout<<"  4. 'add compound': to add a compound"<<endl;
       std::cout<<"  5. 'save': output shape to file"<<endl;
       std::cout<<"  6. 'exit': to exit the program"<<endl;
}

void InputHandler::handleEditorInstructions(int instruction) {
    switch (instruction)
    {
    case 1:
    {
        std::cout<<"Please enter the information of circle:"<<endl;
        std::cout<<"Radius of circle:";
        double _radius=0;
        std::cin>>_radius;
        try
        {
            builder->buildCircle(_radius);
            std::cout<<"circle add\n";
             
        }
        catch(const char*)
        {
            std::cout<<"Invalid argument. Please try again\n";
            handle();
        }
        handle();
        break;
    }
    case 2:
    {
        std::cout<<"Please enter the information of rectangle:"<<endl;
        double _width=0;
        double _height=0;
        std::cout<<"Width of rectangle:";
        std::cin>>_width;
        std::cout<<"Height of rectangle:";
        std::cin>>_height;
        try
        {
            builder->buildRectangle(_width,_height);
             std::cout<<"rectangle add\n";
        }
        catch(const char*)
        {
            std::cout<<"Invalid argument. Please try again\n";
            handle();
        }
        
        handle();
        break;
    }
    case 3:
    {
        std::cout<<"Please enter the information of triangle:"<<endl;
        std::cout<<"X1 of triangle:";
        std::cout<<"Y1 of triangle:";
        std::cout<<"X2 of triangle:";
        std::cout<<"Y2 of triangle:";
        handle();
        break;
    }
     case 4:{
        std::cout<<"Please enter the following instruction number to build the compound:"<<endl;
        int _CompoundInstruction=0;
        printCompoundInstructions();
       // handleCompoundInstructions(_CompoundInstruction);
        handle();
        break;
     }
     case 5:
     {
        std::cout<<"Please enter the file name to save the shape:"<<endl;
        handle();
        break;
     }
     case 6:
     {
        isContinued = false;
        handle();
        break;
     }
    default:
    {
        std::cout<<"Invalid argument. Please try again."<<endl;
        handle();
        break;
    }    
    }
}

void InputHandler::save() {}

void InputHandler::addCircle() {}

void InputHandler::addRectangle() {}

void InputHandler::addTriangle() {}

void InputHandler::printCompoundInstructions() {
       std::cout<<"Please enter the following instruction number number to start building:"<<endl;
       std::cout<<"  1. 'add circle': to add a circle"<<endl;
       std::cout<<"  2. 'add rectangle': to add a rectangle"<<endl;
       std::cout<<"  3. 'add triangle': to add a triangle"<<endl;
       std::cout<<"  4. 'add compound': to add a compound"<<endl;
       std::cout<<"  5. 'exit': to exit the program"<<endl;
}

void InputHandler::handleCompoundInstructions(int instruction) {}

void InputHandler::addCompound() {}
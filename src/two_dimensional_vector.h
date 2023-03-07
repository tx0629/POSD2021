#ifndef TWO_DIMENSIONAL_VECTOR_H
#define TWO_DIMENSIONAL_VECTOR_H
#include "cmath"
class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y): _x(x),_y(y){}

    double x() const {return _x ;}

    double y() const { return _y ;}

    double length() const {
        double length_result;
        return length_result=sqrt((_x*_x)+(_y*_y));
    }


    double dot(TwoDimensionalVector vec) const { 
        double dot_result;
        dot_result= vec._x*_x+vec._y*_y;
        return dot_result;
    }

    double cross(TwoDimensionalVector vec) const { 
         double cross_result;
        cross_result=(_x*vec._y)-(vec._x*_y);
        return cross_result;
    }
       
    TwoDimensionalVector subtract(TwoDimensionalVector vec) const { 
        TwoDimensionalVector subtract_result((_x-vec._x),(_y-vec._y));
        return subtract_result;
    }
    std::string info() const { 
        double Process_x;
        double Process_y;
        if(_x<0){
            Process_x = (int)(((-_x)* 100 + 0.5)) / (100* 1.0);
            Process_x*=-1;
        }
        else{
             Process_x = (int)((_x* 100 + 0.5)) / (100* 1.0);
        }
        if(_y<0){
            Process_y=(int)(((-_y)* 100 + 0.5)) / (100 * 1.0);
            Process_y*=-1;
        }
        else{
             Process_y=(int)((_y* 100 + 0.5)) / (100 * 1.0);
        }
        string Info_x=to_string(Process_x);
        Info_x.erase(Info_x.end()-4,Info_x.end());
        string Info_y=to_string(Process_y);
        Info_y.erase(Info_y.end()-4,Info_y.end());
        return ("[" + Info_x+","+Info_y+"]");
        }
private:
 double _x;
 double _y;
};
#endif
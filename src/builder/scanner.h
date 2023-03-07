#pragma once
#include <string>
#include <vector>
class Scanner {
public:
    Scanner(std::string input) :_input(input){}

        std::string next() {
            std::string result = "";
            int flag=0;
            if(isDone()){
                throw("is done");
            }
                else{
                while (_pos<_input.length())
                {
                    skipWhiteSpace();
                     if(_pos>=_input.length()){
                    break;
                }
                for(auto token: tokenList) {
                        if((_input.compare(_pos, token.length(), token) == 0)&&(_pos+token.length()<=_input.length())) {
                            _pos = _pos + token.length();
                            result = token;

                            return result;
                        }
                    else{
                    }
                }
                _pos++;
                //return result;
                }
                }
            }
       


    double nextDouble() {
        std::string num = "";
        if(isDone()){
            throw("is done");
        }
        else{
        while (_pos<=_input.length())
        {
           
        skipWhiteSpace();
        while(1){
            if((_input[_pos] <= '9' && _input[_pos] >= '0') || _input[_pos] == '.') {
                num = num + _input[_pos];
                _pos++;
            }
            else{
                break;
            }
        }
        if(num!=""){
            break;
        }
        else{
            _pos++;
        }
        }
        }
         //std::cout<<num<<endl;
       return std::stod(num);
    }

    bool isDone() {
         skipWhiteSpace();
        return _pos == _input.length();

        
    }
    void skipWhiteSpace() {
        while(_input[_pos] == ' ' || _input[_pos] == '\n'||_input[_pos]=='\t') {
            _pos++;
        }
    }


private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::string _input;
    std::string::size_type _pos=0;
};
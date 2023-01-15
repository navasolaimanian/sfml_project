#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
#include<iostream>
class input{
public:
    void set_name(std::string);
    std::string get_name() const;

private:
    char command;
    std::string name;
    
};

#endif
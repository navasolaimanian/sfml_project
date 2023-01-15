#include <iostream>
#include"input.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

void input::set_name(string n)
{
    name = n;
}
string input::get_name() const
{
    return name;
}



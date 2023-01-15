#ifndef GAME_TG
#define GAME_TG
#include<iostream>
#include <array>
#include <SFML/Graphics.hpp>


#define window_x 500
#define window_y 500

class Game{
    public:
        std::array <std::array <char, 5>, 5> initBoard(); 
        std::array <std::array <char, 5>, 5> logic(sf::RectangleShape);
        int play();
        bool isWin();
        bool decrease_score();
        void file(std::string);

    private:
        std::array <std::array <char, 5>, 5> board;
        std::array <std::string, 6 > cell = {"01", "13", "21", "34", "40", "42"};
        struct Position{int x; int y;};
        Position findindex();
        int score = 20;
};

#endif
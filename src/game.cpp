#include "game.hpp"
#include <cstdlib>
#include <iostream>
#include <random>
#include <fstream>
#include "input.hpp"
#include "print.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

array <std::array <char, 5>, 5> Game::initBoard()
{
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            string code = to_string(i) + to_string(j);
            
            for (auto item : cell)
            {
                if(code == item)
                {
                    board[i][j] = 'x';
                    break;
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }
    board[0][0] = 'b';    
    board[4][4] = 'a';    
    return board;
}

int Game::play()
{
    input in;
    print p;
   
    RenderWindow window(VideoMode(window_x, window_y), "game", Style::Close); 
    p.print_text(window, "welcome to our game \n enter your name : ");

    String buffer;
    Event event;

    while (window.pollEvent(event))
    {

        switch(event.type)
        {
            case Event::EventType::TextEntered:
            {

                buffer += event.text.unicode;
                window.setTitle(buffer);
                p.print_text(window, buffer);
                break;
            }
        }    
    }
    sf::sleep(seconds(1));
    in.set_name(buffer);


    RectangleShape Wall(Vector2f(100.f, 100.f));
    p.print_board(initBoard(), window ,Wall);
    while(window.isOpen() && !isWin())
    {
       
        window.setVerticalSyncEnabled(60);
        
        Event event;

        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();

            board = logic(Wall);
            p.print_board(board, window, Wall);

            switch(event.type)
            {
                case Event::EventType::KeyPressed:
                {
                     if(!decrease_score())
                    {
                        p.print_text(window, "you lose");
                        exit(0); 
                    }
                    if(event.key.code == Keyboard::Key::Enter)
                    {
                        window.clear();
                        window.close();
                    }

                    break;
                }
            }    
        }
    }
     if(isWin())
    {
        p.print_board(board ,window, Wall);
        p.print_text(window, "you win");
        file(in.get_name());
    }

    return 0;
}

bool Game::isWin()
{
    for (size_t i = 0; i < 5; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 5; j++)      // Column traversal
        {
            if(board[i][j] == 'a')
            {
                board[1][0] = ' ';    
                return true;

            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

std::array <std::array <char, 5>, 5> Game::logic(sf::RectangleShape Wall)
{
    Position index = findindex();
    
    if(Keyboard::isKeyPressed(Keyboard::Down) && board[index.x + 1][index.y] != 'x' &&  index.x + 1 < 5)
    {
        swap(board[index.x][index.y], board[index.x + 1][index.y]);
    }
     if(Keyboard::isKeyPressed(Keyboard::Up) && board[index.x - 1][index.y] != 'x' && index.x - 1 >= 0)
    {
        swap(board[index.x][index.y], board[index.x - 1][index.y]);
    }
     if(Keyboard::isKeyPressed(Keyboard::Left) && board[index.x][index.y - 1] != 'x' && index.y - 1 >= 0)
    {
        swap(board[index.x][index.y], board[index.x][index.y - 1]);
    }
     if(Keyboard::isKeyPressed(Keyboard::Right) && board[index.x][index.y + 1] != 'x' && index.y + 1 < 5)
    {
        swap(board[index.x][index.y], board[index.x][index.y + 1]);
    }
       
    return board;
}

Game::Position Game::findindex()
{
    Position index;

    for (size_t i = 0; i < 5; i++)      // Row traversal 
    {
        for (size_t j = 0; j < 5; j++)      // Column traversal
        {
            if(board.at(i).at(j) == 'a')
            {
                index.x = i;
                index.y = j;
                return index;
            }
        }
    }

    return index;
}    

bool Game::decrease_score(){
    if(score >= 0)
    {
        score--;
        return true;
    }
    else
    {
        return false;
    }
}

void Game::file(string name){
    fstream f;
    f.open("file.txt", ios::app);
    if(!f)
    {
        cout << "error";
    }

    f << endl << "name: " << name << "    score: " << score << endl;
}


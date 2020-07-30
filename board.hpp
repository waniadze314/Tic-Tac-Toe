#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <iostream>
#include <cstring>

class board{
private:
    int moves;
    char player, winner; //gracz, zwyciezca
    char *grid; //tablica reprezentujaca stan gry

    char toggle_player();
public:
    static int size; 
    static int elements_in_line; //rozmiar planszy, ilosc symboli w linii potrzebnych do wygrania

    board();
    board(int s, int l);
    board(const board &b);
    ~board();
    void print();
    void write_state(char* state);
    void player_start();
    void computer_start();
    
    char get_grid_state(int index){
        return grid[index];
    }
    int get_number_of_moves(){
        return moves;
    }
    char get_winner(){
        return winner;
    }
    char get_player(){
        return player;
    }
    int size_of(){
    return size*size;
    }
    bool move(int index);
    bool possible_move();
    bool win();
};

#endif // BOARD_HPP_INCLUDED

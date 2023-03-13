#include "chessboard.h"
#include <iostream>


chessboard::chessboard(){
    turn = 'w';
    for (size_t i = 0; i < 8; ++i){
        for (size_t j = 0; j < 8; ++j){
            board[i][j] = ' ';
        }
    }
}

void chessboard::Print_board() const
{
    std::cout << " ";
    for (size_t i = 0; i < 8; ++i){
        std::cout << (char)('A' + i) << " ";

    }
    std::cout << std::endl;
    for (size_t i = 8; i > 0; --i){
        std::cout << i;

        for (int j = 0; j < 8; ++j){
            std::cout  << board[i - 1][j] << " ";
        }
        std::cout << std::endl;
    }

}

void chessboard :: place_figure(char letter, unsigned int number, char figure)
{
    board [number - 1][letter - 'A'] = figure;
}

char chessboard::get_turn() const{
    return turn;
}

bool chessboard :: is_empty (char letter, unsigned int number) const{
    return (board[number - 1][letter - 'A'] == ' ');
}

chessboard chessboard :: move (char letterFrom, unsigned int numberFrom, char letterTo, unsigned int numberTo) const
{
    chessboard new_board(*this);

    new_board.place_figure(letterTo, numberTo, this->board[numberFrom - 1][letterFrom - 'A']);
    new_board.place_figure(letterFrom, numberFrom, ' ');

    return new_board;
}

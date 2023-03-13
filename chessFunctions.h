#include <vector>
#include "chessboard.h"
#include <iostream>


// возвращает true, если это фигура человека, чей сейчас ход и false в противном случае
// маленькие буквы соответсуют белым фигурам, большие черным
char Own_move(char figure,  chessboard cb){
    if (figure >= 'a' && figure <= 'z' && cb.get_turn() == 'w'){
        return true;
    }
    else if (figure >= 'A' && figure <= 'Z' && cb.get_turn() == 'b')
    {
        return true;
    }
    else{
        return false;
    }
    
}


std::vector <chessboard> get_Possible_Moves (chessboard cb){
    std::vector <chessboard> result;
    for (unsigned int i = 0; i < 8; ++i){
        for (unsigned int j = 0; j < 8; ++j){

            if (cb.board[i][j] == ' ') continue;

            if (!Own_move(cb.board[i][j], cb)) continue;
            
            unsigned int number = i + 1;
            char letter = 'A' + j;
            // черные пешки
            /*
            if (cb.board[i][j] == 'P'){
                if ()
            }
            */

            // белые пешки
            if (cb.board[i][j] == 'p'){
                if (number < 8)  // можно двигаться вперед 
                {
                    if (cb.is_empty(letter, number + 1)){
                        result.push_back(cb.move(letter, number, letter, number + 1));
                    }
                }
                if (number == 2)
                {
                    if (cb.is_empty(letter, number + 2) && cb.is_empty(letter, number + 1)){
                        result.push_back(cb.move(letter, number, letter, number + 2));
                    }

                }
                
            }

        }
    }
    return result;
}


#include "chessboard_methods.h"
#include "chessFunctions.h"

int main(){
    chessboard board;
    board.place_figure('E', 2, 'p');
    board.place_figure('D', 3, 'p');
    board.place_figure('E', 4, 'P');

    board.Print_board();
    
    auto tmp = get_Possible_Moves(board);
    std::cout << std::endl;
    std::cout << "Number of combinations: " << tmp.size() << std::endl;

    for (size_t i = 0; i < tmp.size(); ++i){
        tmp[i].Print_board();
        std::cout << std::endl;
    }
    
    return 0;
}
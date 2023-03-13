#pragma once
class chessboard
{
private:
    char turn;
public:
    char board[8][8];  // turn может быть w - белый и b - черный
    chessboard();

    // вернуть чей сейчас ход 
    char get_turn() const;

    // проверяем, есть ли мат на доске ?
    bool isCheckMate() const;

    //проверяем, есть ли шах ?
    bool isCheck() const;

    // путстая ли клетка ? (true, если пустая)
    bool is_empty(char letter, unsigned int number) const;

    // отрисовка поля в консоль
    void Print_board() const;

    // установить на позицию (letter, number) фигуру, not const
    void place_figure(char letter, unsigned int number, char figure);

    // возвращает новую доску, не меняя "старый" - this жкземпляр класса
    chessboard move(char letterFrom, unsigned int numberFrom, char letterTo, unsigned int numberTo) const;


};
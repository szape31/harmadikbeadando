#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include "graphics.hpp"
#include "tic_tac_toe.hpp"
#include "ujjatek.hpp"

class JatekMester {
private:
    bool isXTurn;
    bool gameWon;
    bool gameDraw;
    char winner;
    UjJatek ujJatekGomb;

    bool checkWin(int row, int col, char player, const TicTacToe& game);
    bool checkDirection(int startRow, int startCol, int dRow, int dCol, char player, const TicTacToe& game);
    bool checkDraw(const TicTacToe& game);

public:
    JatekMester();

    char getNextPlayer();
    void switchTurn();
    bool isGameWon() const;
    bool isGameDraw() const;
    char getWinner() const;
    void checkGameStatus(int row, int col, const TicTacToe& game);
    void drawGameOverMessage() const;
    void handleEvent(const event& ev, TicTacToe& game);
    void resetGame(TicTacToe& game);
};

#endif // JATEKMESTER_HPP

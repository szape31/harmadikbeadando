#include "tic_tac_toe.hpp"
#include "jatekmester.hpp"

TicTacToe::TicTacToe() {
    for (int i = 0; i < size; ++i) {
        vector<Button> row;
        for (int j = 0; j < size; ++j) {
            row.push_back(Button(i * cell_size, j * cell_size, cell_size));
        }
        buttons.push_back(row);
    }
}

void TicTacToe::draw() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            buttons[i][j].draw();
        }
    }
}

void TicTacToe::handleEvent(const event& ev, JatekMester& jatekMester) {
    if (!jatekMester.isGameWon()) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                buttons[i][j].handleEvent(ev);
                if (buttons[i][j].isClicked() && buttons[i][j].getText() == ' ') {
                    char player = jatekMester.getNextPlayer();
                    buttons[i][j].setText(player);
                    jatekMester.checkGameStatus(i, j, *this);
                    jatekMester.switchTurn();
                }
            }
        }
    }
}

char TicTacToe::getButtonText(int row, int col) const {
    return buttons[row][col].getText();
}

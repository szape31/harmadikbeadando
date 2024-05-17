#include "jatekmester.hpp"

JatekMester::JatekMester()
    : isXTurn(true), gameWon(false), gameDraw(false), winner(' '),
      ujJatekGomb(TicTacToe::XX / 2 - 50, TicTacToe::YY / 2 + 50, 100, 40) {}

char JatekMester::getNextPlayer() {
    return isXTurn ? 'X' : 'O';
}

void JatekMester::switchTurn() {
    isXTurn = !isXTurn;
}

bool JatekMester::isGameWon() const {
    return gameWon;
}

bool JatekMester::isGameDraw() const {
    return gameDraw;
}

char JatekMester::getWinner() const {
    return winner;
}

void JatekMester::checkGameStatus(int row, int col, const TicTacToe& game) {
    char player = getNextPlayer();
    if (checkWin(row, col, player, game)) {
        gameWon = true;
        winner = player;
        ujJatekGomb.setVisible(true);
    } else if (checkDraw(game)) {
        gameDraw = true;
        ujJatekGomb.setVisible(true);
    }
}

bool JatekMester::checkWin(int row, int col, char player, const TicTacToe& game) {
    return checkDirection(row, col, 0, 1, player, game) ||
           checkDirection(row, col, 1, 0, player, game) ||
           checkDirection(row, col, 1, 1, player, game) ||
           checkDirection(row, col, 1, -1, player, game);
}

bool JatekMester::checkDirection(int startRow, int startCol, int dRow, int dCol, char player, const TicTacToe& game) {
    int count = 1;

    for (int i = 1; i < 5; ++i) {
        int newRow = startRow + i * dRow;
        int newCol = startCol + i * dCol;
        if (newRow < 0 || newRow >= TicTacToe::size || newCol < 0 || newCol >= TicTacToe::size || game.getButtonText(newRow, newCol) != player) {
            break;
        }
        count++;
    }

    for (int i = 1; i < 5; ++i) {
        int newRow = startRow - i * dRow;
        int newCol = startCol - i * dCol;
        if (newRow < 0 || newRow >= TicTacToe::size || newCol < 0 || newCol >= TicTacToe::size || game.getButtonText(newRow, newCol) != player) {
            break;
        }
        count++;
    }

    return count >= 5;
}

bool JatekMester::checkDraw(const TicTacToe& game) {
    for (int i = 0; i < TicTacToe::size; ++i) {
        for (int j = 0; j < TicTacToe::size; ++j) {
            if (game.getButtonText(i, j) == ' ') {
                return false;
            }
        }
    }
    return true;
}

void JatekMester::drawGameOverMessage() const {
    if (gameWon) {
        gout << font("LiberationSans-Regular.ttf", 30);
        std::string winnerText = (winner == 'X') ? "First player (X) wins!" : "Second player (O) wins!";
        int textWidth = gout.twidth("Game Over");
        int textWidthWinner = gout.twidth(winnerText);
        gout << move_to((TicTacToe::XX - textWidth) / 2, TicTacToe::YY / 2 - 30) << color(255, 0, 0) << text("Game Over");
        gout << move_to((TicTacToe::XX - textWidthWinner) / 2, TicTacToe::YY / 2 + 10) << color(255, 0, 0) << text(winnerText);
    } else if (gameDraw) {
        gout << font("LiberationSans-Regular.ttf", 30);
        int textWidth = gout.twidth("Game Over");
        int textWidthDraw = gout.twidth("It's a draw!");
        gout << move_to((TicTacToe::XX - textWidth) / 2, TicTacToe::YY / 2 - 30) << color(255, 0, 0) << text("Game Over");
        gout << move_to((TicTacToe::XX - textWidthDraw) / 2, TicTacToe::YY / 2 + 10) << color(255, 0, 0) << text("It's a draw!");
    }
    ujJatekGomb.draw();
}

void JatekMester::handleEvent(const event& ev, TicTacToe& game) {
    if (ujJatekGomb.isClicked()) {
        resetGame(game);
    }
    ujJatekGomb.handleEvent(ev);
}

void JatekMester::resetGame(TicTacToe& game) {
    isXTurn = true;
    gameWon = false;
    gameDraw = false;
    winner = ' ';
    ujJatekGomb.reset();
    game = TicTacToe();
}

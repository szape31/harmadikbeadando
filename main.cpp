#include "graphics.hpp"
#include "tic_tac_toe.hpp"
#include "jatekmester.hpp"

using namespace genv;

int main() {
    gout.open(TicTacToe::XX, TicTacToe::YY);
    gin.timer(40);

    TicTacToe game;
    JatekMester jatekMester;

    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_timer) {
            gout << color(0, 0, 0) << move_to(0, 0) << box(TicTacToe::XX, TicTacToe::YY);
            game.draw();
            jatekMester.drawGameOverMessage();
            gout << refresh;
        }
        jatekMester.handleEvent(ev, game);
        game.handleEvent(ev, jatekMester);
    }

    return 0;
}

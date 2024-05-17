#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include "graphics.hpp"
#include "button.hpp"
#include <vector>

class JatekMester;

using namespace genv;
using namespace std;

class TicTacToe {
private:
    vector<vector<Button>> buttons;

public:
    static const int size = 15;
    static const int cell_size = 40;
    static const int XX = size * cell_size;
    static const int YY = size * cell_size;

    TicTacToe();
    void draw() const;
    void handleEvent(const event& ev, JatekMester& jatekMester);
    char getButtonText(int row, int col) const;
};

#endif // TIC_TAC_TOE_HPP

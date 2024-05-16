#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "graphics.hpp"

using namespace genv;

class Button {
private:
    int x, y, size;
    bool clicked;

public:
    Button(int x, int y, int size);

    void draw();
    void handleEvent(const event& ev);
    bool isClicked() const;
    void reset();
};

#endif // BUTTON_H

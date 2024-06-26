#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "graphics.hpp"

using namespace genv;

class Button {
private:
    int x, y, size;
    bool clicked;
    char texts;

public:
    Button(int x, int y, int size);

    void draw() const;
    void handleEvent(const event& ev);
    bool isClicked() const;
    void reset();
    void setText(char t);
    char getText() const;
};

#endif // BUTTON_HPP

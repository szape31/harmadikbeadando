#include "button.hpp"

Button::Button(int x, int y, int size) : x(x), y(y), size(size), clicked(false) {}

void Button::draw() {
    gout << move_to(x, y) << color(200, 200, 200) << box(size, size);
    if (clicked) {
        gout << font("LiberationSans-Regular.ttf", size - 10);
        int textWidth = gout.twidth("X");
        int textHeight = size - 10;
        gout << move_to(x + 10, y) << color(0, 0, 0) << text("X");
    }
}

void Button::handleEvent(const event& ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (ev.pos_x > x && ev.pos_x < x + size && ev.pos_y > y && ev.pos_y < y + size) {
            clicked = true;
        }
    }
}

bool Button::isClicked() const {
    return clicked;
}

void Button::reset() {
    clicked = false;
}

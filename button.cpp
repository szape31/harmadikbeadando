#include "button.hpp"

Button::Button(int x, int y, int size) : x(x), y(y), size(size), clicked(false), texts(' ') {}

void Button::draw() const {
    gout << move_to(x, y) << color(0, 0, 0) << box(size, size);
    gout << move_to(x + 1, y + 1) << color(200, 200, 200) << box(size - 2, size - 2);
    if (texts != ' ') {
        gout << font("LiberationSans-Regular.ttf", size - 10);

        gout << move_to(x + 10, y) << color(0, 0, 0) << text(std::string(1, texts));
    }
}

void Button::handleEvent(const event& ev) {
    if (ev.type == ev_mouse && ev.button == btn_left && !clicked) {
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

void Button::setText(char t) {
    texts = t;
}

char Button::getText() const {
    return texts;
}

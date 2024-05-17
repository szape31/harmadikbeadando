#include "ujjatek.hpp"

UjJatek::UjJatek(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), visible(false), clicked(false) {}

void UjJatek::draw() const {
    if (visible) {
        gout << move_to(x, y) << color(0, 0, 200) << box(width, height);
        gout << move_to(x + 20, y ) << color(255, 255, 255) << text("New");
    }
}

void UjJatek::handleEvent(const event& ev) {
    if (visible && ev.type == ev_mouse && ev.button == btn_left) {
        if (ev.pos_x > x && ev.pos_x < x + width && ev.pos_y > y && ev.pos_y < y + height) {
            clicked = true;
        }
    }
}

void UjJatek::setVisible(bool v) {
    visible = v;
}

bool UjJatek::isClicked() const {
    return clicked;
}

void UjJatek::reset() {
    clicked = false;
    visible = false;
}

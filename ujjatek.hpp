#ifndef UJJATEK_HPP
#define UJJATEK_HPP

#include "graphics.hpp"

using namespace genv;

class UjJatek {
private:
    int x, y, width, height;
    bool visible;
    bool clicked;

public:
    UjJatek(int x, int y, int width, int height);

    void draw() const;
    void handleEvent(const event& ev);
    void setVisible(bool v);
    bool isClicked() const;
    void reset();
};

#endif // UJJATEK_HPP

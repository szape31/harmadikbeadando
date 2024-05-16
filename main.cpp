#include "graphics.hpp"
#include "button.hpp"

using namespace genv;

const int XX = 800;
const int YY = 800;

int main() {
    gout.open(XX, YY);
    gin.timer(40);

    Button button(100, 100, 40);

    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_timer) {
            gout << color(0, 0, 0) << move_to(0, 0) << box(XX, YY);
            button.draw();
            gout << refresh;
        }
        button.handleEvent(ev);
    }

    return 0;
}

#include "main.hpp"

using namespace tankwar;

int main()
{
    TankT80 t1;
    TankT80 t2;
    t1.show_all();
    t1.speed_up().speed_up();
    t1.forward();
    t1.show_all();


    return 0;
}
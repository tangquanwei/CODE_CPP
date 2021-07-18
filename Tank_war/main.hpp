#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <iostream>

using namespace std;

namespace tankwar
{
    class Tank // 抽象
    {
    private:
        unsigned int speed;
        int life;
        unsigned int experience;

    public:
        virtual void fire_cannon(Tank &t) = 0; // 发射炮弹
        virtual void fire_bullet(Tank &t) = 0; // 发射子弹
        virtual int get_life() = 0;
        virtual bool is_alive() = 0;
    };
    class Cartridge // 各种炮弹
    {
    public:
        unsigned int harm;
        float cool_time;
        unsigned int number{10};
        Cartridge(unsigned int h = 1, float c = 0.1) : harm(h), cool_time(c) {}
    };
    class Ability //技能
    {
    private:
        const float cool_time{30};

    public:
        void add_life();
        void add_speed();
        void add_harm();
    };
    class Location
    {
    private:
        int x, y, speed;

    public:
        Location(int x = 0, int y = 0) : x(x), y(y) { speed = 1; }
        Location &forward()
        {
            x += speed;
            return *this;
        }
        Location &backward()
        {
            x -= speed;
            return *this;
        }
        Location &turn_right()
        {
            y += speed;
            return *this;
        }
        Location &turn_left()
        {
            y -= speed;
            return *this;
        }
        Location &speed_up()
        {
            ++speed;
            return *this;
        }
        Location &speed_down()
        {
            --speed;
            return *this;
        }
        int get_x() const { return x; }
        int get_y() const { return y; }
    };
    class TankT80 : public Tank, public Location
    {
    private:
        const unsigned int size{2};
        const char color[6]{"green"};
        int life;
        unsigned int experience;
        Cartridge cannon{10 + experience, 1};
        Cartridge bullet{1 + experience};
        int get_life() { return life; }

    public:
        TankT80(unsigned int speed = 10, unsigned int life = 100, unsigned int experience = 0, int x = 1, int y = 3) : Location(x, y), life(life), experience(experience) {}
        void fire_cannon(Tank &t) override
        {
            t.get_life() - cannon.harm;
        }
        void fire_bullet(Tank &t) override
        {
            t.get_life() - bullet.harm;
        }
        bool is_alive() override { return life > 0 ? true : false; }
        void show_all() const
        {
            cout << "life = " << life
                 << "\nexperience = " << experience
                 << "\ncannon = " << cannon.harm
                 << "\nbullet = " << bullet.harm
                 << "\nlocation(" << get_x() << ',' << get_y() << ')'
                 << endl;
        }
    };
}

#endif
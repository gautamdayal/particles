#include "particle.h"
#include <iostream>


Particle::Particle() {
    pos.x = GetRandomValue(1, kScreenWidth-1);
    pos.y = GetRandomValue(1, kScreenHeight-1);

    vel.v_x = GetRandomValue(5, 20);
    vel.v_y = GetRandomValue(5, 20);
}

void Particle::UpdateParticle() {
    std::cout << "x before" << pos.x << std::endl;
    pos.x += vel.v_x;
    std::cout << "x after" << pos.x << std::endl;
    pos.y += vel.v_y;
    if (pos.x > kScreenWidth || pos.x < 0) {
        std::cout << "bounds" << std::endl;
        vel.v_x *= -1;
    }
    if (pos.y > kScreenHeight || pos.y < 0) {
        vel.v_y *= -1;
    }

}

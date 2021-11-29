#include "particle.h"
#include <iostream>


Particle::Particle(int in_radius) {
    radius = in_radius;
    pos.x = GetRandomValue(1, kScreenWidth-1);
    pos.y = GetRandomValue(1, kScreenHeight-1);

    vel.x = GetRandomValue(5, 10);
    vel.y = GetRandomValue(5, 10);

    acc.x = 0;
    acc.y = 0;
}

void Particle::UpdateParticle() {
    if (pos.x > kScreenWidth || pos.x < 0) {
        vel.x *= -1;
    }
    if (pos.y > kScreenHeight || pos.y < 0) {
        vel.y *= -1;
    }
    pos.x += vel.x;
    pos.y += vel.y;

    vel.x += acc.x;
    vel.y += acc.y;
}

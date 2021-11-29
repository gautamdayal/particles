#include "raylib.h"
#include <cmath>

const int kScreenWidth = 800;
const int kScreenHeight = 450;

struct Position {
    int x;
    int y;
};

struct Velocity {
    int x;
    int y;
};

struct Acceleration {
    int x;
    int y;
}

struct Particle {
    int radius;
    Position pos;
    Velocity vel;
    Acceleration acc;
    Particle(int in_radius);
    void UpdateParticle();
    friend bool IsCollide(Particle &p1, Particle &p2);
};

float Distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(y2-y1, 2) + pow(x2-x1, 2));
}

bool IsCollide(Particle &p1, Particle &p2) {
    return Distance(p1.x, p1.y, p2.x, p2.y) <= p1.radius + p2.radius;
}

#include "raylib.h"

const int kScreenWidth = 800;
const int kScreenHeight = 450;

struct Position {
    int x;
    int y;
};

struct Velocity {
    int v_x;
    int v_y;
};

struct Particle {
    Position pos;
    Velocity vel;
    Particle(Position p, Velocity v);
    Particle();
    void UpdateParticle();
};

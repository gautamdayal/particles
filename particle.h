#include "raylib.h"
#include <cmath>
#include <iostream>
#include <vector>

const int kScreenWidth = 1200;
const int kScreenHeight = 800;

struct Position {
    int x;
    int y;
};

struct Velocity {
    int x;
    int y;
};

struct Acceleration {
    double x;
    double y;
};

struct Momentum {
    double x;
    double y;
};

struct Particle {
    int id;
    int radius;
    Position pos;
    Velocity vel;
    Acceleration acc;
    Momentum p;
    Particle(int in_radius);
    Particle(int in_id, int in_radius);
    void UpdateParticle();
    void DrawParticle();

    std::vector<Position> path_pixels;
    void DrawPath();
};

struct ParticleSystem {
    int particle_num;
    std::vector<Particle> particles;
    void AddParticle();
    void DrawSystem();
    void UpdateSystem();
    ParticleSystem(int in_num, int in_rad);
};

float Distance(int x1, int y1, int x2, int y2);
bool IsCollide(Particle &p1, Particle &p2);

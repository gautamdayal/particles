#include "particle.h"
// Image frog = LoadImage("frog.png");
// Texture2D frog_texture = LoadTextureFromImage(frog);
Particle::Particle(int in_radius) {
    radius = in_radius;
    pos.x = GetRandomValue(1, kScreenWidth-1);
    pos.y = GetRandomValue(1, kScreenHeight-1);

    vel.x = GetRandomValue(3, 7);
    vel.y = GetRandomValue(3, 7);

    acc.x = 0;
    acc.y = 0;
}

Particle::Particle(int in_id, int in_radius) {
    id = in_id;
    radius = in_radius;
    pos.x = GetRandomValue(1, kScreenWidth-1);
    pos.y = GetRandomValue(1, kScreenHeight/2);

    vel.x = 100 / (double)radius;
    vel.y = 100 / (double)radius;

    acc.x = 0;
    acc.y = 1;
}

void Particle::UpdateParticle() {
    if (pos.x + radius > kScreenWidth || pos.x - radius < 0) {
        vel.x *= -1;
    }
    if (pos.y + radius > kScreenHeight || pos.y - radius < 0) {
        vel.y *= -1;
    }
    pos.x += vel.x;
    pos.y += vel.y;

    // vel.x += acc.x;
    // vel.y += acc.y;

    if (IsKeyDown(KEY_SPACE)) {
        path_pixels.push_back(pos);
        DrawPath();
    } else {
        path_pixels = {};
    }
}

// draws a circle to enter the bouncing arena
void Particle::DrawParticle() {
    DrawCircle(pos.x, pos.y, radius, (Color){0, 0, 0, 150});
    // DrawTexture(frog_texture, pos.x, pos.y, (Color) {30, 30, 30, 150});
}


void Particle::DrawPath() {
    for (Position pixel : path_pixels) {
        DrawCircle(pixel.x, pixel.y, 1, (Color) {0, 0, 0, 255});
    }
}

// adds many bouncers(circles/particles) to the club(pun) of the same size
ParticleSystem::ParticleSystem(int in_num, int in_rad) {
    particle_num = in_num;
    for (int i = 0; i < particle_num; i++) {
        Particle to_add = Particle(particles.size(), in_rad);
        particles.push_back(to_add);
    }
}

//  actually draws the circles computed by the previous fucktion
void ParticleSystem::DrawSystem() {
    for (Particle &p : particles) {
        p.DrawParticle();
    }
}

// updates the position of each circle after the new position is calculated
void ParticleSystem::UpdateSystem() {
    for (Particle &p : particles) {
        p.UpdateParticle();
    }
}

// this calculates the distance between 2 particles
float Distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(y2-y1, 2) + pow(x2-x1, 2));
}

// calculates the collision between a particle and a wall
bool IsCollide(Particle &p1, Particle &p2) {
    return Distance(p1.pos.x, p1.pos.y, p2.pos.x, p2.pos.y) < p1.radius + p2.radius;
}

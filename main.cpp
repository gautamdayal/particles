#include "particle.h"
#include <vector>
#include <iostream>

int main(void) {
    std::vector<Particle> cloud;
    for (int i = 0; i < 5; i++) {
        Particle to_add = Particle();
        cloud.push_back(to_add);
    }
    InitWindow(kScreenWidth, kScreenHeight, "Multiple Particles");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        for (Particle p : cloud) {
            p.UpdateParticle();
        }
        BeginDrawing();
            ClearBackground((Color){ 245, 245, 245, 255 } );
            for (Particle p : cloud) {
                DrawCircle(p.pos.x, p.pos.y, 10, (Color){30, 30, 30, 150});
            }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

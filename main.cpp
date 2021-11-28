#include "particle.h"
#include <vector>
#include <iostream>

int main(void) {
    InitWindow(kScreenWidth, kScreenHeight, "Multiple Particles");
    Particle p = Particle();
    Particle q = Particle();
    Particle r = Particle();
    Particle s = Particle();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        p.UpdateParticle();
        q.UpdateParticle();
        r.UpdateParticle();
        s.UpdateParticle();

        BeginDrawing();
            ClearBackground((Color){ 245, 245, 245, 255 } );

            DrawCircle(p.pos.x, p.pos.y, 10, (Color){30, 30, 30, 150});
            DrawCircle(q.pos.x, q.pos.y, 10, (Color){30, 30, 30, 150});
            DrawCircle(r.pos.x, r.pos.y, 10, (Color){30, 30, 30, 150});
            DrawCircle(s.pos.x, s.pos.y, 10, (Color){30, 30, 30, 150});


        EndDrawing();
    }
    CloseWindow();
    return 0;
}

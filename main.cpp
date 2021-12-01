#include "particle.h"

int main(void) {
    ParticleSystem s = ParticleSystem(20, 7);
    ParticleSystem s1 = ParticleSystem(8, 14);
    ParticleSystem s2 = ParticleSystem(4, 50);


    InitWindow(kScreenWidth, kScreenHeight, "Multiple Particles");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // s.UpdateSystem();
        // s1.UpdateSystem();
        s2.UpdateSystem();

        BeginDrawing();
            ClearBackground((Color){ 245, 245, 245, 255 } );
            // s.DrawSystem();
            // s1.DrawSystem();
            s2.DrawSystem();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

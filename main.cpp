#include "particle.h"

int main(void) {
    ParticleSystem s = ParticleSystem(20, 7);
    ParticleSystem s1 = ParticleSystem(8, 14);
    ParticleSystem s2 = ParticleSystem(4, 50);
    

    InitWindow(kScreenWidth, kScreenHeight, "Multiple Particles");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        s.UpdateSystem();
        s1.UpdateSystem();
        s2.UpdateSystem();


        // for (Particle &p1 : s.particles) {
        //     for (Particle& p2 : s.particles) {
        //         if (p1.id != p2.id && IsCollide(p1, p2)) {
        //             p1.vel.x = 0;
        //             p1.vel.y = 0;
        //         }
        //     }
        // }
        BeginDrawing();
            ClearBackground((Color){ 245, 245, 245, 255 } );
            s.DrawSystem();
            s1.DrawSystem();
            s2.DrawSystem();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

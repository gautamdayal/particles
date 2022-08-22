/** 
 * @file main.cpp
 * @brief has main control flow
 * 
 * This has the main flowchart of the entire program ifykwim
 */ 

#include "particle.h"

int main(void) {
    ParticleSystem s = ParticleSystem(15, 7);
    ParticleSystem s1 = ParticleSystem(6, 14);
    ParticleSystem s2 = ParticleSystem(3, 50);


    InitWindow(kScreenWidth, kScreenHeight, "Multiple Particles");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        s.UpdateSystem();
        s1.UpdateSystem();
        s2.UpdateSystem();

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

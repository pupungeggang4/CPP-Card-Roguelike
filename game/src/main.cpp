#include "includes.hpp"

int loop() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, Raylib!", 320, 200, 20, DARKGRAY);
    EndDrawing();
}

#ifdef __EMSCRIPTEN__
void loopGame() {
    loop();
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
void startGame() {
    //initGame(&gameVar);
    InitWindow(800, 600, "Temp");
    emscripten_set_main_loop(loopGame, 0, 1);
}
}
#endif

int main(int argc, char** argv) {
    #ifdef __EMSCRIPTEN__
    EM_ASM({
        try { FS.mkdir('/save'); } catch(e) {}
        FS.mount(FS.filesystems.IDBFS, {}, '/save');
        Module.print("IDBFS Mount complete!");
        FS.syncfs(true, function(err) {
            if (err) Module.print(err);
            else Module.print("Load complete!");
            _startGame();
        });
    });
    #else
    //initGame(&gameVar);
    InitWindow(800, 600, "Temp");
    while(!WindowShouldClose()) {
        loop();
    }
    //disposeAsset(&gameVar);
    #endif
    return 0;
}

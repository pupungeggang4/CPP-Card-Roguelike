#include "includes.hpp"
#include "game.hpp"

Game* game;

#ifdef __EMSCRIPTEN__
void loopGame() {
    game->loop();
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
void startGame() {
    game->init();
    emscripten_set_main_loop(loopGame, 0, 1);
}
}
#endif

int main(int argc, char** argv) {
    game = new Game();
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
    game.init();
    while(game.running) {
        game.loop();
    }
    delete game;
    #endif
    return 0;
}

#pragma once

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <cstdlib>

#include <vector>
#include <unordered_map>
#include <memory>

using std::shared_ptr;
using std::make_shared;

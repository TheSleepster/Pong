#pragma once

#ifndef define

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include <memory>
#include <cassert>
#include <cstdint>
#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>

#define global static
#define local_persist static
#define internal static

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef float real16;
typedef double real32;

typedef Vector2 v2;
typedef Vector3 v3;
typedef Vector4 v4;

void pongDraw();
void update();
void checkInput();
void handleCollision();
void handleUI();
void resetBall();

#endif

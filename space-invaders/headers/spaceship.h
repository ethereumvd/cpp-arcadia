#pragma once

#include "raylib.h"

class Spaceship {

public:
  Spaceship();
  ~Spaceship();
  void draw_spaceship();
  void move_spaceship_left();
  void move_spaceship_right();
  void fire_laser();

private:
  Texture2D spaceship_image;
  Vector2 spaceship_position;

};

#include "../headers/spaceship.h"
#include <raylib.h>

Spaceship::Spaceship() {

  spaceship_image = LoadTexture("assets/spaceship.png");
  spaceship_position.x = 100;
  spaceship_position.y = 100;
  
}

Spaceship::~Spaceship() {

  UnloadTexture(spaceship_image);

}

void Spaceship::draw_spaceship() {

  DrawTextureV(spaceship_image, spaceship_position, WHITE);

}

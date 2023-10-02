#include "Ball.h"

#include <random>
#include <iostream>

using namespace std;

/*
 * One way to create variables, functions and classes
 * which are only visible in one file is by using an
 * anonymous namespace (that is, a namespace which
 * has no name).
 *
 * This will ensure that no other file will get
 * access to these variables.
 */
namespace
{
    /*
     * an engine which generates random numbers
     */
    random_device rd { };

    /*
     * wrappers which defines various ranges
     * we want to generate numbers in.
     */

    // used to randomly choose what sprite to use
    uniform_int_distribution<unsigned> index { 0, 1 };

    // randomly choose a radius
    uniform_real_distribution<float>   radius { 10, 50 };

    // randomly choose a velocity direction
    uniform_real_distribution<float>   angle { 0, 2*3.14 };

    // randomly choose a speed for our ball
    uniform_real_distribution<float>   length { 0.5, 8.0 };
}

/*
 * This constructor uses some basic trigonometry
 * to create a velocity vector.
 */
//Ball :: Ball (Spritesheet & sheet,
//              float         x,
//              float         y)
//        : sprite { sheet.get_sprite (0, index (rd)) },
//          velocity { }
//{
//    float direction { angle (rd) };
//    float speed     { length (rd) };
//
//    velocity = sf::Vector2f { speed * cos (direction),
//                              speed * sin (direction) };
//
//    /* position the ball, and make sure that we place
//     * the center of the ball where the mouse clicked */
//    auto sprite_size { sheet.sprite_size () };
//    sprite.setPosition (x, y);
//    sprite.setOrigin (sprite_size.x / 2, sprite_size.y / 2);
//}

Ball :: Ball (float         x,
             float         y)
       :
        sprite{radius(rd)}, velocity { }
{
   float direction { angle (rd) };
   float speed     { length (rd) };

   velocity = sf::Vector2f { speed * cos (direction),
                             speed * sin (direction) };

   /* position the ball, and make sure that we place
    * the center of the ball where the mouse clicked */

    // Create a sprite
    float sprite_size { sprite.getRadius () };
    sprite.setPosition (x, y);
    sprite.setOrigin (sprite_size / 2, sprite_size / 2);
}

void Ball :: update ()
{
    // move the sprite according to the velocity
    sprite.move (velocity);
}

void Ball :: render (sf::RenderTarget & target)
{
    // draw the sprite
    target.draw (sprite);
}

sf::FloatRect Ball :: bounds () const
{
    // get the hitbox of the sprite
    return sprite.getGlobalBounds ();
}

#pragma once

#include <SFML/Graphics.hpp>

/*
 * Class representing a moving ball on the screen.
 *
 * This class serves as a demonstration of a moving
 * object.
 */
class Ball
{

public:

    /*
     * Create a ball and place it at the supplied coordinates.
     */
    Ball( float x, float y);
    /*
     * This function contains all logic that needs
     * to be run for the ball each iteration in the
     * game loop.
     */
    void update ();

    /*
     * draw the ball to 'target'
     */
    void render (sf::RenderTarget & target);

    /*
     * Get a rectangle which covers the ball
     * completly (a hitbox)
     */
    sf::FloatRect bounds () const;

private:

    // graphical representation of the ball
    sf::CircleShape sprite;


    // the velocity (speed + direction) in
    // which this ball is moving
    sf::Vector2f velocity;

};

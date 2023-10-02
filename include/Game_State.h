#include "State.h"
#include "Ball.h"

#include <vector>

/*
 * This class represents the "game".
 *
 * It is a simple program where a ball appears wherever
 * the user has clicked with the mouse. This ball
 * is assigned a random velocity and will begin moving
 * according to that velocity.
 *
 * This class serves as an example of a state, but also
 * of how the various functions of the State class can
 * be used to get moving objects in the game.
 *
 * It also demonstrates how to remove objects from
 * the game in a safe way, as to avoid memory leaks.
 */
class Game_State : public State
{
public:

    Game_State () = default;

    void handle_event (sf::Event event) override;
    void update () override;
    void render (sf::RenderTarget & target) override;
    virtual int get_next_state() override;


private:
    bool end_game{false};

    /*
     * Remove all balls which are no longer visible on the
     * screen.
     */
    void cleanup ();


    /*
     * A collection which contains all balls that are currently
     * visible on the screen (see Ball.h).
     */
    std::vector<Ball> balls { };

};
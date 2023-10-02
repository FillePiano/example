#include "Menu_State.h"

#include <string>
#include <stdexcept>

using namespace sf;

/*
 * Create the welcome message using the font given in
 * 'resources/fonts/font.ttf'.
 *
 * The first argument of the sf::Text constructor is what string
 * it should draw, the second argument is what font should be used
 * to draw the text and the final argument specifies the font-size
 * (in pixels) of the text.
 */
Menu_State :: Menu_State ()
        :play { false }
{
    std::string file = "resources/fonts/font.ttf"; 
    if ( !font.loadFromFile (file) )
        throw std::invalid_argument ("Unable to load font");
    text = sf::Text{ "Press <Enter> to start", font, 16 };
}

/*
 * check for the 'enter' key.
 *
 * If it has been pressed we want to change to a new state.
 */
void Menu_State :: handle_event (Event event)
{
    if ( event.type == Event::KeyPressed )
    {
        if ( event.key.code == Keyboard::Key::Return )
            play = true;
    }
}


void Menu_State :: update ()
{

}

void Menu_State :: render (RenderTarget & target)
{
    auto bounds { text.getGlobalBounds () };
    auto size   { target.getSize () };

    text.setPosition ((size.x - bounds.width) / 2,
                      (size.y - bounds.height) / 2);

    target.draw (text);
}

/*
 * If return has been pressed we change to the GAME_STATE, otherwise
 * we stay in MENU_STATE
 */
int Menu_State :: get_next_state()
{
    if (play)
    {
        play = false;
        return GAME_STATE;
    }
    else
    {
        return MENU_STATE;
    }
}


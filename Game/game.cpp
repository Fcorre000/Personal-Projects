#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
// use g++ game.cpp -I/opt/homebrew/Cellar/sfml/2.6.2/include -o prog -L/opt/homebrew/Cellar/sfml/2.6.2/lib/ -lsfml-graphics -lsfml-window -lsfml-system
//to compile
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Cyan);
    shape.setSize(sf::Vector2f(100, 100));
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(2);
    shape.setPosition(200, 100);

    bool mouseWasReleased = false;
    bool AKeyWasReleased = false;

    sf::Texture texture;
    texture.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/maverick-sprite.jpeg");
    //setup our sprite with a texture
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        //event object created
        sf::Event event;

        //loop will run forever while our program is running
        while (window.pollEvent(event))
        {
            //will activate if we exit out of the program
            if (event.type == sf::Event::Closed){
                window.close(); 
                //terminal message to confirm we exited successfully
                cout << "Handling Event Close\n";
                exit(EXIT_SUCCESS);
            }

            if(event.type == sf::Event::KeyReleased){
                cout << "A key was pressed\n";
                if(event.key.code == sf::Keyboard::W){
                    cout <<"\t specifically the W Key\n";
                }
            }

            //terminal will display message if mouse button is pressed
            //while program is running
            if(event.type == sf::Event::MouseButtonPressed){
                cout << "Mouse Button Pressed\n";
                
            }

            //code used to make sure mouse detection is only detected on a press AND release
            //otherwise one mouse click will print out a whole lot of messages
            if(event.type == sf::Event::MouseButtonReleased){
                mouseWasReleased = true;
            }

            if(event.type == sf::Event::KeyReleased){
                AKeyWasReleased = true;
            }

                            
        }

        //outside of the event loop
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mouseWasReleased){
            cout <<"Left Mouse button Pressed\n";
            mouseWasReleased = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && AKeyWasReleased){
            cout << "The letter A key was pressed";
            AKeyWasReleased = false;
        }

        //will continually clear, draw and display window
        //until program is closed.
        window.clear();

        //draw sprites
        window.draw(sprite);
        //window.draw(shape);
        window.display();
    }

    return 0;
}


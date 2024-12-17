#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
// use g++ game.cpp -I/opt/homebrew/Cellar/sfml/2.6.2/include -o prog -L/opt/homebrew/Cellar/sfml/2.6.2/lib/ -lsfml-graphics -lsfml-window -lsfml-system
//to compile
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Fernando's SFML Project!");
    

    bool mouseWasReleased = false;
    bool AKeyWasReleased = false;
    float xPosition = 0.0f;

    //object for timing/fps
    sf::Clock clock; 
    window.setFramerateLimit(60);

    //Texture object used to put sprite in
    sf::Texture texture;
    texture.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/images/PlayerSprite.png");
    //setup our sprite with a texture
    sf::Sprite sprite(texture);

    sprite.setScale(.3, .3);
    

    //Load a font, and setup a test 'test' for the program
    sf::Font font;
    font.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/fonts/Simple Heavy.otf");
    sf::Text text("Bird From FORTNITE!!", font, 50);
    text.setPosition(50, 50);//position set to see text on on background, isn't necessary
    //this only confirms the text overlaps the sprite

    //set font color to whatever, but for now red
    text.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {

        //compute frame time
        float currentTime = clock.restart().asSeconds();//returns time object and stored as a float
        float fps = 1.0f/(currentTime);
        //cout << "fps: " << fps << "\n";


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

        sprite.setPosition(xPosition, 0.0f);
        xPosition+= 1;
        if(xPosition > 100){
            xPosition = 0;
        }

        //will continually clear, draw and display window
        //until program is closed.
        window.clear();

        //draw sprites
        window.draw(sprite);
        //Draw our test text
        window.draw(text);
        //window.draw(shape);
        window.display();
    }

    return 0;
}


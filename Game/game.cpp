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

                            
        }

        //will continually clear, draw and display window
        //until program is closed.
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}


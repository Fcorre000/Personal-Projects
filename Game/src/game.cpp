#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
using namespace std;
// use g++ game.cpp -I/opt/homebrew/Cellar/sfml/2.6.2/include -o prog -L/opt/homebrew/Cellar/sfml/2.6.2/lib/ -lsfml-graphics -lsfml-window -lsfml-system
//to compile

//interface for all components
class IComponent{
    public:
        virtual ~IComponent() { }

};


class Sprite2DComponent : public IComponent{
    public:
        
        Sprite2DComponent(string filepath){
            //setup our sprite with a texture
            m_texture.loadFromFile(filepath);
            m_sprite.setTexture(m_texture);
        }
        ~Sprite2DComponent(){

        }
        void Render(sf::RenderWindow& ref){
            ref.draw(m_sprite);
        }
    private:
        //Texture object used to put sprite in
        sf::Texture m_texture;
        //setup our sprite with a texture
        sf::Sprite m_sprite;
    
};

class GameEntity{
    public:
        GameEntity(){

        }
        ~GameEntity(){}
    private:
        vector<IComponent> m_components;
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Fernando's SFML Project!");
    

   
    float xPosition = 0.0f;

    //object for timing/fps
    sf::Clock clock; 
    window.setFramerateLimit(60);

    //Texture object used to put sprite in
    sf::Texture texture;
    texture.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/images/PlayerSprite.png");
    //setup our sprite with a texture
    sf::Sprite sprite(texture);

    //scale sprite image to not be too big
    sprite.setScale(.3, .3);
    

    //Load a font, and setup a test 'test' for the program
    sf::Font font;
    font.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/fonts/Simple Heavy.otf");
    sf::Text text("Bird From FORTNITE!!", font, 50);
    text.setPosition(50, 50);//position set to see text on on background, isn't necessary
    //this only confirms the text overlaps the sprite

    //set font color to whatever, but for now red
    text.setFillColor(sf::Color::Red);

    Sprite2DComponent test("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/images/PlayerSprite.png");

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
        }
        
        //will continually clear, draw and display window
        //until program is closed.
        window.clear();

        //draw sprites
        test.Render(window);
        //Draw our test text
        window.draw(text);
        //window.draw(shape);
        window.display();
    }

    return 0;
}


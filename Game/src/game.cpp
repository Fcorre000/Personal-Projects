#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;
// use g++ game.cpp -I/opt/homebrew/Cellar/sfml/2.6.2/include -o prog -L/opt/homebrew/Cellar/sfml/2.6.2/lib/ -lsfml-graphics -lsfml-window -lsfml-system
//to compile

//interface for all components
class IComponent{
    public:
        virtual ~IComponent() { }
        
        // not forced to implement this
        //TODO: Move this to a renderable or drawable component
        virtual void Render(sf::RenderWindow& ref) {}
        virtual void SetPosition(float x, float y) {}

};


class Sprite2DComponent : public IComponent{
    public:
        
        Sprite2DComponent(string filepath){
            //setup our sprite with a texture
            m_texture.loadFromFile(filepath);
            m_sprite.setTexture(m_texture);
            m_sprite.setScale(.09, .09);
        }
        ~Sprite2DComponent(){

        }
        void SetPosition(float x, float y){
            m_sprite.setPosition(x,y);
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

        //TODO: I'm going to make things very simple for now
        float xDirection = 1.0;
        float yDirection = 1.0;

        GameEntity(string name){
            m_name = name;
            //TODO: for the purpose of this lession, randomize x and y direction
            xDirection  = rand() %(5 + 1) - 3;
            yDirection  = rand() %(5 + 1) - 3;

        }
        ~GameEntity(){}

        void SetPosition(float x, float y){
            m_x = x;
            m_y = y;
            for(int i = 0; i < m_components.size(); i++){
                m_components[i] -> SetPosition(m_x, m_y);
            }
        }

        float GetXPosition() const{
            return m_x;
        }

        float GetYPosition() const{
            return m_y;
        }

        //addComponent, to add a new component
        void AddSpriteComponent2D(string filename){
            shared_ptr<Sprite2DComponent> sprite2dComponent = make_shared<Sprite2DComponent>(filename);
            m_components.push_back(sprite2dComponent);
        }

        //walk through all of the renderable components
        void Render(sf::RenderWindow& ref){
            for(int i = 0; i < m_components.size(); i++){
                m_components[i] -> Render(ref);
            }
        }
    
    private:
        float m_x, m_y; //positions of our Game Entity
        string m_name;
        vector<shared_ptr<IComponent>> m_components;
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Fernando's SFML Project!");
    

    //object for timing/fps
    sf::Clock clock; 
    window.setFramerateLimit(60);

    /*
    //Texture object used to put sprite in
    sf::Texture texture;
    texture.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/images/PlayerSprite.png");
    //setup our sprite with a texture
    sf::Sprite sprite(texture);

    //scale sprite image to not be too big
    sprite.setScale(.3, .3);
    */

    //Load a font, and setup a test 'test' for the program
    sf::Font font;
    font.loadFromFile("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/fonts/Simple Heavy.otf");
    sf::Text text("WOWZERS!!", font, 50);
    text.setPosition(50, 50);//position set to see text on on background, isn't necessary
    //this only confirms the text overlaps the sprite
    text.setFillColor(sf::Color::Blue);//set font color to whatever, but for now red

    srand(time(nullptr));

    vector<GameEntity> entities;
    for(int i = 0; i < 50; i++){
        GameEntity test("ghost" + to_string(i));
        test.AddSpriteComponent2D("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/images/PlayerSprite.png");
        
        float xPosition = rand() % 600;
        float yPosition = rand() % 600;
        test.SetPosition(xPosition, yPosition);
        entities.push_back(test);     
    }
    //GameEntity test("player");
    //test.AddSpriteComponent2D("/Users/fortnitekorea/Desktop/Personal-Projects/Game/assets/images/PlayerSprite.png");

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

        //draw all of our sprites
        for(int i = 0; i < entities.size(); i++){
            entities[i].Render(window);
            float x = entities[i].GetXPosition() + entities[i].xDirection;
            float y = entities[i].GetYPosition() + entities[i].yDirection;
            entities[i].SetPosition(x, y);
            //keep our entities in bounds
            if(x > 600){
                entities[i].xDirection *= -1;
            }
            if(x < 0){
                entities[i].xDirection *= -1;
            }
            if(y > 600){
                entities[i].yDirection *= -1;
            }
            if(y < 0){
                entities[i].yDirection *= -1;
            }
        }
        //test.Render(window);
        //Draw our test text
        window.draw(text);
        //window.draw(shape);
        window.display();
    }

    return 0;
}


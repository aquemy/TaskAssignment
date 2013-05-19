#ifndef SIFAPP_TS
#define SIFAPP_TS

#include <vector>
#include <SFML/Graphics.hpp>
#include <SIF/environment/aTaskSpot.hpp>
#include <SIF/environment/taskSpot.hpp>
#include <SIF/environment/coordonate.hpp>


class DTaskSpot
{
public:
    DTaskSpot(sif::ATaskSpot* _r) : r(_r)
    {
        rectangle = sf::RectangleShape(sf::Vector2f(10,10));
        rectangle.setFillColor(sf::Color::Red);
        update();
    }
    
    void update()
    {
        sif::Coordonate<2, int> c = static_cast<sif::TaskSpot<2,int>*>(r)->getCoordonates();
        rectangle.setPosition(sf::Vector2f(c[0], c[1]));
    }
    
    void draw(sf::RenderWindow &rw) const
    {
        rw.draw(rectangle);
    }   
    
protected :

    sf::RectangleShape rectangle;
    sif::ATaskSpot* r;

};

#endif

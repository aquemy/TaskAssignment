#ifndef SIFAPP_RES
#define SIFAPP_RES

#include <vector>
#include <SFML/Graphics.hpp>
#include <SIF/environment/aResource.hpp>
#include <SIF/environment/resource.hpp>
#include <SIF/environment/coordonate.hpp>


class DResource
{
public:
    DResource(sif::AResource* _r) : r(_r)
    {
        rectangle = sf::RectangleShape(sf::Vector2f(5,5));
        rectangle.setFillColor(sf::Color::Blue);
        update();
    }
    
    void update()
    {
        sif::Coordonate<2, int> c = static_cast<sif::Resource<2,int,int>*>(r)->getCoordonates();
        rectangle.setPosition(sf::Vector2f(c[0], c[1]));
    }
    
    void draw(sf::RenderWindow &rw) const
    {
        rw.draw(rectangle);
    }   
    
protected :

    sf::RectangleShape rectangle;
    sif::AResource* r;

};

#endif

#ifndef SIFAPP_ENV
#define SIFAPP_ENV

#include <vector>
#include <SFML/Graphics.hpp>
#include <SIF/environment/aEnvironment.hpp>

#include "resource.cpp"
#include "taskspot.cpp"

class DEnvironment
{
public:
    DEnvironment(sf::Vector2f _vect, sif::AEnvironment& _env) : env(&_env)
    {
        rectangle = sf::RectangleShape(_vect);
        rectangle.setFillColor(sf::Color(100, 250, 50));
        rectangle.setOutlineThickness(5);
        rectangle.setOutlineColor(sf::Color(250, 150, 100));
    }
    
    void update()
    {
        res.clear();
        for(auto e : env->getResources())
        {
            res.push_back(DResource(e));
        }
        ts.clear();
        for(auto e : env->getTaskSpots())
        {
            ts.push_back(DTaskSpot(e));
        }
    }
    
    void draw(sf::RenderWindow &rw) const
    {
        rw.draw(rectangle);
        for(auto e : ts)
            e.draw(rw);
        for(auto e : res)
            e.draw(rw);
        
    }   
    
protected :

    sf::RectangleShape rectangle;
    sif::AEnvironment* env;
    std::vector<DResource> res;
    std::vector<DTaskSpot> ts;
};

#endif

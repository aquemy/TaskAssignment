#include <iostream>
#include <exception>
#include <cassert>
#include <functional>
#include <random>
#include <string>

#include <SFML/Graphics.hpp>
#include <sif.hpp>

#include "src/environment.cpp"

using namespace std;
using namespace sif;

void SFML_Draw(sf::RenderWindow& window, 
    DEnvironment& env, 
    sf::Text& labelTask, 
    Task& t,
    SimpleSP& spa,
    AEnvironment& env2,
    double _time)
{
    if(window.isOpen())
    {
        // Add resources
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i pos = sf::Mouse::getPosition();
            Coordonate<2, int> coord;
            coord[0] = pos.x;
            coord[1] = pos.y;
            AResource* r = new Resource<2,int,int>(coord, 50 / 1000., false, spa);
            env2.addObject(*r);
        }
        
        // To close the application
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
                
        //Update 
        labelTask.setString("Value : "+to_string(t.getValue()));
        env.update();
        
        // Drawing part
        window.clear();
        env.draw(window);
        window.draw(labelTask);
        window.display();
    }
    else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.create(sf::VideoMode(800,600), "SIF Example");
}

int main(int argc, char *argv[])
{
    (void) argc;
    
    const unsigned xsize = 590;
    const unsigned ysize = 590;
    
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text labelTask("Value : 0", font, 25);
    labelTask.setColor(sf::Color::Black);

    try
    {
        // Create the Window and the View
        sf::RenderWindow window(sf::VideoMode(800,600), "SIF Example");
        
        // Random engine
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, xsize);
        std::uniform_int_distribution<> vel(5, 10);
    
        // Create simple 2D environment
        Environment<2, int, int> env;
        // Environment
        DEnvironment envi(sf::Vector2f(xsize, ysize), env);
        
        // Add some resources randomly
        SimpleSP spa;
        Coordonate<2,int> coord;

        std::vector<AResource*> res;
        for(unsigned i = 0; i < 5; i++)
        {
            coord[0] = dis(gen);
            coord[1] = dis(gen);
            res.push_back(new Resource<2,int,int>(coord, vel(gen) / 1000., false, spa));
        }
        
        env.addObject(res);
        
        // Create some tasks and the constraintSystem
        Task t;
        StepConstraint sc(0, t, ConstraintComp::GREATER, 500);
        ConstraintSystem constraintSystem;
        constraintSystem.push(&sc);
        
        // Add some taskSpots
        std::vector<ATaskSpot*> taskSpots;
        for(unsigned i = 0; i < 5; i++)
        {
            coord[0] = dis(gen);
            coord[1] = dis(gen);
            taskSpots.push_back(new TaskSpot<2,int>(coord, std::ref(t), [](int& i, double _time)
                { static double up = 0;
                    up += _time*0.0001;
                    if((int)up > 0)
                    {
                        up = 0;
                        return i + 1; 
                    }
                    else 
                        return i;
                }
            ));
        }
        
        env.addObject(taskSpots);
        
        
        // Assignment
        Kuhn assignment;
        
        // Strategies creation
        SimpleStrategy<2,int> s1(assignment);
        
        // Model creation
        ManualModel<2,int> model(s1);
        
        // IA Creation
        IA<2,int> ia(model, constraintSystem);
        
        // Stop criterion
        TimeContinue cont(25);
        Controller::addContinue(cont);
        
        // Step Environment
        unsigned envDelay = 100; // ms
        auto envController = bind(&Environment<2,int,int>::update, std::ref(env), placeholders::_1);
        Step envStep(envController, envDelay);
        Controller::addStep(envStep);
        
        // Step DUMP
        unsigned dumpDelay = 100; // ms
        auto dump = bind(&Environment<2,int,int>::dump, std::ref(env));
        Step dumpStep(dump, dumpDelay);
        Controller::addStep(dumpStep);
        
        // Step IA
        unsigned iaDelay = 1000; // ms
        auto iaController = bind(&IA<2,int>::update, std::ref(ia), placeholders::_1);
        Step iaStep(iaController, iaDelay);
        Controller::addStep(iaStep);
        
        // Step SFML Draw
        unsigned sfmlDelay = envDelay; // ms
        auto sfmlController = bind(&SFML_Draw, std::ref(window),  
                    std::ref(envi), 
                    std::ref(labelTask), 
                    std::ref(t), 
                    std::ref(spa),
                    std::ref(env),
                    placeholders::_1);
        Step sfmlStep(sfmlController, sfmlDelay);
        Controller::addStep(sfmlStep);
        
        // Init and launch the simulation
        Controller::init(ia, env);
        Controller::run();
    
    }
    catch(exception& e)
    {
        logger(Logger::ERROR) << e.what();
        logger << "FATAL ERROR - EXIT NOW !";
    }

    return 0;
}


#ifndef _engine_
#define _engine_

#include <chipmunk/chipmunk.h>
#include "scene.hpp"
#include "kitty.hpp"
#include "clock.hpp"
#include "explosive.hpp"
#include "engine_menu.hpp"

#define PIXELSTOMETERS(x) x/100.f
#define METERSTOPIXELS(x) x*100.f

#define MAXEXPLOSIVES 3

namespace fff{
    
    class engine: public fff::scene{
        cpSpace *space;
        sf::View camera;
        sf::Sprite floor;
        cpShape *shapeleftlimit, *shaperightlimit;
        fff::clock engineclock;
        sf::Text clock;
        sf::Text speed;
        sf::Text km_h;
        sf::Text height;
        sf::Text meters;
        
        sf::Uint32 time;
        
        fff::kitty kitty;
        fff::explosive explosive[MAXEXPLOSIVES];
        
        enum _status{
            running,
            pause,
        }status;
        
        engine_menu menu;
        
        public:
            engine();
            ~engine();
            void Reset();
            void loadResources();
            void Event(sf::Event &);
            void Run(sf::RenderTarget &);
            void Continue();
        
        protected:
            int createExplosive();
            bool generateExplosive();
            bool generateExplosiveWhileFalling();
            bool generateExplosiveWhileClimbing();
            
    };
    
}

#endif

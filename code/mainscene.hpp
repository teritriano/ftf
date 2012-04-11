#ifndef _mainscene_
#define _mainscene_

#include "scene.hpp"
#include "bg.hpp"

namespace fff{
    
    class mainscene: public fff::scene{
        
        sf::Text title;
        sf::Text instruction;
        
        sf::Text record;
        
        fff::bg bg;
        
        public:
            mainscene();
            void loadResources();
            void Event(sf::Event &);
            void Run(sf::RenderTarget &);
            void setRecord(char *);
            
    };
    
}

#endif

#include "Observers/Publisher.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 


namespace Managers{
    class Inputs : public Observers::Publisher{
        private:
            std::vector<Observers::Subscriber*> subscribers;
            std::unordered_map<sf::Keyboard::Key, std::string> keys;
        public:
            void subscribe(Observers::Subscriber* subscriber);
            void unsubscribe(Observers::Subscriber* subscriber);
            void notify_KeyPressed(sf::Keyboard::Key key);
            void notify_KeyReleased(sf::Keyboard::Key key);
            Inputs();
            ~Inputs();

    };

    
}
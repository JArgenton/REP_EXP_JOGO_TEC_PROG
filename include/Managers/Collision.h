#include "Math/Coord.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

namespace managers{


    class Collision{
        private:
            static Collision* instance;
            static std::mutex mtx;
            Collision();
        public:
            ~Collision();
            static Collision* get_instance();
            void check_collision(sf::RectangleShape* body1, sf::RectangleShape* body2);
    };
}
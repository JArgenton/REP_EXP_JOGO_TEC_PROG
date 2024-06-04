#include "Math/Coord.h"
#include <SFML/Graphics.hpp>
#include <mutex>
#include "List/EntityList.h"
namespace managers{
    class Collision{
        private:
            List::EntityList* StaticEntities;
            List::EntityList* MovingEntities;
            static Collision* instance;
            static std::mutex mtx;
        public:
            Collision(List::EntityList* StaticEntities, List::EntityList* MovingEntities);
            ~Collision();
            Math::CoordF check_collision(sf::RectangleShape* body1, sf::RectangleShape* body2);
            void exec();
    };
}
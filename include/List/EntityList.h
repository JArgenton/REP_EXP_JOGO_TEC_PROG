#include "List.h"
#include "include/Entities/Entity.h"
using namespace Entities;

namespace List{
    class EntityList{
        private:
            List<Entity> list;
        public:
            EntityList();
            ~EntityList();
            void add(Entity* entity);
            Entity* remove(Entity* entity);
            Entity* remove(int index);
            Entity* operator[](int index);
            void deleteEntity(int index);
            void deleteEntity(Entity* entity);
            int getsize();
            void clear();
    };




}
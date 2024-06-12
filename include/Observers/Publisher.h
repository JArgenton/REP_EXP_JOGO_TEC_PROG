
#include "Observers/Subscriber.h"
#include <vector>

namespace Observers{
    
    class Publisher{
        private:
            std::vector<Subscriber*> subscribers;
        public:
            virtual void subscribe(Subscriber* Subscriber) = 0;
            virtual void unsubscribe(Subscriber* Subscriber) = 0;
            virtual void notify() = 0;
    };
}
#include "headers\Dispacher.hpp"
#include <Observer.hpp>
#include <Message.hpp>

namespace engine 
{
    shared_ptr<Dispacher> Dispacher::_instance = shared_ptr<Dispacher>(nullptr);

    shared_ptr<Dispacher> engine::Dispacher::instance()
    {
        if (_instance == nullptr)
            Dispacher::_instance = shared_ptr<Dispacher>(new Dispacher);
        return _instance;
    }

    void engine::Dispacher::add(Observer& observer, string id)
    {
        observers[id].push_back(&observer);
    }

    void engine::Dispacher::send(Message& message)
    {
        auto list = observers.find(message.get_id());

        if (list != observers.end()) 
        {
            for (auto&& observer : list->second) 
            {
                observer->handle(message);
            }
        }
    }

}

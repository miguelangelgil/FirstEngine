#include "headers\Message.hpp"

engine::Message::Message(const string& id) : id(id)
{
}

void engine::Message::add_parameter(const string& id, string value)
{
    parameters[id] = value;
}

const string engine::Message::get_id()
{
    return id;
}

string engine::Message::get_value(const string& id)
{
    return parameters[id];
}

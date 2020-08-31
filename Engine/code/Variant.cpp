#pragma once
#include <Variant.hpp>
using namespace engine;

namespace engine
{
    Variant::Variant(bool initializer)
    {
        type = BOOL;
        value.bool_value = initializer;
    }

    Variant::Variant(int initializer)
    {
        type = INT;
        value.int_value = initializer;
    }

    Variant::Variant(float initializer)
    {
        type = FLOAT;
        value.float_value = initializer;
    }

    Variant::Variant(const string& initializer)
    {
        type = STRING;
        value.string_value = new string(initializer);
    }

    Variant::~Variant()
    {
        release();
    }

    void Variant::release()
    {

        if (type == STRING)
        {
            delete value.string_value;
        }

    }

    Variant::Type Variant::get_type() const
    {
        return type;
    }

    bool  Variant::is_bool() const
    {
        return type == BOOL;
    }

    bool  Variant::is_int() const
    {
        return type == INT;
    }

    bool  Variant::is_float() const
    {
        return type == FLOAT;
    }

    bool  Variant::is_string() const
    {
        return type == STRING;
    }

    bool  Variant::as_bool() const
    {
        switch (type)
        {
        case BOOL:    return  value.bool_value;
        case INT:     return  value.int_value != 0;
        case FLOAT:   return  value.float_value != 0.f;
        case STRING:  return *value.string_value == "true" ? true : false;
        }
        return false;
    }

    int  Variant::as_int() const
    {
        switch (type)
        {
        case BOOL:    return value.bool_value ? 1 : 0;
        case INT:     return value.int_value;
        case FLOAT:   return int(value.float_value);
        case STRING:  return strtol(value.string_value->c_str(), nullptr, 10);
        }

        return 0;
    }

    float Variant::as_float() const {
        switch (type) {
        case BOOL: return value.bool_value ? 1.f : 0.f;
        case INT: return float(value.int_value);
        case FLOAT: return value.float_value;
        case STRING: return std::stof(*value.string_value);
        }
        return 0.f;
    }

    string  Variant::as_string() const
    {
        switch (type)
        {
        case BOOL:    return  value.bool_value == true ? "true" : "false";
        case INT:     return  to_string(value.int_value);
        case FLOAT:   return  to_string(value.float_value);
        case STRING:  return *value.string_value;
        }

        return string();

    }

    Variant& Variant::operator = (const Variant& other)
    {

        if (this != &other)
        {

            release();

            this->type = other.type;
            this->value = other.value;

        }

        return *this;

    }

    Variant& Variant::operator = (int new_value)
    {

        release();

        type = INT;
        value.int_value = new_value;

        return *this;

    }

    Variant::operator int() const
    {
        return this->as_int();
    }

    Variant::operator string () const
    {
        return this->as_string();
    }
}
/*
MIT License

Copyright(c) 2020 MAGMa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#include <math.h>
#include <string>
#include <stdint.h>

using namespace std;
namespace engine
{
    class Porcentaje
    {
    private:
        size_t value;
        int min_value = 0;
        int max_value = 100;
    public:

        Porcentaje(size_t value)
        {
            this->value = value;
        }
        Porcentaje(int min_value, int max_value, size_t value = 0)
        {
            this->min_value = min_value;
            this->max_value = max_value;
            this->value = value;
        }
        ///Asigna un porcentaje 
        void set_porcentaje(size_t value)
        {
            if (value > 100) { value = 100; }
            this->value = value;
        }
        ///Asigna un porcentaje 
        void set_porcentaje(int value)
        {
            this->value = size_t(value * 100 / (abs(min_value) + abs(max_value)));
        }
        ///Asigna un porcentaje 
        void set_porcentaje(int min_value, int max_value, int value)
        {
            this->value = size_t(value * 100 / (abs(min_value) + abs(max_value)));
        }
        ///Retorna el porcentaje
        size_t get_porcentaje() { return value; }
        int get_porcentaje(int min_value, int max_value)
        {
            return(((int64_t)max_value - (int64_t)min_value) * (int)value / 100) + min_value;
        }
        bool operator < (const Porcentaje& other)
        {
            return value < other.value;
        }
        bool operator > (const Porcentaje& other)
        {
            return value > other.value;
        }
        bool operator ==(const Porcentaje& other)
        {
            return value == other.value;
        }
        operator string ()
        {
            return to_string(value) + "%";
        }
    };
}
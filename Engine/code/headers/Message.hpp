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
#include <EngineTypeDef.hpp>
#include <Variant.hpp>
using namespace engine;
using namespace std;
namespace engine
{
    class Message
    {
    public:

        /// <summary>
        /// Id del mensaje
        /// </summary>
        string id;

        /// <summary>
        /// Parametros que contienen el mensaje
        /// </summary>
        map< string, string > parameters;

        /// <summary>
        /// Constructor de clase
        /// </summary>
        /// <param name="id">id del mensaje</param>
        /// <returns></returns>
        Message(const string& id);

        /// <summary>
        /// Anyade parametros al mensaje
        /// </summary>
        /// <param name="id">parametro</param>
        /// <param name="value">valor</param>
        void add_parameter(const string& id, string value);

        /// <summary>
        /// Retorna la id del mensaje
        /// </summary>
        /// <returns></returns>
        const string get_id();

        /// <summary>
        /// Retorna el valor de un parametro
        /// </summary>
        /// <param name="id">parametro</param>
        /// <returns></returns>
        string get_value(const string& id);

    };

}
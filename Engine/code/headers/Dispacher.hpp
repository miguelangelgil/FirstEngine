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
#include <iostream>
#include <list>
#include <map>

using namespace std;
namespace engine 
{
    class Message;
    class Observer;
    class Dispacher
    {
    public:
        /// <summary>
        /// Retorna la referencia a la propia clase
        /// </summary>
        /// <returns>shared_ptr Dispacher</returns>
        static shared_ptr<Dispacher> instance();

    private:
        /// <summary>
        /// Guarda la referencia al objeto
        /// </summary>
        static shared_ptr<Dispacher> _instance;

        /// <summary>
        /// Mapa que contiene la lista de clases que esperan eventos y los eventos que esperan
        /// </summary>
        map<string, list<Observer* >> observers;

    public:

        /// <summary>
        /// Suscrive una clase a un evento
        /// </summary>
        /// <param name="observer"></param>
        /// <param name="id"></param>
        void add(Observer& observer, string id);

        /// <summary>
        /// Mnanda un mensaje a las clases que esten suscritas
        /// </summary>
        /// <param name="message"></param>
        void send(Message & message);


    };


}

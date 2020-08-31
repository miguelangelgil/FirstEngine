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
#include <iostream>
#include <list>

using namespace std;
namespace engine {


    class Input {
    public:
        /// <summary>
        /// Mapeo del teclado
        /// </summary>
        struct KEYCODE
        {
            const string A = "A";
            const string B = "B";
            const string C = "C";
            const string D = "D";
            const string E = "E";
            const string F = "F";
            const string G = "G";
            const string H = "H";
            const string I = "I";
            const string J = "J";
            const string K = "K";
            const string L = "L";
            const string M = "M";
            const string N = "N";
            const string O = "O";
            const string P = "P";
            const string Q = "Q";
            const string R = "R";
            const string S = "S";
            const string T = "T";
            const string U = "U";
            const string V = "V";
            const string W = "W";
            const string X = "X";
            const string Y = "Y";
            const string Z = "Z";
            const string SPACE = "SPACE";
            const string N1 = "1";
            const string N2 = "2";
            const string N3 = "3";
            const string N4 = "4";
            const string N5 = "5";
            const string N6 = "6";
            const string N7 = "7";
            const string N8 = "8";
            const string N9 = "9";
            const string N0 = "0";

        };
    public:
        /// <summary>
        /// Mapeo del teclado
        /// </summary>
        KEYCODE key_mapper;
        /// <summary>
        /// Lista de teclas pulsadas
        /// </summary>
        list<string> key_pressed;
        /// <summary>
        /// Comprueba si una tecla ha sido pulsada
        /// </summary>
        /// <param name="key">tecla</param>
        /// <returns></returns>
        bool is_key_pressed(string key);
        /// <summary>
        /// Comprueba si una tecla esta siendo pulsada
        /// </summary>
        /// <param name="key">tecla</param>
        void set_key_down(string key);
        
        /// <summary>
        /// Comprueba si una tecla se ha levantado
        /// </summary>
        /// <param name="key">tecla</param>
        void set_key_up(string key);
   
    };
}
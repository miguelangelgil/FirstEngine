# First Engine
----------------

## Description:
This is a videogame engine project developed with SDL2 and OpenGL 3.3, in the solution you can find two folders, Demo and Engine, in the first one you can find a scene built by the engine functionalities and in the second one, Engine, you can find the project engine.

---------------------

## Libraries:

[![N|SDL2](https://www.libsdl.org/media/SDL_logo.png)](https://www.libsdl.org/download-2.0.php)

[![N|OpenGL](https://www.opengl.org/img/opengl_logo.jpg)](https://www.opengl.org/)

-----------------

## Features:

* Scene -> can hold entities and the kernel (kernel manage the engine task so Scene is essential for engine operation)
* Entities -> that represent a game object in the scene, an entity can hold components
* Components -> hold functionalities, so components represent the features of the engine.
    * Transform Component -> all Entities have a default transform component, it's used to move the owner
    * Camera Component -> the owner has a camera to render the scene
    * Light Component -> the owner gives off light
    * Model Component -> the owner has a mesh
    * Control Component -> you can configure keyboards inputs for the owner
    * IA Component -> the owner follows a target
    * Sound Component -> the owner can play a soundtrack or fx
    * Sphere collider Component -> the owner detects collisions in a radius

------------------

## Licenses:

MIT License

Copyright (c) 2020 MAGMa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.



# scop
First openGl project of 42 school


The purpose is to parse an .obj file and display it using openGL.
The project must be done in C without any library to load .obj file, using matrix or parse an image file.


I use my own TGA parser for loading the texture.
The display is done using SDL2 and OpenGL4.1 on macOS.


The display must rotate in the 3 axis, have a basics texture apply on it.

the controls are as follow :
- x, y, z : to ratate in the differents axis (tap twice to change direction)
- z q s d : to move the object.
- a and e : to move the object front and back
- '*' '/'     : to change the rotation speed
- m       : the change the display mode (black & white, color, texture)
- t       : change texture
- p       : change the primitive

As requested on the subject there is a smooth changing from color to texture and texture to color.

![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-05-04%20at%204.09.07%20PM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.27.47%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.28.26%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.28.40%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.29.11%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.30.19%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.31.18%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.32.07%20AM.png)
![alt text](https://github.com/fchevrey/scop/blob/master/screenshots/Screen%20Shot%202019-06-07%20at%209.32.15%20AM.png)

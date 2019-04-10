#version 410
//VERTEX SHADER

layout (location = 0) in vec3 aPos;   // la variable aPos a l'attribut de position 0
layout (location = 1) in vec3 aColor; // la variable aColor a l'attribut de position 1

out vec3 ourColor; // transmettre une couleur au fragment shader

void main()
{
	gl_Position = vec4(aPos, 1.0);
	ourColor = aColor; // affecter ourColor avec l'entrée color issue des  données vertex
}

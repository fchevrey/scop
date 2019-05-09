#version 410
//VERTEX SHADER

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 pos;
out vec3 color;
//out vec2 tex_crd;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	pos = aPos;
	color = aColor;
	//tex_crd = vec2(UV);
}

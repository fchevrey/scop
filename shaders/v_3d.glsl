#version 410
//VERTEX SHADER

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 auv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
//uniform uint time;

out vec3 pos;
out vec2 uv;
//out uint time;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	pos = aPos;
	uv = auv;
}

#version 410
//VERTEX SHADER

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
//uniform uint time;

out vec3 pos;
flat out vec3 color;
//out uint time;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	pos = aPos;
	//float grey = (abs(pos.x) * 0.21 + abs(pos.y) * 0.71 + abs(pos.z) * 0.07);
	float grey = (abs(pos.x) * 0.2f + abs(pos.y) * 0.7f + abs(pos.z) * 0.1f);
//	float grey = (pos.x * 0.21 + pos.y * 0.71 + pos.z * 0.07) / 2.0f;
//	float grey = (aColor.x * 0.21 + aColor.y * 0.71 + aColor.z * 0.07);// / 2.0f;
	color = vec3(grey, grey, grey);
}

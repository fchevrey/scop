#version 410 core
//FRAGMENT SHADER

out vec4 FragColor;

in			vec3	pos;
smooth in	vec3	color;

uniform samplerCube ourTexture;

void main()
{
	FragColor = texture(ourTexture, pos);
}

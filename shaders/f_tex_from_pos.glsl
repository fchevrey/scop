
#version 410 core
//FRAGMENT SHADER

out vec4 FragColor;

in vec3 pos;

uniform sampler2D ourTexture;

void main()
{
	FragColor = texture(ourTexture, vec2(pos.x, pos.z));
}

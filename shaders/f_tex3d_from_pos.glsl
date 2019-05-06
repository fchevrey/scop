
#version 410 core
//FRAGMENT SHADER

out vec4 FragColor;

in vec3 pos;

//uniform sampler2D ourTexture;
uniform samplerCube ourTexture;

void main()
{
	FragColor = texture(ourTexture, pos);
}

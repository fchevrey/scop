#version 410 core
//FRAGMENT SHADER
out vec4 FragColor;
in vec3 ourColor;

void main()
{
	FragColor = vec4(ourColor, 1.0);
}

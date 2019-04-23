#version 410 core
//FRAGMENT SHADER
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
	FragColor = mix(texture(tex1, TexCoord), texture(tex2, TexCoord), 0.2);
}

#version 410 core
//FRAGMENT SHADER
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
	vec4 tex = texture(ourTexture, TexCoord);
	FragColor = vec4(tex.r, tex.g, tex.b, tex.a);
}

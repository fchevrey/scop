#version 410
//VERTEX SHADER

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform		mat4	model;
uniform		mat4	view;
uniform		mat4	projection;
uniform		int		aIs_tex;
uniform		int		aIs_flat;
uniform		int		aIs_grey;
uniform		int		aIs_time;
uniform		int		aIs_3dtex;
uniform		float	aTime;
uniform		float	aBlend;

out			vec3	pos;
flat out	vec3	color;
smooth out	vec3	s_color;
flat out	int		is_tex;
flat out	int		is_flat;
flat out	int		is_grey;
flat out	int		is_time;
flat out	int		is_3dtex;
flat out	float	time;
flat out	float	blend;

void main()
{
	time = (sin(aTime) / 2.0f) + 0.5f;
	pos = aPos;
	color = aColor;
	is_grey = aIs_grey;
	is_tex = aIs_tex;
	is_flat = aIs_flat;
	is_3dtex = aIs_3dtex;
	is_time = aIs_time;
	s_color = aColor;
	blend = aBlend;
	if (is_time == 1)
		s_color = vec3(pos);
	if (is_grey == 1)
	{
		float grey = (abs(pos.x) * 0.2f + abs(pos.y) * 0.7f + abs(pos.z) * 0.1f);
		color = vec3(grey, grey, grey);
	}
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
}

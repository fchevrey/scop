#version 410 core
//FRAG SHADER
uniform		sampler2D tex1;
uniform		sampler2D tex2;

out			vec4	FragColor;

in			vec3	pos;
flat in		vec3	color;
flat in		float	time;
smooth in	vec3	s_color;
flat in		int		is_flat;
flat in		int		is_time;
flat in		int		is_tex;
flat in		int		is_blend;
flat in		int		is_grey;
flat in		int		is_dbtex;
flat in		float	blend;

			vec4	color1;
			vec4	color2;
			vec4	final_color;
			vec2	tex_crd;

void main()
{
	color1 = vec4(s_color, 1.0f);
	color2 = vec4(s_color, 1.0f);
	tex_crd = vec2(pos.z, (pos.y + pos.x) / 2);
	if (is_flat == 1)
		color1 = vec4(color, 1.0f);
	if (is_tex == 1)
	{
		color1 = texture(tex1, tex_crd);
	}
	else
	{
		color2 = texture(tex1, tex_crd);
	}
	if (is_time == 1)
	{
		color1 = vec4(color1.x, time,
				color1.z, 1.0f);
	}
	if (is_blend == 1)
	{
		final_color = vec4(mix(color1.x, color2.x, blend),
				mix(color1.y, color2.y, blend),
				mix(color1.z, color2.z, blend),
				1.0f);
	}
	else
	{
		final_color = color1;
	}
	if (is_dbtex == 1)
	{
		final_color = mix(texture(tex1, tex_crd), texture(tex2, tex_crd), 0.5f);
	}
	FragColor = final_color;
}


#version 410 core
//FRAG SHADER
uniform		sampler2D ourTexture;
uniform		samplerCube ourTexture3d;

out			vec4	FragColor;

in			vec3	pos;
flat in		vec3	color;
flat in		float	time;
smooth in	vec3	s_color;
flat in		int		is_flat;
flat in		int		is_time;
flat in		int		is_tex;
flat in		int		is_grey;
flat in		int		is_3dtex;
flat in		float	blend;

			vec4	final_color;

void main()
{
	final_color = vec4(s_color, 1.0f);
	if (is_flat == 1)
		final_color = vec4(color, 1.0f);
	else if (is_tex == 1)
	{
		final_color = texture(ourTexture, vec2(pos.z, (pos.y + pos.x) /2));
	}
	if (is_3dtex == 1)
	{
		final_color = vec4(color, 1.0f);
		final_color = texture(ourTexture, vec2(pos.z, pos.x));
	}
	//if (is_3dtex == 1 || is_tex == 1)
	if (is_tex == 1)
	{
		final_color = vec4(mix(final_color.x, s_color.x, blend),
				mix(final_color.y, s_color.y, blend),
				mix(final_color.z, s_color.z, blend),
				mix(final_color.w, 1.0f, blend));
	}
	if (is_time == 1)
		final_color = vec4(final_color.x, time,
				final_color.z, 1.0f);
	FragColor = final_color;
}


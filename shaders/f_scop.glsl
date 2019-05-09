#version 410 core
//FRAG SHADER
uniform sampler2D ourTexture;

out vec4 FragColor;

in			vec3	pos;
flat in		vec3	color;
flat in		float	time;
smooth in	vec3	s_color;
flat in		int		is_flat;
flat in		int		is_time;
flat in		int		is_tex;
flat in		int		is_grey;
flat in		float	blend;

vec4 final_color;
void main()
{
  // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
   //float grey = (color.x * 0.21 + color.y * 0.72 + color.z * 0.07) / 2.0f;
	final_color = vec4(s_color, 1.0f);
   if (is_flat == 1)
		final_color = vec4(color, 1.0f);
   if (is_tex == 1)
   {
		final_color = texture(ourTexture, vec2(pos.z, (pos.y + pos.x) /2)); //
		final_color = vec4(mix(final_color.x, s_color.x, blend),
				mix(final_color.y, s_color.y, blend),
				mix(final_color.z, s_color.z, blend),
				mix(final_color.w, 1.0f, blend));
   }
		//* vec4(s_color, 0.5); ;
   if (is_time == 1)
	   final_color = vec4(final_color.x * time, final_color.y * time, final_color.z * time, 1.0f);
	FragColor = final_color;
}


#version 410 core
out vec4 FragColor;
in vec3 pos;
in vec3 center;
flat in vec3 color;
smooth in vec3 s_color;

void main()
{
  // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
   //float grey = (color.x * 0.21 + color.y * 0.72 + color.z * 0.07) / 2.0f;
   float grey = (pos.x * 0.21 + pos.y * 0.72 + pos.z * 0.07) / 2.0f;
   FragColor = vec4(grey, grey, grey, 1.0f);
}

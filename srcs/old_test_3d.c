#include "scop.h"
#include "init.h"
#include "tga.h"

typedef struct		s_mat4
{
	float		m[16];
}					t_mat4;

static int				load_gl_texture(unsigned int *text_number, char *filename)
{
	t_texture	*txt;

	if (!(txt = ft_load_texture(filename)))
		return (0);
	glGenTextures(1, text_number);
	glBindTexture(GL_TEXTURE_2D, *text_number);
	// définit les options de la texture actuellement liée
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, txt->size.x, txt->size.y, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA, txt->size.x, txt->size.y,
	//	0, GL_BGRA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glGenerateMipmap(GL_TEXTURE_2D);
	free_tex(&txt);
	return (1);
}

t_mat4        mat4_set(float a, int identity)
{
	t_mat4    ret;
	int        i;

	i = 0;
	while (i < 16)
	{
		if (identity)
			ret.m[i] = i % 5 == 0 ? a : 0;
		else
			ret.m[i] = a;
		i++;
	}
	return (ret);
}

t_mat4        mat4_proj(void)
{
	t_mat4    ret;
	float    t;
	float    r;

	t = tan(deg_to_rad(FOV) / 2) * N_PLANE;
	r = t * (WIN_WIDTH / WIN_HEIGHT);
	ret = mat4_set(0.0f, 0);
	ret.m[0] = 1 / r;
	ret.m[5] = 1 / t;
	ret.m[10] = -(F_PLANE + N_PLANE) / (F_PLANE - N_PLANE);
	ret.m[14] = -(2 * F_PLANE * N_PLANE) / (F_PLANE - N_PLANE);
	ret.m[11] = -1;
	return (ret);
}


void		calc_rot(t_mat4 *a, const t_vecfl axis, const float * coef)
{
	a->m[0] = coef[2] * axis.x * axis.x + coef[0];
	a->m[1] = coef[2] * axis.x * axis.y - coef[1] * axis.z;
	a->m[2] = coef[2] * axis.x * axis.z + coef[1] * axis.y;
	a->m[4] = coef[2] * axis.x * axis.y + coef[1] * axis.z;
	a->m[5] = coef[2] * axis.y * axis.y + coef[0];
	a->m[6] = coef[2] * axis.y * axis.z - coef[1] * axis.x;
	a->m[8] = coef[2] * axis.x * axis.z - coef[1] * axis.y;
	a->m[9] = coef[2] * axis.y * axis.z + coef[1] * axis.x;
	a->m[10] = coef[2] * axis.z * axis.z + coef[0];
}

t_mat4		mat4_mul(t_mat4 a, const t_mat4 b)
{
	t_mat4    ret;
	int        i;

	i = 0;
	while (i < 16)
	{
		ret.m[i] = a.m[i / 4 * 4] * b.m[i % 4] + a.m[i / 4 * 4 + 1] * b.m[i % 4 + 4]
			+ a.m[i / 4 * 4 + 2] * b.m[i % 4 + 8] + a.m[i / 4 * 4 + 3] * b.m[i % 4 + 12];
		i++;
	}
	return (ret);
}

t_mat4        mat4_rot(t_mat4 a, const float angle, const t_vecfl axis)
{
	t_mat4    ret;
	float    coef[3];

	coef[0] = cos(angle);
	coef[1] = sin(angle);
	coef[2] = 1 - coef[0];
	ret = mat4_set(1.0f, 1);
	calc_rot(&ret, axis, coef);
	ret = mat4_mul(ret, a);
	return (ret);
}

void		print_float_arr(float *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%f ", arr[i]);
		if (i % 4 == 3)
			printf("\n");
		i++;
	}
	printf("\n");
}

void			test_3d(t_data *data)
{
	const unsigned int		nb_array = 2;
	unsigned int			shaderprogram_orange;
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	char					*frag_file;
	char					*std_vert;
	unsigned int			text_number;


	shaderprogram_orange = glCreateProgram();
	frag_file = load_shader("shaders/f_3d_tex.glsl");
	std_vert = load_shader("shaders/v_3d_tex.glsl");
	vert_shader = add_shader(std_vert, &shaderprogram_orange, GL_VERTEX_SHADER);
	frag_shader = add_shader(frag_file, &shaderprogram_orange, GL_FRAGMENT_SHADER);
	glLinkProgram(shaderprogram_orange);
	glUseProgram(shaderprogram_orange);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	ft_strdel(&frag_file);
	ft_strdel(&std_vert);
	/*create vertices*/
	unsigned int		vbo;//Vertex Buffer Object
	unsigned int		VAO;//Vertex array Object
	float vert[] = {
		//position				txt coord
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};
	/*load texture*/
	glEnable( GL_BLEND );//to use alpha
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // to use alpha
	load_gl_texture(&text_number, "textures/Brick.tga");
	/*init buffer for vertices*/
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vbo);
	glBindVertexArray(VAO);
	/*init triangle*/
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	/*init buffer for indices*/
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	/*glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));*/
	glEnable(GL_DEPTH_TEST);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	t_4matrix		model;
	t_4matrix		view;
	t_4matrix		projection;
	float			*view_ptr;
	float			*model_ptr;
	float			*proj_ptr;

	view_ptr = (float*)malloc(sizeof(float) * 16);
	model_ptr = (float*)malloc(sizeof(float) * 16);
	proj_ptr = (float*)malloc(sizeof(float) * 16);
	model = m4_identity();
	//	model = m4_rotation(vecfl_set(0.5f, 1.0f, 0.0f), 270.0f);
	view = m4_identity();
	view = m4_translate(vecfl_set(0.0f, 0.0f, -3.0f));
	//model = m4_one();
	//view = m4_one();
	projection = perspective(90.0f, ptfl_set((float)WIN_WIDTH, (float)WIN_HEIGHT), 0.1f,
			100.0f);
	m4_to_float(proj_ptr, &projection, 1);
	m4_print(view);
	m4_to_float(view_ptr, &view, 1);
	//	print_float_arr(view_ptr, 16);
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram_orange, "projection"),
			1, GL_FALSE, proj_ptr);
	m4_to_float(view_ptr, &view, 1);
	m4_to_float(model_ptr, &model, 1);
	printf("projection : \n");
	print_float_arr(proj_ptr, 16);
	while(!glfwWindowShouldClose(data->win))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, text_number);
		glUseProgram(shaderprogram_orange);
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		model = m4_rotation(vecfl_set(0.0f, 1.0f, 1.0f), 50.0f * (float)glfwGetTime() );
		//model = m4_rotation(vecfl_set(0.0f, 0.0f, 0.0f), 50.0f * (float)glfwGetTime() );
		m4_to_float(view_ptr, &view, 1);
		m4_to_float(model_ptr, &model, 1);
		unsigned int modelLoc = glGetUniformLocation(shaderprogram_orange, "model");
		unsigned int viewLoc  = glGetUniformLocation(shaderprogram_orange, "view");
		glUniformMatrix4fv(modelLoc, 1, GL_TRUE, model_ptr);
		glUniformMatrix4fv(viewLoc, 1, GL_TRUE, view_ptr);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glfwSwapBuffers(data->win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &vbo);
	glfwTerminate();
}

#include "scop.h"
#include "init.h"
#include "tga.h"

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
	glEnable(GL_DEPTH_TEST);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	t_4matrix		model;
	t_4matrix		model_tmp;
	t_4matrix		view;
	t_4matrix		projection;
	float			*view_ptr;
	float			*model_ptr;
	float			*proj_ptr;

	view_ptr = (float*)malloc(sizeof(float) * 16);
	model_ptr = (float*)malloc(sizeof(float) * 16);
	proj_ptr = (float*)malloc(sizeof(float) * 16);
	model = m4_identity();
	model = m4_rotation(vecfl_set(0.0, 0.0, 0.0), 50.0f * (float)glfwGetTime());
	view = m4_identity();
	view = m4_translate(vecfl_set(0.0f, 0.0f, -2.0f));
	projection = perspective(90.0f, ptfl_set((float)WIN_WIDTH, (float)WIN_HEIGHT), 0.1f,
	100.0f);
	m4_to_float(proj_ptr, &projection, 1);
	m4_to_float(view_ptr, &view, 1);
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram_orange, "projection"),
			1, GL_FALSE, proj_ptr);
	while(!glfwWindowShouldClose(data->win))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, text_number);
		glUseProgram(shaderprogram_orange);
		glBindVertexArray(VAO);
		model_tmp = m4_rotation(vecfl_set(1.0, 0.0, 0.5), 1.5f);
		model = m4_op(&model_tmp, '*', &model);
		m4_to_float(model_ptr, &model, 1);
		unsigned int modelLoc = glGetUniformLocation(shaderprogram_orange, "model");
		unsigned int viewLoc  = glGetUniformLocation(shaderprogram_orange, "view");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model_ptr);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view_ptr);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glfwSwapBuffers(data->win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &vbo);
	glfwTerminate();
}

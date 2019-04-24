/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_double_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:13:00 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/24 12:14:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "init.h"
#include "tga.h"
//changes : render loop, one file more to load, fragment shader is different
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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, txt->size.x, txt->size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA, txt->size.x, txt->size.y, 0, GL_BGRA, GL_UNSIGNED_BYTE, txt->tab_pxl);
	glGenerateMipmap(GL_TEXTURE_2D);
	free_tex(&txt);
	return (1);
}

void			test_double_tex(t_data *data)
{
	const unsigned int		nb_array = 2;
	unsigned int			shaderprogram_orange;
	unsigned int			vert_shader;
	unsigned int			frag_shader;
	char					*frag_file;
	char					*std_vert;
	unsigned int			text1_nber;
	unsigned int			text2_nber;


	shaderprogram_orange = glCreateProgram();
	frag_file = load_shader("shaders/f_blendtex.glsl");
	std_vert = load_shader("shaders/v_basic_tex.glsl");
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
	/*	float vert[] = { //original form tuto
	// positions          // colors           // texture coords
	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};*/
	float vert[] = { //revert
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f    // top left 
	};
	/*	float vert[] = { //revert with alpha
	// positions          // colors           // texture coords
	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // top right
	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 1.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 0.0f, 1.0f,   0.0f, 0.0f    // top left 
	};*/
	unsigned int		indices[] =
	{
		0, 1, 3,
		1, 2, 3
	};
	unsigned int		ebo;//Element Buffer Array used to stock indices
	/*load texture*/
	glEnable( GL_BLEND );//to use alpha
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // to use alpha
	/*init buffer for vertices*/
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(VAO);
	/*init triangle*/
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	/*init buffer for indices*/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//             // color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	/*glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));*/
	load_gl_texture(&text1_nber, "textures/Brick.tga");
	load_gl_texture(&text2_nber, "textures/smiley.tga");
	glUniform1i(glGetUniformLocation(shaderprogram_orange, "tex1"), 0);//donne l'index des textures au fragment shader tex1 etant le nom de  la variable dans le shader 
	glUniform1i(glGetUniformLocation(shaderprogram_orange, "tex2"), 1);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	while(!glfwWindowShouldClose(data->win))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, text1_nber);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, text2_nber);
		glUseProgram(shaderprogram_orange);
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(data->win);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glfwTerminate();
}

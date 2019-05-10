/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:22:05 by fchevrey          #+#    #+#             */
/*   Updated: 2019/05/10 12:18:49 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

unsigned int			add_shader(const char *shadersource,
		unsigned int *shaderprogram, GLenum define)
{
	int					success;
	unsigned int		shader;
	char				info_log[512];

	shader = glCreateShader(define);
	glShaderSource(shader, 1, &shadersource, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		ft_putstr("Shader compilation error :");
		ft_putendl(info_log);
		return (0);
	}
	if (shaderprogram)
		glAttachShader(*shaderprogram, shader);
	return (shader);
}

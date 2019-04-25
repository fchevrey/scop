/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:05:06 by fchevrey          #+#    #+#             */
/*   Updated: 2019/04/25 19:37:49 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPT_H
# define LIBPT_H
# include "libft.h"

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_ptfl
{
	float	x;
	float	y;
}					t_ptfl;

typedef struct		s_ptdb
{
	double	x;
	double	y;
}					t_ptdb;

typedef struct		s_vec
{
	int		x;
	int		y;
	int		z;
}					t_vec;

typedef struct		s_vecfl
{
	float		x;
	float		y;
	float		z;
}					t_vecfl;

typedef struct		s_quatfl
{
	float		x;
	float		y;
	float		z;
	float		w;
}					t_quatfl;

typedef struct		s_4matrix
{
	float		n[4][4];
}					t_4matrix;

t_point				pt_bc(t_point crd, char operand, int nb);
t_point				pt_op(t_point crd1, char operand, t_point crd2);
t_point				pt_set(int x, int y);
void				pt_yplus(t_point *src, int ymin, int ymax);
void				pt_ypluseg(t_point *src, int ymin, int ymax);
void				ft_putcrd(t_point crd);
void				pt_swap(t_point *pt1, t_point *pt2);
t_ptfl				ptfl_op(t_ptfl crd1, char operand, t_ptfl crd2);
t_ptfl				ptfl_bc(t_ptfl crd, char operand, float nb);
t_ptfl				ptfl_set(float x, float y);
t_ptfl				ptfl_yplus(t_ptfl src, t_ptfl incr, float ymin,
		float ymax);
t_ptfl				ptfl_ypluseg(t_ptfl src, t_ptfl incr, float ymin,
		float ymax);
void				ptfl_swap(t_ptfl *pt1, t_ptfl *pt2);
t_ptdb				ptdb_op(t_ptdb crd1, char operand, t_ptdb crd2);
t_ptdb				ptdb_bc(t_ptdb crd, char operand, double nb);
t_ptdb				ptdb_set(double x, double y);
void				vec_swap(t_vec *pt1, t_vec *pt2);
t_vec				vec_bc(t_vec crd, char operand, int nb);
t_vec				vec_set(int x, int y, int z);
t_vec				vec_op(t_vec crd1, char operand, t_vec crd2);
void				vecfl_swap(t_vecfl *pt1, t_vecfl *pt2);
t_vecfl				vecfl_bc(t_vecfl crd, char operand, float nb);
t_vecfl				vecfl_set(float x, float y, float z);
t_vecfl				vecfl_op(t_vecfl crd1, char operand, t_vecfl crd2);

float				deg_to_rad(float deg);
float				rad_to_deg(float rad);
t_quatfl			quatfl_set(float x, float y, float z, float w);
t_quatfl			quatfl_form_vec(t_vecfl, float w);
t_4matrix			m4_identity(void);
t_4matrix			m4_zero(void);
t_4matrix			m4_one(void);
t_4matrix			m4_op(const t_4matrix *m1, char operand,
		const t_4matrix *m2);
t_4matrix			m4_bc(const t_4matrix *m1, char operand, float nb);
void				m4_to_float(float *array, const t_4matrix *src,
		int is_column_major);
t_vecfl				scale(t_vecfl src, t_vecfl factors);
t_vecfl				translate(t_vecfl src, t_vecfl factors);
t_vecfl				rotate_x(t_vecfl src, float angle);
t_vecfl				rotate_y(t_vecfl src, float angle);
t_vecfl				rotate_z(t_vecfl src, float angle);
t_vecfl				rotate(t_vecfl src, t_vecfl factors, float angle);
t_4matrix			perspective(float angle, float ratio,
float near, float far);
#endif

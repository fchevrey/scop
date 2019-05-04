
#include "parser.h"

static size_t	compute_length(t_list *lst)
{
	size_t		dst;

	dst = 0;
	while (lst)
	{
		dst += lst->id;
		lst = lst->next;
	}
	return (dst);
}

static void		fill(t_list *lst, unsigned int *arr)
{
	size_t			i;
	size_t			j;
	unsigned int	*tmp;

	i = 0;
	while (lst)
	{
		j = 0;
		tmp = (unsigned int*)lst->content;
		while (j < lst->id)
		{
			arr[i + j] = tmp[j] -1;
			j++;
		}
		i += j;
		lst = lst->next;
	}
}
/*static void		print_int(t_list *elem)
{
	static unsigned int		i = 0;
	unsigned int			*arr;

	arr = (unsigned int*)elem->content;
	if (arr)
	{
		printf("%u : %u %u %u\n", i, arr[0], arr[1], arr[2]);
		i++;
	}
}*/

static int		create_buf_from_list(t_int_buf *src)
{
	size_t		size;

	size = compute_length(src->lst);
	if (!size)
		return (0);
	if (!(src->buf = (unsigned int*)malloc(sizeof(unsigned int) * size)))
		return (0);
	fill(src->lst, src->buf);
	src->size = size;
	return (1);
}

int				parse_obj_face(t_parse *parse, char **line)
{
	if (!read_face(parse, line, "f "))
		return (0);
/*	ft_putendl("- vertex index -");
	ft_lstiter(parse->vert_index->lst, &print_int);*/
/*	ft_putendl("- normal index -");
	ft_lstiter(parse->norm_index->lst, &print_int);
	ft_putendl("- texture index -");
	ft_lstiter(parse->tex_index->lst, &print_int);*/
	if (create_buf_from_list(parse->vert_index))
		return (0);
	if (parse->is_texture && create_buf_from_list(parse->norm_index))
		return (0);
	if (parse->is_normal && create_buf_from_list(parse->tex_index))
		return (0);
//	printf("size texture = %zu\n", size);
//	ft_lstdel(&parse->buf_lst, &free_elem);
//	ft_putendl("face");
	ft_strdel(line);
	return (1);
}

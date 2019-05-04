
#include "parser.h"
static void		print_int(t_list *elem)
{
	static int		i = 0;
	int			*arr;

	arr = (int*)elem->content;
	if (arr)
	{
		printf("%d : %d %d %d\n", i, arr[0], arr[1], arr[2]);
		i++;
	}
}

int				parse_obj_face(t_parse *parse, char **line)
{
	ft_putendl("face");
	read_face(parse, line, "f ");
	ft_putendl("- vertex index -");
	ft_lstiter(parse->vert_index->lst, &print_int);
	ft_putendl("- normal index -");
	ft_lstiter(parse->norm_index->lst, &print_int);
	ft_putendl("- texture index -");
	ft_lstiter(parse->tex_index->lst, &print_int);
//	size = lst_to_arr(parse->buf_lst, &parse->tex_buffer->buf);
//	parse->tex_buffer->size = size;
//	printf("size texture = %zu\n", size);
//	ft_lstdel(&parse->buf_lst, &free_elem);
//	ft_putendl("face");
	ft_strdel(line);
	return (1);
}

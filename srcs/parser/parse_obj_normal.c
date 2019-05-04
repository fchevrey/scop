
#include "parser.h"
/*static void		print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f %f\n", i, arr[0], arr[1], arr[2]);
	i++;
}*/

int		parse_obj_normal(t_parse *parse, char **line)
{
	size_t		size;

	ft_putendl("- normal -");
	parse->is_normal = 1;
	read_float_arr(parse, line, "vn ", 3);
//	ft_lstiter(parse->buf_lst, &print_float);
	size = lst_to_arr(parse->buf_lst, &parse->normal_buffer->buf);
	parse->normal_buffer->size = size;
	printf("size normal = %zu\n", size);
	ft_lstdel(&parse->buf_lst, &free_elem);
	if (!parse || !line)
		return (1);
	return (1);
}

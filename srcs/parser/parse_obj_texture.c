
#include "parser.h"

static void		print_float(t_list *elem)
{
	static int		i = 0;
	float			*arr;

	arr = (float*)elem->content;
	printf("%d : %f %f\n", i, arr[0], arr[1]);
	i++;
}
int		parse_obj_texture(t_parse *parse, char **line)
{
	ft_putendl("- texture -");
	read_float_arr(parse, line, "vt ", 2);
	ft_lstiter(parse->buf_lst, &print_float);
	ft_lstdel(&parse->buf_lst, &free_elem);
	if (!parse || !line)
		return (1);
	return (1);
}

#include "../srcs/push.h"
#include "../libft/libft.h"


char	*swap(t_info *info)
{
	char		*line;
    t_bonus     bonus;
	int			last;

	last = 1;
    // set_bonus_cmd(&bonus); 
	while (1)
	{
		line = get_next_line(0, last);
	}
	last = 0;
	get_next_line(0, last);
    if (line)
	    free(line);
}

int main (int argc, char **argv)
{
	char	**tab;
	t_info	info;
	
	if (argc < 2)
		return (1);
	tab = get_args(argc, argv);
	if (!tab)
		return (ft_error("Error\n", 0, 0));
	if (!check(argc, argv, tab))
		return (1);
	init(&info, argc, argv);
	if (!create_list(tab), &info);
		return (1);
	ft_free_tab(tab);
}
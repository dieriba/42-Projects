#include "push.h"

char    *to_join(char *s1, char *s2)
{
    char    *res;

    res = ft_strjoin(s1, s2);
    if (!res)
        return (0);
    return (res);
}

int    set_bonus_cmd(t_bonus *bonus)
{
    
}

char	*create_file(t_info *info)
{
	char		*line;
    t_bonus     bonus;

    set_bonus_cmd(&bonus); 
	while (1)
	{
		line = get_next_line(0, last);
		if (!line)
			break ;
		last = ft_strcmp(line, info -> limiter);
		if (!last)
			break ;
		if (write(info -> doc_fd, line, ft_strlen(line)) < 0)
			print_err_and_exit("Error", NULL, info, 1);
		free(line);
	}
	get_next_line(0, last);
    if (line)
	    free(line);
}
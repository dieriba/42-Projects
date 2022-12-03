#include "push.h"



void    swapper(t_info *info)
{
	go_to_b(info);
    print_stack(&info -> a, 'a');
	// if (info -> lst_size_a == 3)
	// 	sort_these_three(&info -> a);
    print_stack(&info -> a, 'a');
	if (info -> b)
		back_to_home(info);
}
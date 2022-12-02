#include "push.h"

void    choose_node(t_info *info)
{
    if (info -> tmp_ra != -1 && info -> tmp_rb != -1)
		if (info -> tmp_ra + info -> tmp_rb <= info -> ra + info -> rb)
		{
			info -> ra = info -> tmp_ra;
			info -> rb = info -> tmp_rb;
		}
	if (info -> tmp_rra != -1 && info -> tmp_rrb != -1)
		if (info -> tmp_rra + info -> tmp_rrb <= info -> rra + info -> rrb)
		{
			info -> rra = info -> tmp_rra;
			info -> rrb = info -> tmp_rrb;
		}
}
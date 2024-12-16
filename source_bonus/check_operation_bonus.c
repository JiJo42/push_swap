/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:07:28 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 11:23:45 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*exit properly when search operation need it*/
static void	search_exit(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str)
		free(str);
	checker_exit(stack_a, stack_b, ERROR);
}

/*search the operation from stdin and do it, exit if dont find*/
static void	search_and_do(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0 && str[4] == '\0')
		swap_a(stack_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0 && str[4] == '\0')
		swap_b(stack_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0 && str[4] == '\0')
		swap_both(stack_a, stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0 && str[4] == '\0')
		push_a(stack_a, stack_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0 && str[4] == '\0')
		push_b(stack_a, stack_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0 && str[4] == '\0')
		rotate_a(stack_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0 && str[4] == '\0')
		rotate_b(stack_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0 && str[4] == '\0')
		rotate_both(stack_a, stack_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0 && str[5] == '\0')
		reverse_rotate_a(stack_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0 && str[5] == '\0')
		reverse_rotate_b(stack_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0 && str[5] == '\0')
		reverse_rotate_both(stack_a, stack_b);
	else
		search_exit(stack_a, stack_b, str);
}

/*read stdin and execute operation exit if memory problem*/
void	get_stdin(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		search_and_do(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free(str);
}

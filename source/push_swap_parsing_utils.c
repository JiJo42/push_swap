/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:43 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/09 13:05:04 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*transform and return the argument to a valid integer
if invalid (double or no direct operator) return ERROR*/
int	ft_atoi_ps(const char *str)
{
	int	i;
	int	negativ;
	int	result;

	result = 0;
	i = 0;
	negativ = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ *= -1;
		i++;
	}
	if (!(str[i] <= '9' && str[i] >= '0'))
		return (ERROR);
	while (str[i] <= '9' && str[i] >= '0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (ERROR);
	return (result * negativ);
}

/*properly exit the program if the parsing are invalid or encounter a problem*/
void	parsing_exit(t_stack **stack, char **split, int code)
{
	if (stack)
		ft_stackclear(stack);
	if (split)
		freetab(split);
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (code == MEMORY_ERROR)
		ft_putstr_fd("Memory Error\n", 2);
	exit(EXIT_FAILURE);
}

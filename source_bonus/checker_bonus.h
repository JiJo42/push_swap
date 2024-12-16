/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:01:36 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 11:33:55 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define OK 2
# define KO 1
# define NO_ERROR 0
# define ERROR -1
# define MEMORY_ERROR -2

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

# include <unistd.h>
# include "../libft/libft.h"

/*---OPERATION---*/
# include "operations_bonus/operations_bonus.h"



/*in: check_operation_bonus*/
void	get_stdin(t_stack **stack_a, t_stack **stack_b);

/*---PARSING---*/
/*in: checker_parsing_bonus*/
void	parsing_ck(int argc, char **argv, t_stack **stack_a);
/*in: checker_parsing_utils_bonus*/
int		atoi_ck(const char *str);
void	parsing_exit(t_stack **stack, char **split, int code);

/*---STACK---*/
/*in: checker_stack_utils_bonus*/
t_stack	*stacknew(int content);
t_stack	*stacklast(t_stack *stack);
void	stackadd(t_stack **stack, t_stack *new);
void	stackclear(t_stack **stack);
int		stacksize(t_stack *stack);

/*---UTILS---*/
/*in: checker_utils_bonus*/
void	freetab(char **tab);
void	check_sort(t_stack **stack_a, t_stack **stack_b, int first_time);
void	checker_exit(t_stack **stack_a, t_stack **stack_b, int code);

#endif
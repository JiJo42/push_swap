/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:56:08 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 11:59:29 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NO_ERROR 0
# define ERROR -1
# define MEMORY_ERROR -2

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_mq
{
	int	q1;
	int	med;
	int	q3;
}	t_mq;

# include <unistd.h>
# include "../libft/libft.h"

/*---OPERATION---*/
# include "operations/operations.h"

/*---PARSING---*/
/*in: push_swap_parsing*/
void	parsing_ps(int argc, char **argv, t_stack **stack_a);
/*in: push_swap_parsing_utils*/
int		atoi_ps(const char *str);
void	parsing_exit(t_stack **stack, char **split, int code);

/*---STACK---*/
/*in: push_swap_stack_utils*/
t_stack	*stacknew(int content);
t_stack	*stacklast(t_stack *stack);
void	stackadd(t_stack **stack, t_stack *new);
void	stackclear(t_stack **stack);
int		stacksize(t_stack *stack);

/*---UTILS---*/
/*in: push_swap_utils*/
void	freetab(char **tab);
void	check_sort(t_stack **stack_a);
void	ps_exit(t_stack **stack_a, t_stack **stack_b, int code);

/*---SORTING---*/
/*in: sort_little*/
void	sort_little(t_stack **stack_a, t_stack **stack_b, int size);
/*in: sort_big*/
void	sort_big(t_stack **stack_a, t_stack **stack_b, int size);
/*in: sort_big_utils*/
t_mq	*get_mq(t_stack **stack_a, int size);

#endif
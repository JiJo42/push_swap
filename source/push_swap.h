/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:56:08 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/11 08:30:59 by dleclerc         ###   ########.fr       */
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

# include <unistd.h>
# include "../libft/libft.h"
# include "operations.h"

/*in: push_swap_parsing*/
t_stack	**parsing_ps(int argc, char **argv);

/*in: push_swap_parsing_utils*/
int		atoi_ps(const char *str);
void	parsing_exit(t_stack **stack, char **split, int code);

/*in: push_swap_stack_utils*/
t_stack	*stacknew(int content);
t_stack	*stacklast(t_stack *stack);
void	stackadd(t_stack **stack, t_stack *new);
void	stackclear(t_stack **stack);
int		stacksize(t_stack *stack);

/*in: push_swap_utils*/
void	freetab(char **tab);

#endif
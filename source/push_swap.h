/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:56:08 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/06 08:04:29 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

# define NO_ERROR 0
# define ERROR -1
# define MEMORY_ERROR -2

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

/*in: push_swap_parsing*/

/*in: push_swap_stack_utils*/
t_stack	*ft_stacknew(int content);
void	ft_stackadd(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackclear(t_stack **stack);

#endif
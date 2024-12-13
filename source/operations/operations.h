/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:13:12 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/13 09:23:13 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

/*define code for more efficient print of operations*/
# define sa "sa\n"
# define sb "sb\n"
# define ss "ss\n"
# define pa "pa\n"
# define pb "pb\n"
# define ra	"ra\n"
# define rb "rb\n"
# define rr "rr\n"
# define rra "rra\n"
# define rrb "rrb\n"
# define rrr "rrr\n"

# include <unistd.h>
# include "../push_swap.h"

/*in: swap*/
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

/*in: push*/
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

/*in: rotate*/
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);

/*in: reverse_rotate*/
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
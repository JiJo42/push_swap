/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:13:12 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/14 18:22:39 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_BONUS_H
# define OPERATIONS_BONUS_H

/*define code for more efficient print of operations*/
# define sa 100
# define sb 101
# define ss 102
# define pa 103
# define pb 104
# define ra	105
# define rb 106
# define rr 107
# define rra 108
# define rrb 109
# define rrr 110

# include <unistd.h>
# include <stdarg.h>
# include "../checker_bonus.h"

/*in: swap_bonus*/
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

/*in: push_bonus*/
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

/*in: rotate_bonus*/
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);

/*in: reverse_rotate_bonus*/
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
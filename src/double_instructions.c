/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/20 08:51:28 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

//ss : sa and sb at the same time.

void    swap_both(t_element **stack_a, t_element **stack_b)
{
    swap(stack_a, 'a');
    swap(stack_b, 'b');
    printf("ss\n");
}

//rr : ra and rb at the same time.

void    rotate_both(t_element **stack_a, t_element **stack_b)
{
    rotate(stack_a, 'a');
    rotate(stack_b, 'b');
    printf("rr\n");
}

//rrr : rra and rrb at the same time.

void    reverse_rotate_both(t_element **stack_a, t_element **stack_b)
{
    reverse_rotate(stack_a, 'a');
    reverse_rotate(stack_b, 'b');
    printf("rrr\n");
}

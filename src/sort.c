/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:43:58 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/10 14:17:12 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	little_sort(t_element *top_of_stack, t_element *bot_of_stack, int argc)
{
	if (top_of_stack->value > top_of_stack->next->value
		&& bot_of_stack->value > top_of_stack->value)
		swap(&top_of_stack, 'a');
	else if (top_of_stack->value > bot_of_stack->value
		&& bot_of_stack->value > top_of_stack->next->value)
		rotate(&top_of_stack, 'a');
	else if (top_of_stack->value < top_of_stack->next->value
		&& top_of_stack->next->value > bot_of_stack->value)
		reverse_rotate(&top_of_stack, 'a');
	else if (top_of_stack->value > top_of_stack->next->value
		&& top_of_stack->next->value > bot_of_stack->value)
	{
		swap(&top_of_stack, 'a');
		reverse_rotate(&top_of_stack, 'a');
	}
	else if (top_of_stack->value < top_of_stack->next->value
		&& top_of_stack->value < bot_of_stack->value)
	{
		swap(&top_of_stack, 'a');
		rotate(&top_of_stack, 'a');
	}
}

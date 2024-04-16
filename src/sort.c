/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:43:58 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/16 10:49:59 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	little_sort(t_element *stack, int argc)
{
	if (argc == 3 && stack->value > stack->prev->value)
	{
		swap(&stack, 'a');
		exit(EXIT_SUCCESS);	
	}
	if(argc == 4)
	{
		three_int_sort(stack);
		exit(EXIT_SUCCESS);	
	}
	// else if(argc == 5)
	// {
	// 	five_int_sort(stack);
	// 	exit(EXIT_SUCCESS);	
	// }
}
void	three_int_sort(t_element *stack)
{
	if (stack->value > stack->next->value
		&& stack->prev->value > stack->value)
		swap(&stack, 'a');
	else if (stack->value > stack->prev->value
		&& stack->prev->value > stack->next->value)
		rotate(&stack, 'a');
	else if (stack->value < stack->next->value
			&& stack->value > stack->prev->value)
			reverse_rotate(&stack, 'a');
	else if (stack->value > stack->next->value
		&& stack->next->value > stack->prev->value)
	{
		swap(&stack, 'a');
		reverse_rotate(&stack, 'a');
	}
	else if (stack->value < stack->next->value
		&& stack->value < stack->prev->value)
	{
		swap(&stack, 'a');
		rotate(&stack, 'a');
	}
}

// void	five_int_sort(t_element *stack)
// {
	
// }

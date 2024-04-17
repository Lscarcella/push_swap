/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:43:58 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/17 13:59:02 by lozkuro          ###   ########.fr       */
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
	else if(argc == 5)
	{
		four_int_sort(stack);
		exit(EXIT_SUCCESS);
	}
	else if(argc == 6)
	{
		five_int_sort(stack);
		exit(EXIT_SUCCESS);	
	}
}
void	find_min_and_pos(int *min1, int *min2, int *position, t_element *stack_a)
{
	t_element *ptr;

 	ptr = stack_a->next;
    *min1 = stack_a->value;
    *min2 = ptr->value;
	*position = 0;
    while (ptr != stack_a)
	{
        if (ptr->value < *min1)
		{
            *min2 = *min1;
            *min1 = ptr->value;
        }
		else if (ptr->value < *min2)
            *min2 = ptr->value;
        ptr = ptr->next;
    }
	while(ptr->value != *min1)
	{
		position++;
		ptr = ptr->next;
	}
}
void	three_int_sort(t_element *stack)
{
	int a = stack->value;
	int b = stack->next->value;
	int c = stack->prev->value;

	if (a < b && b < c)
		return ;
	else if (a > b && c > a)
		swap(&stack, 'a');
	else if (a > c && c > b)
		rotate(&stack, 'a');
	else if (a < b && a > c)
			reverse_rotate(&stack, 'a');
	else if (a > b && b > c)
	{
		swap(&stack, 'a');
		reverse_rotate(&stack, 'a');
	}
	else if (a < b && a < c)
	{
		swap(&stack, 'a');
		rotate(&stack, 'a');
	}
}


void	four_int_sort(t_element *stack_a)
{
	t_element *stack_b;
	t_element *ptr;
	int min;
	
	ptr = stack_a->next;
	min = stack_a->value;
	stack_b = NULL;
	while (ptr != stack_a)
	{
		if(ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	while(stack_a->value != min)
	rotate(&stack_a, 'a');
	push(&stack_a, &stack_b, 'b');
	three_int_sort(stack_a);
	push(&stack_b, &stack_a, 'a');
}
void	five_int_sort(t_element *stack_a)
{
	t_element *stack_b;
	int min1;
	int min2;
	int position;

	stack_b = NULL;
	find_min_and_pos(&min1, &min2, &position, stack_a);
	while(stack_a->value != min1)
	{
	if(position <= 3)
	rotate(&stack_a, 'a');
	else
	reverse_rotate(&stack_a, 'a');
	}
	push(&stack_a, &stack_b, 'b');
	while(stack_a->value != min2)
	rotate(&stack_a, 'a');
	push(&stack_a, &stack_b, 'b');
	three_int_sort(stack_a);
	push(&stack_b, &stack_a, 'a');
	push(&stack_b, &stack_a, 'a');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/20 08:42:10 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_element	*stack_a;
	int stack_len;

	stack_len = 0;
	stack_a = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(1);
	else 
		stack_len = init_stack(&stack_a, argc, argv, stack_len);
	if (stack_len <= 5)
		little_sort(stack_a, stack_len);

}

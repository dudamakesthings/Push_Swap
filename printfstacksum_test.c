void print_stack(t_stack *first_element)
{
	t_stack *current_node;
	int sum = 0;

	current_node = first_element;
	while (current_node != NULL) 
	{
		// ft_printf("%d\n", current_node->number);
		sum += current_node->number;
		current_node = current_node->next;
	}
	ft_printf("%d\n", sum);
}

void test(head_a)
{
	//faca com que o a seja o menor numero
	//mas voce nao sabe quem e o maior e quem e o menor
	if (head_a->next->conteudo < head_a->conteudo)
	{
		ft_swap();
	}
}

test(8, 16);
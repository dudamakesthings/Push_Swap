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
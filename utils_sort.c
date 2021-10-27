// #include "push_swap.h"

// t_node	*find_min(t_stack *a)
// {
// 	t_node	*smallest;
// 	t_node	*comparator;

// 	if (a->head == NULL)
// 		return ;
// 	if (a->size == 1)
// 		return (smallest = a->head);
// 	else
// 	{	
// 		smallest = a->head;
// 		comparator = a->head->next;
// 		while(a->size)
// 		{
// 			if (smallest->num > comparator->num && comparator->index == -1)
// 			{
// 				smallest = comparator;
// 				comparator = comparator->next;
// 			}
// 			a->size--;
// 		}
// 	}
// 	return (smallest);
// }

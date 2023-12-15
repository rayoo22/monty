#include "monty.h"
/**
 * push - push element in a stack
 * @stack: head of the linked list
 * @line_numer: line number
 */
void _push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * pall - prints all vlues on the stak
 * @stack: head of the linked list
 * @line_number: line numbers
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;

	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the linked list
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * pop - removes the top element
 * @stack: head of the list
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - frees the linked list
 * @head: pointer to tje first node
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: head of the linked list
 * @line_number: line_number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp
	stack_t *runner;

	runner = *stack;

	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: cant swap, to short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

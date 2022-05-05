#ifndef SORT_H
#define SORT_H
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

#include <stdio.h>
#include <stdlib.h>
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void merge_sort(int *array, size_t size);
int  copy_array(int *array, int start_index, int end_index, int *array_copy);
void top_down_split(int *array2, int start_index, int end_index, int *array3);
void top_down(int *array2, int start_index, int end_index, int *array3);
#endif /*SORT_H*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return (NULL);

	new_table->size = size;
	new_table->array = calloc(size, sizeof(shash_node_t *));
	if (!new_table->array) 
    {
		free(new_table);
		return (NULL);
	}

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The hash table to add/update the key/value pair
 * @key: The key, string
 * @value: The value corresponding to a key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	if (!ht || !key || !value)
		return (0);

	unsigned long int index;
	shash_node_t *new_node, *current, *prev;

	index = key_index((unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current) 
    {
		if (strcmp(current->key, key) == 0) 
        {
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (!new_node->key || !new_node->value) 
    {
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	/* Add to sorted linked list */
	if (!ht->shead || strcmp(new_node->key, ht->shead->key) < 0) 
    {
		new_node->snext = ht->shead;
		new_node->sprev = NULL;
		if (ht->shead)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
		if (!ht->stail)
			ht->stail = new_node;
	} else {
		prev = ht->shead;
		while (prev->snext && strcmp(new_node->key, prev->snext->key) > 0) 
        {
			prev = prev->snext;
		}

		new_node->snext = prev->snext;
		new_node->sprev = prev;
		if (prev->snext)
			prev->snext->sprev = new_node;
		else
			ht->stail = new_node;
		prev->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key in the sorted hash table
 * @ht: The hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	if (!ht || !key)
		return NULL;

	unsigned long int index = key_index((unsigned char *)key, ht->size);
	shash_node_t *current = ht->array[index];

	while (current) 
    {
		if (strcmp(current->key, key) == 0)
			return current->value;
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the hash table using the sorted linked list
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	if (!ht)
		return;

	shash_node_t *current = ht->shead;

	printf("{");
	while (current) {
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
		if (current)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table in reverse order using the sorted linked list
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	if (!ht)
		return;

	shash_node_t *current = ht->stail;

	printf("{");
	while (current) {
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
		if (current)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	if (!ht)
		return;

	shash_node_t *current, *temp;

	for (unsigned long int i = 0; i < ht->size; i++) {
		current = ht->array[i];
		while (current) {
			temp = current;
			current = current->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}

	free(ht->array);
	free(ht);
}

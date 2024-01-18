#ifndef MONTEY_H
#define MONTEY_H

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Deque */

typedef enum
{
	DEQUE_STACK,
	DEQUE_QUEUE
} DequeMode;

/**
 * struct Deque - deque node
 *
 * @data: integer
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 */

typedef struct DequeNode
{
	int data;
	struct DequeNode *prev;
	struct DequeNode *next;
} DequeNode;

/**
 * struct Deque - deque
 *
 * @head: pointer to head of the deque
 * @tail: pointer to tail of the deque
 * @size: size of the deque
 * @mode: mode of the deque
 */

typedef struct Deque
{
	DequeNode *head;
	DequeNode *tail;
	size_t size;
	DequeMode mode;
} Deque;

/* interface */

bool deque_is_empty(void);
void deque_push_front(int data);
void deque_push_back(int data);
void deque_push(int data);
int deque_pop_front(void);
int deque_pop_back(void);
int deque_peek(void);
size_t deque_get_size(void);
DequeMode deque_get_mode(void);
void deque_set_mode(DequeMode mode);
void deque_print(void);
void deque_free(void);

/* implementation */

Deque *_deque_get(void);
DequeNode *_deque_node_init(int data);
void _deque_init_nodes(DequeNode *node);
void _deque_push_front(int data);
void _deque_push_back(int data);
int _deque_pop_front(void);
int _deque_pop_back(void);

/* Tokenizer */

typedef char *Token;
typedef char **Tokens;

Tokens tokenize(const char *str);
void free_tokens(Tokens tokens);

/* Tokens hander */

void handle_tokens(Tokens tokens, size_t line_number);

/* Instructions */

void instruction_unknown(Tokens tokens, size_t line_number);
void instruction_push(Tokens tokens, size_t line_number);
void instruction_pall(void);
void instruction_pint(size_t line_number);
void instruction_pop(size_t line_number);
void instruction_swap(size_t line_number);
void instruction_add(size_t line_number);
void instruction_nop(void);
void instruction_sub(size_t line_number);
void instruction_div(size_t line_number);
void instruction_mul(size_t line_number);
void instruction_mod(size_t line_number);
void instruction_pchar(size_t line_number);
void instruction_pstr(void);
void instruction_rotl(void);
void instruction_rotr(void);
void instruction_stack(void);
void instruction_queue(void);

/* Utils */

bool is_integer(const char *str);
bool is_ascii(char c);
char *_strdup(const char *str);

#endif /* !MONTEY_H */

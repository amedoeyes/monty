#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stddef.h>

typedef char *Token;
typedef char **Tokens;

Tokens tokenize(const char *str);
void free_tokens(Tokens tokens);

#endif /* !TOKENIZER_H */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "tokenizer.h"

void instruction_push(Tokens tokens, size_t line_number);
void instruction_pall(void);
void instruction_pint(size_t line_number);

#endif /* !INSTRUCTIONS_H */

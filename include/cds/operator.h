#ifndef CDS_OPERATOR_H
#define CDS_OPERATOR_H

#include "struct.h"

void *random_access_get(void *collection, u32 index);
void random_access_set(void *collection, void *value, u32 index);
void shift_right(void *collection, u32 start_index, u32 end_index);
void shift_left(void *collection, u32 start_index, u32 end_index);

void *sequence_access_get(void *node, u32 index);
void sequence_access_set(void *node, void *value, u32 index);

#endif

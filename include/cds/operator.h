#ifndef CDS_OPERATOR_H
#define CDS_OPERATOR_H

#include "struct.h"

void *random_access_get(DSCollection *collection, u32 index);
void random_access_set(DSCollection *collection, void *value, u32 index);
void shift_right(DSCollection *collection, u32 start_index, u32 end_index);
void shift_left(DSCollection *collection, u32 start_index, u32 end_index);

#endif

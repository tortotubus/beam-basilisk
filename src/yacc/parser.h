#include <string.h>
#include <assert.h>
#include <stdlib.h>
  
#include "node.h"
#include "allocator.h"

typedef struct {
  Allocator * alloc;
} ParseParams;

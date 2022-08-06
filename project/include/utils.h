#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include "dataStruct.h"

#define filename "transaction.dat";

void transactionWrite(FILE *ofPtr, Data transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_

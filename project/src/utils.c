#include "utils.h"

void transactionWrite(FILE *ofPtr, Data transfer) {
        printf("%s\n%s\n",
                "1 Number account: ",
                "2 Client cash payments: ");
         while ( scanf("%d%lf", &transfer.Number, &transfer.cash_payments) != -1 ) {
            fprintf(ofPtr, "%-3d%-6.2f\n", transfer.Number, transfer.cash_payments);
            printf("1 Number account: %12d\n2 Client cash payments: %12.2f\n", transfer.Number,
             transfer.cash_payments);
        }
}

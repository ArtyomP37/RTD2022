#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dataStruct.h"
#include "utils.h"
#include "blackRecord.h"
#include "masterWrite.h"

    int main(void) {
        int choice = 0;
        FILE *record, *transaction, *blackRecord;
        Data client_data = {0};
        Data transfer = {0};
        printf("please enter action\n1 enter data client: \n2 enter data transaction: \n3 update base\n\n");
        while (scanf("%d", &choice) != -1) {
            switch (choice) {
                case 1:
                    record = fopen("record.dat", "r+");
                    if (record == NULL) {
                        puts("Not access");
                    } else {
                        masterWrite(record, client_data);
                        fclose(record);
                    }
                    break;
                case 2:
                    transaction = fopen("transaction.dat", "r+");
                    if (transaction == NULL) {
                        puts("Not access");
                    } else {
                        transactionWrite(transaction, transfer);
                        fclose(transaction);
                    }
                    break;
                case 3:
                    record = fopen("record.dat", "r");
                    transaction = fopen("transaction.dat", "r");
                    blackRecord = fopen("blackrecord.dat", "w");
                    if (record == NULL || blackRecord == NULL) {
                        puts("exit");
                    } else {
                        blackrecord(record, transaction, blackRecord, client_data, transfer);
                        fclose(record);
                        fclose(transaction);
                        fclose(blackRecord);
                    }
                    break;
                    default:
                    puts("error");
                    break;
            }
    printf("please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    }
    return 0;
    }

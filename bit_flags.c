//
//  bit_flags.c
//  Program 1
//
//  Created by Philopater Askander on 2/23/22.
//

//Include the header files.

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags{
    int size;
    int* data;
    int capacity;
};
typedef struct bit_flags Bit_Flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){
    Bit_Flags* pFlags = (Bit_Flags*)malloc(sizeof(Bit_Flags));
    if (pFlags != NULL){
        pFlags->size = number_of_bits;
        pFlags->capacity = ((number_of_bits / 32) + 1) * 32;
        pFlags->data = (int*)malloc(sizeof(int) * pFlags->capacity);
        if (pFlags->data == NULL){
            free(pFlags);
            return NULL;
        }
        else{
            for (int i = 0; i < (pFlags->capacity) / 32; i++){
                pFlags->data[i] = 0;
            }
        }
    }
    return pFlags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
    Bit_Flags* pFlags = (Bit_Flags*)hBit_flags;
    int* temp = (int*)malloc(sizeof(int));

    if (pFlags == NULL){
        return FAILURE;
    }

    if (pFlags->size <= flag_position){
        temp = (int*)malloc(sizeof(int)*((flag_position / 32) + 1) * 2);

        if (temp == NULL){
            return FAILURE;
        }

        for (int i = 0; i < ((flag_position / 32) + 1); i++){
            temp[i] = 0;
        }
        
        for (int j = 0; j < (1 + (pFlags->size) / 32); j++){
            temp[j] = pFlags->data[j];
        }
        
        free(pFlags->data);
        pFlags->size = flag_position - 1;
        pFlags->capacity = ((pFlags->size / 32) + 1) * 32;
        pFlags->data = temp;
        
    }
    int position = flag_position / 32;
    int condition = (flag_position - (32 * position));
    int shift = 1;
    
    if (condition < 0){
        printf("Invalid integer.\n");
        condition = 0 - condition;
    }

    shift = shift << condition;

    pFlags->data[position] = pFlags->data[position] | shift;
    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
    Bit_Flags* pFlags = (Bit_Flags*)hBit_flags;

    int* temp = (int*)malloc(sizeof(int));

    if (pFlags == NULL){
        return FAILURE;
    }

    if (pFlags->capacity <= flag_position){
        temp = (int*)malloc(sizeof(int)*((flag_position / 32) + 1) * 2);

        if (temp == NULL){
            return FAILURE;
        }


        for (int i = 0; i < ((flag_position / 32) + 1); i++){
            temp[i] = 0;
        }

        for (int j = 0; j < (1 + (pFlags->size) / 32); j++){
            temp[j] = pFlags->data[j];
        }

        free(pFlags->data);
        pFlags->data = temp;
        pFlags->size = flag_position - 1;
        pFlags->capacity *= ((pFlags->size / 32) + 1) * 32;
    }

    int unset = 1;
    int position = flag_position / 32;
    int condition = (flag_position - (32 * position));
    if (condition < 0){
        condition = 0 - condition;
    }

    unset = unset << condition;
    pFlags->data[position] = pFlags->data[position] & ~unset;
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
    Bit_Flags* pFlags = (Bit_Flags*)hBit_flags;

    int shift = 1;

    if ( flag_position > pFlags->capacity || flag_position < 0 || pFlags->size > pFlags->capacity){
        printf("ERROR\n");
        return -1;
    }

    int conversion = flag_position / 32;
    int position = (flag_position - (32 * conversion));
    shift <<= position;
    if ((shift & pFlags->data[conversion]) != 0){
        return 1;
    }

    return 0;
}


int bit_flags_get_size(BIT_FLAGS hBit_flags){
    Bit_Flags* pFlags = (Bit_Flags*)hBit_flags;
    return pFlags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
    Bit_Flags* pFlags = (Bit_Flags*)hBit_flags;
    return pFlags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags){
    Bit_Flags* pFlags = (Bit_Flags*)*phBit_flags;
    free(pFlags->data);
    free(pFlags);
    *phBit_flags = NULL;
}

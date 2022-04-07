//
//  main.c
//  Program 1
//
//  Created by Philopater Askander on 2/23/22.
//

//Include the header files.
#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

void print_flags(BIT_FLAGS hBit_Flags);

int main(int argc, const char * argv[]){
    BIT_FLAGS hBit_Flags;
    if ((hBit_Flags = bit_flags_init_number_of_bits(128)) == NULL){
        printf("Failed to create handle.\n");
        exit(1);
    }
    
    bit_flags_set_flag(hBit_Flags, 1);
    bit_flags_set_flag(hBit_Flags, 2);
    bit_flags_set_flag(hBit_Flags, 99);
    
    print_flags(hBit_Flags);
    printf("Size: %d\nCapacity: %d\n", bit_flags_get_size(hBit_Flags), bit_flags_get_capacity(hBit_Flags));
    bit_flags_unset_flag(hBit_Flags, 2);
    print_flags(hBit_Flags);
    bit_flags_destroy(&hBit_Flags);
    
    return 0;
}

void print_flags(BIT_FLAGS hBit_Flags)
{
    int i, j;
    for (i = 0; i < bit_flags_get_capacity(hBit_Flags) / 32; i++)
    {
        for (j = 0; j < 32; j++)
        {
            printf("%d", bit_flags_check_flag(hBit_Flags, i * 32 + j));
            if ((j + 1) % 4 == 0)
                printf(" ");
        }
        printf("\n");
    }
}

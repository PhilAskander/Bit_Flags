//
//  bit_flags.h
//  Program 1
//
//  Created by Philopater Askander on 2/23/22.
//

//Include the header files.
/***********************************************************
Author: Philopater Askander
Date: 2-22-2022
Effort: A couple months
Purpose: Make an opaque object wrapper that allows for all the behaviors we want in a bit collection data structure called BIT_FLAGS.
Interface proposal: An additional funtion we can implement is an "is empty" function and what that function entails is it consists of a set of code that determines if the size is less than  0 and return a boolean expression. This allows us to terminate the program completely in the event that the size doesn't increase when requested.
***********************************************************/
#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "Status.h"
typedef void* BIT_FLAGS;
//Intentionally leaving out a default init function to force user to at least guess at the size needed. //If one WERE to be used it would have the following prototype:
//BIT_FLAGS bit_flags_init_default(void);
//Precondition: number of bits is a positive integer.
//Postcondition: Returns the handle to a valid Bit_flags object that has the ability to store up to
// number_of_bits bits but currently all flags are set at zero. Returns NULL on failure. The container // is assumed to hold size=number_of_bits after the init function runs.
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);
//Precondition: flag_position is a non-negative integer and hBit_flags is a handle to a valid Bit_flags object. //Postcondition: The flag at the flag_position index is set to 1. Function will attempt to resize the
// internal representation if the flag_position is too large instead of failing for out of bounds. Returns
// SUCCESS if the operation is successful and FAILURE if the operation fails a needed resize. This
// operation is considered to be expensive if flag_position is constantly going out of bounds by a small
// amount because the resize always attempts to minimize the amount of space required to store the bits.
// All new flags created in a resize operation (except the one being set) will be set as zero.
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);
//Precondition: flag_position is a non-negative integer and hBit_flags is a handle to a valid Bit_flags object. //Postcondition: The flag at the flag_position index is set to 0. Function will attempt to resize the
// internal representation if the flag_position is too large instead of failing for out of bounds. Returns
// SUCCESS if the operation is successful and FAILURE if the operation fails a needed resize. This
// operation is considered to be expensive if flag_position is constantly going out of bounds by a small
// amount because the resize always attempts to minimize the amount of space required to store the bits.
// All new flags created in a resize operation will be set as zero.
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);
//Precondition: flag_position is a non-negative integer and hBit_flags is a handle to a valid Bit_flags object. //Postcondition: returns the value of the flag at index flag_position if it is in bounds or -1 otherwise.
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);
//Precondition: hBit_flags is a handle to a valid Bit_flags object. //Postcondition: returns the number of bits currently held by the data structure.
int bit_flags_get_size(BIT_FLAGS hBit_flags);
//Precondition: hBit_flags is a handle to a valid Bit_flags object. //Postcondition: returns the number of bits the object CAN hold.
int bit_flags_get_capacity(BIT_FLAGS hBit_flags);
//Precondition: phBit_flags is the address of a handle to a valid Bit_flags object.
//Postcondition: The memory for the object referred to by the handle is free'd and the handle is set to NULL.
void bit_flags_destroy(BIT_FLAGS* phBit_flags);
#endif

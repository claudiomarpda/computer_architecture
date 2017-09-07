//
// Created by mz on 06/09/17.
//

#include "../include/control_unit.h"
#include "../include/memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Fetches the next instruction according to program counter.
 *
 * @return an instruction as string
 */
char *fetch(char instructionMemory[][INSTRUCTION_LENGTH]) {

    if (LOG) {
        printf("Fetching...\n");
    }
    // check empty instruction
    if (strcmp(instructionMemory[pc], "") == 0) {
        return NULL;
    } else {
        return instructionMemory[pc++];
    }
}

/**
 * Decodes an instruction in pieces and handles every string.
 *
 * @param instruction
 */
void decode(const char *instruction) {

    if (LOG) {
        printf("%s", instruction);
        puts("Decoding...");
    }

    // Get the instruction size
    size_t iSize = strlen(instruction);
    // A copy of the instruction
    char instructionCopy[iSize];
    strcpy(instructionCopy, instruction);

    // Will keep every piece of an instruction, one by one.
    // Examples: LOAD, 0, MOVE, R1...
    char *token = NULL;

    // Get the operation
    token = strtok(instructionCopy, " ");
    if (strcmp(token, "LOAD") == 0) {
        // Example: LOAD R ADDRESS
        // Load the value from the address into the register

        // Get the first operand, which must be a register
        token = strtok(NULL, " ");
        if (token[0] == 'R') {
            operand1 = token[1] - '0'; // the number of the register
            operand1 -= 1; // decrements 1 to fit in the index of the registers
        }

        // Get the second operand, which must be an address
        token = strtok(NULL, " ");
        operand2 = atoi(token);

        operation = LOAD;

    } else if (strcmp(token, "MOVE") == 0) {
        // TODO: Handle the decoding of this operation
        operation = MOVE;

    } else if (strcmp(token, "STORE") == 0) {
        // TODO: Handle the decoding of this operation
        operation = STORE;
    } else if (strcmp(token, "ADD") == 0) {
        // TODO: Handle the decoding of this operation
        operation = ADD;
    } else if (strcmp(token, "SUBTRACT") == 0) {
        // TODO: Handle the decoding of this operation
        operation = SUBTRACT;
    } else if (strcmp(token, "MULTIPLY") == 0) {
        // TODO: Handle the decoding of this operation
        operation = MULTIPLY;
    } else if (strcmp(token, "DIVIDE") == 0) {
        // TODO: Handle the decoding of this operation
        operation = DIVIDE;
    } else if (strcmp(token, "JUMP") == 0) {
        // TODO: Handle the decoding of this operation
        operation = JUMP;
    }
}

/**
 *
 * @param operation
 */
void execute(const int operation) {
    switch (operation) {
        case LOAD:
            puts("LOAD operation");
            mar = operand2;
            mbr = indirectMemoryAccess(mar);
            reg[operand1] = mbr;

            if (LOG) {
                printf("R%d receives %d from address %d\n\n", operand1 + 1, reg[operand1], mar);
            }
            break;
        case MOVE:
            puts("MOVE operation\n\n");
            // TODO: Handle the execution of this operation
            break;
        case STORE:
            puts("STORE operation\n\n");
            // TODO: Handle the execution of this operation
            break;
        case ADD:
            puts("ADD operation\n\n");
            // TODO: Handle the execution of this operation
            break;
        case SUBTRACT:
            puts("SUBTRACT operation\n\n");
            // TODO: Handle the execution of this operation
            break;
        case MULTIPLY:
            puts("MULTIPLY operation\n\n");
            // TODO: Handle the execution of this operation
            break;
        case DIVIDE:
            puts("DIVIDE operation\n\n");
            // TODO: Handle the execution of this operation
            break;
        case JUMP:
            puts("JUMP operation\n\n");
            // TODO: Handle the execution of this operation
            break;
    }
}
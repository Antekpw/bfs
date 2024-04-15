#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Header {
    uint32_t File_Id;
    uint32_t Steps;
    uint8_t Escape;
    uint16_t Columns;
    uint16_t Lines;
    uint16_t Entry_X;
    uint16_t Entry_Y;
    uint16_t Exit_X;
    uint16_t Exit_Y;
    uint32_t Reserved[3];
    uint32_t Counter;
    uint32_t Solution_Offset;
    uint8_t Separator;
    uint8_t Wall;
    uint8_t Path;
} Header_t;

typedef struct maze_Constructor {
    uint8_t Separator;
    uint8_t Value;
    uint8_t Count;
    uint8_t Direction;
    uint8_t Counter;
} maze_Constructor_t;

void readBinary(FILE *coded_File, Header_t *header, maze_Constructor_t *bin_maze, FILE *decoded_maze);
int steps_to_File_and_bin(FILE *in,FILE *out,int x0, int y0,int xk,int yk,int w,FILE *write_to, Header_t *header, maze_Constructor_t *bin_maze);
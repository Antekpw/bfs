#include "binaryDecoder.h"

void readBinary(FILE *coded_File, Header_t *header, maze_Constructor_t *bin_maze, FILE *decoded_maze) {
    // czytanie naglowka pliku binarnego
    fread(&header->File_Id, sizeof(uint32_t), 1, coded_File);
    fread(&header->Escape, sizeof(uint8_t), 1, coded_File);
    fread(&header->Columns, sizeof(uint16_t), 1, coded_File);
    fread(&header->Lines, sizeof(uint16_t), 1, coded_File);
    fread(&header->Entry_X, sizeof(uint16_t), 1, coded_File);
    fread(&header->Entry_Y, sizeof(uint16_t), 1, coded_File);
    fread(&header->Exit_X, sizeof(uint16_t), 1, coded_File);
    fread(&header->Exit_Y, sizeof(uint16_t), 1, coded_File);
    fread(&header->Reserved[0], sizeof(uint32_t), 1, coded_File);
    fread(&header->Reserved[1], sizeof(uint32_t), 1, coded_File);
    fread(&header->Reserved[2], sizeof(uint32_t), 1, coded_File);
    fread(&header->Counter, sizeof(uint32_t), 1, coded_File);
    fread(&header->Solution_Offset, sizeof(uint32_t), 1, coded_File);
    fread(&header->Separator, sizeof(uint8_t), 1, coded_File);
    fread(&header->Wall, sizeof(uint8_t), 1, coded_File);
    fread(&header->Path, sizeof(uint8_t), 1, coded_File);
    int counter = 0;
    int start = (header->Columns) * (header->Entry_Y-1) + (header->Entry_X-1);
    int end = (header->Columns) * (header->Exit_Y-1) + (header->Exit_X-1);

    for (int i = 0; i < header->Counter; i++) {
        fread(&bin_maze->Separator, sizeof(uint8_t), 1, coded_File);
        fread(&bin_maze->Value, sizeof(uint8_t), 1, coded_File);
        fread(&bin_maze->Count, sizeof(uint8_t), 1, coded_File);
        // wypisywanie do pliku decoded.txt odkodowanego labiryntu
        for (int j = 0; j <= bin_maze->Count; j++) {
            if (counter % header->Columns == 0 && counter != 0) {
                fputc('\n', decoded_maze);
            }
            if (counter == start)
                fputc('P', decoded_maze);
            else if (counter == end)
                fputc('K', decoded_maze);
            else
                fputc((char)bin_maze->Value, decoded_maze);
            counter++; 
        }
    }

    printf("Odczyt pliku binarnego udany\n");
}


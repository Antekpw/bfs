#include "binaryDecoder.h"

int main(int argc, char **argv) {

    FILE *final_maze = fopen("decoded.txt", "w");
    FILE *binary_coded_file = fopen(argv[1], "rb");

    Header_t *header = malloc(sizeof(Header_t));
    maze_Constructor_t *maze_frame = malloc(sizeof(maze_Constructor_t));
    
    readBinary(binary_coded_file, header, maze_frame, final_maze);

    fclose(binary_coded_file);
    fclose(final_maze);

    free(header);
    free(maze_frame);

    return 0;
}
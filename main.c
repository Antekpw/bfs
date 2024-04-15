#include "readFile.h"
#include "parents.h"
#include "fbs.h"
#include "floodfill.h"
#include "bfs.h"
#include "binaryDecoder.h"
int main(int argc, char **argv){
  //wywołanie z plikiem binarnym ./maze <nazwa pliku binarnego> <nazwa pliku wynikowego>
  if(argc==3){
    FILE *final_maze = fopen(argv[2], "w");
    FILE *binary_coded_file = fopen(argv[1], "rb");
    Header_t *header = malloc(sizeof(Header_t));
    maze_Constructor_t *maze_frame = malloc(sizeof(maze_Constructor_t));
    
    readBinary(binary_coded_file, header, maze_frame, final_maze);

    fclose(binary_coded_file);
    fclose(final_maze);
    free(header);
    free(maze_frame);

    FILE *in = fopen(argv[2],"r+");
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
    floodfill(in,x0,y0,xk,yk,w,h);
    zamiana(in);
    bfs(in, x0, y0, xk, yk, w, h, false);
    clearpath(in);
    blankpath(in);
    clearmaze(in,x0,y0,xk,yk);
    fclose(in);
  }
  //wywołanie bez pliku binarnego: ./maze <nazwa pliku z labiryntem>
  if(argc==2){
    FILE *in = fopen(argv[1],"r+");
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
    floodfill(in,x0,y0,xk,yk,w,h);
    zamiana(in);
    bfs(in, x0, y0, xk, yk, w, h, false);
    clearpath(in);
    blankpath(in);
    clearmaze(in,x0,y0,xk,yk);
    checkup2(x0,y0,in,w);
    //turns(x0, y0, in, w);
    fclose(in);
  }
    
}
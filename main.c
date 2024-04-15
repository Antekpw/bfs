#include "readFile.h"
#include "floodfill.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "bfs.h"
#include "binaryDecoder.h"
int main(int argc, char **argv){
  //wywołanie bez pliku binarnego: ./maze <nazwa pliku z labiryntem>
  if(argc==2){
    FILE *in = fopen(argv[1],"r+");
    FILE *out = fopen("Steps.txt","w");
    if(out==NULL){
      fprintf(stderr,"blad z plikem wyjsciowym\n");
      return 1;
      }
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
    floodfill(in,x0,y0,xk,yk,w,h);
    zamiana(in);
    bfs(in, x0, y0, xk, yk, w, h, false);
    int ile_curves = steps_to_File(in,out,x0,y0,xk,yk,w);
    zamiana2(in);
    fclose(out);
    }
  //wywołanie z plikiem binarnym ./maze <nazwa pliku binarnego> <nazwa pliku wynikowego>
  if(argc==3){
    FILE *binary_coded_file = fopen(argv[1], "rb");
    FILE *final_maze = fopen(argv[2], "w");
    Header_t *header = malloc(sizeof(Header_t));
    maze_Constructor_t *maze_frame = malloc(sizeof(maze_Constructor_t));

    readBinary(binary_coded_file, header, maze_frame, final_maze);

    fclose(binary_coded_file);
    fclose(final_maze);
    //free(header);
    //free(maze_frame);

    FILE *in = fopen(argv[2],"r+");
    FILE *out = fopen("Steps.txt","w");
    if(out==NULL){
      fprintf(stderr,"blad z plikem wyjsciowym\n");
      return 1;
      }
    FILE *binary_write = fopen(argv[1], "ab");
    int x0, y0, xk, yk,w,h;
    read(in,&x0,&y0,&xk,&yk,&w,&h);
    floodfill(in,x0,y0,xk,yk,w,h);
    zamiana(in);
    bfs(in, x0, y0, xk, yk, w, h, false);
    uint32_t Steps = steps_to_File_and_bin(in,out,x0,y0,xk,yk,w,binary_write,header,maze_frame);
    zamiana2(in);
    fclose(out);
    
  }
  printf("Labirynt rozwiazany!\n");
  return 0;
}

#include "binaryDecoder.h"
#include "readFile.h"
#include "queue.h"
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

int steps_to_File_and_bin(FILE *in,FILE *out,int x0, int y0,int xk,int yk,int w,FILE *write_to, Header_t *header, maze_Constructor_t *bin_maze){
    fseek(write_to, 970700, SEEK_SET);
    int forward_count = 0;
    int dir = 1;
    int x=0,y=0;
    markPath_visited(in,x0,y0,w);
    queue q = NULL;
    q = enqueue(q,x0,y0);
    int ile_curves = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    int stop = 0;
    fprintf(out,"START\n");
    while(q!=NULL && stop == 0 ){
        q = dequeue(q,&x,&y);
        if(x==xk && y == yk){
            forward_count++;
            fprintf(out,"MOVE FORWARD %d\n",forward_count);
            fprintf(out,"STOP\n");
            stop = 1;
            return (ile_curves+1);
        }
        for(int i=0;i<4;i++){   
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isInvalidPosition(in,newx,newy,w)==1){
                continue;
            }
            if(isPath(in,newx,newy,w)==0){
                markPath_visited(in,newx,newy,w);
                forward_count++;
                if(dir == i){
                    q = enqueue(q,newx,newy);
                }
                if(dir!=i){
                    ile_curves++;
                    fprintf(out,"MOVE FORWARD %d\n",forward_count);
                    if(dir==0){
                        bin_maze->Direction='N';
                        fwrite(&bin_maze->Direction, sizeof(uint8_t), 1, write_to);
                        bin_maze->Counter=forward_count;
                        fwrite(&bin_maze->Counter, sizeof(uint8_t), 1, write_to);
                    } //N
                    if(dir==1){
                        bin_maze->Direction='E';
                        fwrite(&bin_maze->Direction, sizeof(uint8_t), 1, write_to);
                        bin_maze->Counter=forward_count;
                        fwrite(&bin_maze->Counter, sizeof(uint8_t), 1, write_to);
                    } //E
                    if(dir==2){
                        bin_maze->Direction='S';
                        fwrite(&bin_maze->Direction, sizeof(uint8_t), 1, write_to);
                        bin_maze->Counter=forward_count;
                        fwrite(&bin_maze->Counter, sizeof(uint8_t), 1, write_to);
                    } //S
                    if(dir==0){
                        bin_maze->Direction='W';
                        fwrite(&bin_maze->Direction, sizeof(uint8_t), 1, write_to);
                        bin_maze->Counter=forward_count;
                        fwrite(&bin_maze->Counter, sizeof(uint8_t), 1, write_to);
                    } //W
                    forward_count = 0;
                    if(dir==0){
                        switch(i){
                            case 1 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 3 :
                            fprintf(out,"TURN LEFT\n");
                            break;
                        }
                    }
                    if(dir==1){
                        switch(i){
                            case 2 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 0 :
                            fprintf(out,"TURN LEFT\n");
                            break;
                        }
                    }
                    if(dir==2){
                        switch(i){
                            case 3 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 1:
                            fprintf(out,"TURN LEFT\n");
                            break;
                    }
                    }
                    if(dir==3){
                        switch(i){
                            case 0 :
                            fprintf(out,"TURN RIGHT\n");
                            break;
                            case 2 :
                            fprintf(out,"TURN LEFT\n");
                            break;
                        }
                    }
                    dir = i;
                    q = enqueue(q,newx,newy);
                    break;
                }
            }   
            }   
        }
        
}
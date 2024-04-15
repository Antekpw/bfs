#include "parents.h"
#include <stdlib.h>
#include <stdio.h>

int checkup(int x,int y,FILE *in,int w){
    fseek(in,(y-1)*w +x,SEEK_SET);
    char c = fgetc(in);
     if(c==' ' || c == '+' || c == 'P' || c == 'K'){
        return 0;
    }
    return 1;
}
int checkdown(int x,int y,FILE *in,int w){
    fseek(in,(y+1)*w +x,SEEK_SET);
    char c = fgetc(in);
     if(c==' ' || c == '+' || c == 'P' || c == 'K'){
        return 0;
    }
    return 1;
}
int checkleft(int x, int y, FILE *in, int w){
    fseek(in,y*w + x -1,SEEK_SET);
    char c = fgetc(in);
     if(c==' ' || c == '+'|| c == 'P' || c == 'K'){
        return 0;
    } else {
    return 1;
    }
}
int checkright(int x, int y, FILE *in, int w){
    fseek(in,y*w + x + 1,SEEK_SET);
    char c = fgetc(in);
    if(c==' ' || c == '+'|| c == 'P' || c == 'K'){
        return 0;
    } else {
    return 1;
    }
}
int check_if_node(int x,int y,FILE *in,int w){
   /* if(checkleft(x,y,in,w) == 1 && checkright(x,y,in,w) == 1){
        return 1;
    }
    if(checkleft(x,y,in,w) != 1 ||  checkright(x,y,in,w) != 1){
        if((checkup(x,y,in,w)!= 1) || (checkdown(x,y,in,w) != 1)){
            return 0;
        } else {
            return 1;
        }
    */
   int count = 0;
   if(checkup(x,y,in,w)==0){
    count++;
   }
    if(checkdown(x,y,in,w)==0){
    count++;
   }
    if(checkright(x,y,in,w)==0){
    count++;
   }
    if(checkleft(x,y,in,w)==0){
    count++;
   }
   if(count>=3){
        return 0;
   }
   return 1;
}

int checkup2(int x,int y,FILE *in,int w){
    fseek(in,(y-1)*w +x,SEEK_SET);
    char c = fgetc(in);
    //printf("%c ", c);
    if(c=='X' ){
        return 0;
    }
    return 1;
}
int checkdown2(int x,int y,FILE *in,int w){
    fseek(in,(y+1)*w +x,SEEK_SET);
    char c = fgetc(in);
   // printf("%c ", c);
    if(c=='X'){
        return 0;
    }
    return 1;
}
int checkleft2(int x, int y, FILE *in, int w){
    fseek(in,y*w + x -1,SEEK_SET);
    char c = fgetc(in);
    //printf("%c ", c);
    if(c=='X'){
        return 0;
    } 
    return 1;
    
}
int checkright2(int x, int y, FILE *in, int w){
    fseek(in,y*w + x + 1,SEEK_SET);
    char c = fgetc(in);
    //printf("%c ", c);
    if(c=='X'){
        return 0;
    }
    return 1;
    
}
int checkifdeadend(FILE *in,int x, int y, int w){
    fseek(in,y*w + x, SEEK_SET);
    if (fgetc(in) != ' '){
        return 1;
    }

    fseek(in, -1 , SEEK_CUR);
    int count = 0;
    if(checkdown2(x,y,in,w)==0){
        //printf("pod punktem (%d,%d) jest X\n",x,y);
        count++;
    }
    if(checkup2(x,y,in,w)==0){
        //printf("nad punktem (%d,%d) jest X\n",x,y);
        count++;
    }
    if(checkleft2(x,y,in,w)==0){
        //printf("na lewo od punktu (%d,%d) jest X\n",x,y);
        count++;
    }
    if(checkright2(x,y,in,w)==0){
        //printf("na prawo od punktu (%d,%d) jest X\n",x,y);
        count++;
    }
    if(count>=3){
        return 0;
    }
    //printf("ścian jest mniej niż 3\n");
    return 1;
 
}
int check_if_node_marked(int x, int y, FILE *in, int w){
    fseek(in,y*w + x,SEEK_SET);
    char c = fgetc(in);
    if(c=='N'){
        return 0;
    }
return 1;}


#include <stdio.h>


int checkup(int x,int y,FILE *in,int w);
int checkdown(int x ,int y,FILE *in, int w);
int checkleft(int x ,int y,FILE *in, int w);
int checkright(int x ,int y,FILE *in, int w);

int checkup2(int x,int y,FILE *in,int w);
int checkdown2(int x ,int y,FILE *in, int w);
int checkleft2(int x ,int y,FILE *in, int w);
int checkrigh2t(int x ,int y,FILE *in, int w);

int check_if_node(int x,int y,FILE *in,int w);
int checkifdeadend(FILE *in,int x, int y, int w);
int check_if_node_marked(int x, int y, FILE *in, int w);
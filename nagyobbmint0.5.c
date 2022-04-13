#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BEMENET "in.txt"
#define KIMENET "out.txt"
#define BUFFER 1000

int main(){
    FILE* in = fopen(BEMENET,"r");
    if(in != NULL){
        fprintf(stderr, "# in.txt sikeresen megnyitva");
    }
    FILE* out = fopen(KIMENET,"w");
    char line[BUFFER];
    int counter=0;
    printf("# 0,5-nél nagyobb számok szűrése...\n");
    while(fgets(line,BUFFER,in) != NULL){
        line[strlen(line)-1] = '\0';
        if(atof(line) > 0.5){
            fprintf(out,"%s\n",line);
            counter++;
        }
    }
    printf("# szűrés vége\n");
    fclose(in);
    fclose(out);
    printf("# out.txt bezárva\n");
    printf("# out.txt-be kiírt számok mennyisége: %d db\n",counter);

return 0;

}
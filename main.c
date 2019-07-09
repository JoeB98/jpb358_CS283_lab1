#include<stdio.h>
#include<stdlib.h>
void problem1() {
    int x = 5;
    int *array;
    array = (int *)malloc(sizeof(int)*10);
    for(int i=0; i<10; i++){
        array[i]=i+1;
        printf("%d\n",array[i]);
    }
    free(array);
    return;
}
void problem2(){
    char** array = malloc(10*sizeof(char*));
    for(int i=0; i<10; i++){
        array[i]=malloc(15*sizeof(char));
    }
    array[0] = "abstractionists\0";
    array[1] = "acquisitiveness\0";
    array[2] = "channelizations\0";
    array[3] = "descriptiveness\0";
    array[4] = "electromagnetic\0";
    array[5] = "hallucinogenics\0";
    array[6] = "instructionally\0";
    array[7] = "microscopically\0";
    array[8] = "objectification\0";
    array[9] = "unpronounceable\0";
    for(int i=0; i<10; i++){
        printf(array[i]);
        printf("\n");
    }
    return;
}
int main(){
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    return 0;
}
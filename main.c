#include<stdio.h>
#include<stdlib.h>
void problem1() {
    int *array;
    array = (int*)malloc(sizeof(int)*10);
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
void sort(int size, int* a){
    //ints to use for ordering stuff
    int x, y, z;
    for(x = 0; x < size; x++) {
        for(y = x + 1; y < size; y++) {
            //compares the dereferenced pointers to see which is smaller
            if(*(a + y) < *(a + x)) {
                //if the comparator passes a true set temp = to first val changed
                z = *(a + x);
                //set first val to second
                *(a + x) = *(a + y);
                //set second val to first
                *(a + y) = z;
            }
        }
    }
    for(int i = 0; i < size; i++){
        printf("%d\n", *(a + i));
    }
}
void problem3(){
    int size = 10;
    int arr[] = {9, 6, 0, 5, 3, 7, 4, 8, 1, 2};
    sort(size, arr);
    return;
}

int main(){
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");
    return 0;
}
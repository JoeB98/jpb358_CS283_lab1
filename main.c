#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*typedef struct node{
    int data;
    struct node * next;
} nodeL;*/
void problem1() {
    int *array;
    array = (int*)malloc(sizeof(int)*10);
    for(int i=0; i<10; i++){
        array[i]=i+1;
        printf("%d\n",array[i]);
    }
    free(array);
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
}
//code for this function largely taken from https://www.geeksforgeeks.org/c-program-to-sort-an-array-using-pointers/
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
}
/*int listSort(){
    nodeL * head = NULL;
    head = malloc(sizeof(nodeL));
    if(head == NULL){
        return 1;
    }
    head->data = 1;
    head->next = NULL;
}*/
void problem4(){
   struct node {
       int data;
       struct node* next;
   };

   void sort(struct node* start){
       if(start->data > start->next->data){
           struct node* temp = start;
           start = start->next;
           start->next = temp;
       }
       struct node* currNode = start->next;
       while(currNode != NULL){
           if(currNode->data > currNode->next->data){
               struct node* temp = currNode;
               currNode = currNode->next;
               currNode->next = temp;
           }
           currNode = currNode->next;
       }
       struct node* currNodeCheck = start->next;
       while(currNodeCheck != NULL){
           if(currNodeCheck->data > currNodeCheck->next->data){
               sort(start);
           }
           currNodeCheck = currNodeCheck->next;
       }
   }
   struct node first = {10};
   struct node* firstpoint = &first;
   struct node second = {2};
   struct node* secondpoint = &second;
   struct node third = {7};
   struct node* thirdpoint = &third;
   struct node fourth = {3};
   struct node* fourthpoint = &fourth;
   struct node fifth = {8};
   struct node* fifthpoint = &fifth;
   struct node sixth = {9};
   struct node* sixthpoint = &sixth;
   struct node seventh = {5};
   struct node* seventhpoint = &seventh;
   struct node eigth = {6};
   struct node* eigthpoint = &eigth;
   struct node ninth = {1};
   struct node* ninthpoint = &ninth;
   struct node tenth = {4};
   struct node* tenthpoint = &tenth;
   
   firstpoint->next = secondpoint;
   secondpoint->next = thirdpoint;
   thirdpoint->next = fourthpoint;
   fourthpoint->next = fifthpoint;
   fifthpoint->next = sixthpoint;
   sixthpoint->next = seventhpoint;
   seventhpoint->next = eigthpoint;
   eigthpoint->next = ninthpoint;
   ninthpoint->next = tenthpoint;
   tenthpoint->next = NULL;
   
   sort(firstpoint);
   struct node* end = firstpoint;
   while(end != NULL){
       printf("%d", end->data);
       printf("\n");
       end = end->next;
   }
}
void add(int element, int* arr, int loc){
    arr[loc] = element;
}
void removeLast(int* arr, int memSize){
    //arr = (int*)realloc(arr, sizeof(int)*(memSize-1));
}
int get(int* arr, int index){
    return arr[index];
}
void problem5(int n){
    int size = 0;
    int* array = (int*)malloc(sizeof(int)*size);
    double total_time;
    clock_t start, end;
    size=5;
    start=clock();
    srand(time(NULL));
    for(int i=0; i<n; i++){
        size++;
        array = realloc(array, size*sizeof(int));
        add(i, array, i);
    }
    end=clock();
    total_time = ((double)(end-start));
    printf("\nTotal time taken to run for %d elements is: %f",n ,total_time);
}
int main(){
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");
    //problem4();
    problem5(100000);
    problem5(200000);
    return 0;
}
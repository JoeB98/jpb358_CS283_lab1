#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
//code worked on with Josh Kirschner jak423
void problem4(){
   //node keeps it's value in data and has a pointer to the next node
   struct node {
       int data;
       struct node* next;
   };
   //switches two nodes and returns the second node so the previous in the list can be linked.
   struct node* swap2nodes(struct node* a, struct node* b){
       struct node* bpointer = b->next;
       b->next = a;
       a->next = bpointer;
       return b;
   } 
   struct node* sort(struct node* start){
       //first swap is to make sure the first two nodes are in order
       if(start->data > start->next->data){
           start = swap2nodes(start, start->next);
       }
       printf("\n");
       //these are pointers to the locations of the current and last node
       struct node** currNodePoint = &start;
       struct node** lastNodePoint = NULL;
       while((*currNodePoint)->next != NULL){
           printf("%d", (*currNodePoint)->data);
           printf(" vs ");
           printf("%d", (*currNodePoint)->next->data);
           printf("\n");
           if((*currNodePoint)->data > (*currNodePoint)->next->data){
               printf("SWAP");
               printf("\n");
               //this is what connects the last node to the newly swapped node
               (*lastNodePoint)->next = swap2nodes((*currNodePoint), (*currNodePoint)->next);
           }
           printf("%d", (*currNodePoint)->data);
           printf("\n");
           lastNodePoint = currNodePoint;
           currNodePoint = &(*currNodePoint)->next;
           
       }
       //this checks to see if the list is fully sorted
       //if it isn't it recursively calls the sort function again
       struct node** currNodeCheck = &start;
       while((*currNodeCheck)->next != NULL){
           if((*currNodeCheck)->data > (*currNodeCheck)->next->data){
               sort(start);
           }
           currNodeCheck = &(*currNodeCheck)->next;
       }
       return start;
   }
   //setup nodes
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
   
   //connect nodes
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
   
   //sort and list nodes
   sort(firstpoint);
   printf("\n");
   struct node* end = ninthpoint;
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
    problem4();
    printf("\n");
    problem5(100000);
    printf("\n");
    problem5(200000);
    printf("\n");
    return 0;
}
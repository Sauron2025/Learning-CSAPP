#include <stdio.h>


typedef unsigned char *ptr;



void print_bytes(ptr byte_ptr,size_t len){

    int i;
    for(i=0;i<len;i++){
        printf(" %i",byte_ptr[i]);
    }

    printf("\n");
};


void show_int(int x){
    print_bytes((ptr)&x,sizeof(x));
};

void show_float(float x){
    print_bytes((ptr)&x,sizeof(x));
};

void show_ptr(void *x){
    print_bytes((ptr)&x,sizeof(void*));
};

void show_char(char x){
    print_bytes((ptr) &x,sizeof(x));
};


int main(){
    int i;
    scanf("%d",&i);

    float f = (float) i;
    char c = (char) i;

    show_int(i);
    show_float(f);
    show_ptr(&i);
    show_char(c);


    char c2 = 'a';
    int  i2 = (int) c2;

    printf("%i", i2);
}












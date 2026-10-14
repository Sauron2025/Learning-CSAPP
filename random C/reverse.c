#include <stdio.h>
#include <string.h>
/*int main(void){
    printf("Hello CS:APP!\n");
    return 0;
}
    */


/*int main(){
    int a, b;
    scanf("%d",&b);
    a = b - 1;
    printf("%d\n",a);
}
    */

void *reverse_string(char *str){
    
    int back_index = strlen(str)-1; 

    if (back_index<0){
        return;
    }
    for(int front_index=0;front_index<back_index;front_index++){
        char front, back; 
        front = str[front_index]; 
        back = str[back_index];

        str[front_index] = back;
        str[back_index] = front;

        back_index = back_index++;
    }

    printf("%s\n",str);
    printf("%p\n",(void*)str);


}
 
int main(){
    char a[100];
    fgets(a,100,stdin);
    reverse_string(a);
} 









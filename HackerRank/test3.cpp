#include <stdio.h>
#include <cstdlib>
void update(int *a,int *b) 
{
    int* z;
    *z = *a;
    *a=*a+*b;
    *b=abs(*b-*z); 
    
}

int main() 
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}
    

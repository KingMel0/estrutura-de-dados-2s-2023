#include <stdio.h>
 #include <conio.h>
 
 
#include <stdio.h>
 #include <conio.h>
 
 
int main(){
    
    int a[1000],i,n,sum=0;
   
    printf("Digite o tamanho do array : ");
    scanf("%d",&n);
    printf("Digite os elementos do array : ");

    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
 
    for(i=0; i<n; i++){
        sum+=a[i];
    }
     printf("A soma dos elementos do array eh: %d",sum);
 
    return 0;
}
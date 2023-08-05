#include <stdio.h>
int verificaPrimo(int n)
{
  int cont = 3;

  if(n%2 == 0){
    return 0;
  }

  while (cont < n)
  {
    if(n % cont == 0){
        return 0;
    }
    cont += 2;
  }
  
  return 1;
}

int main(){
    int n = 33;
    printf("%d eh primo?  %d", n, verificaPrimo(5));
    return 0;
}
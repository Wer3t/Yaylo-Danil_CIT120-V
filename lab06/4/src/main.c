// Дано 4-розрядне число у системі числення р. Визначити його еквівалент у десятковій системі числення.
#include<stdio.h>

int main()
{
    int slova=0;
    char mas[]="Word  Word   Word s ";
    for(int i=0;mas[i]!='\0';i++){
        if(mas[i]!=' '&&mas[i+1]==' '){
            slova++;
        }
    }
    printf("%d", slova);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void UpString(char *str){
    while(*str){
        *str = toupper((unsigned char) *str);
        str++;
    }
}

char *DuplicateEncoder(const char *string){
    int string_size = strlen(string);
    char *encoder = (char *) malloc(string_size + 1 * sizeof(char));
    char *new_string = (char *) malloc(string_size + 1 * sizeof(char));
    int cont = 0;
    strcpy(new_string, string);
    
    UpString(new_string);
    for(int i = 0; i < string_size; i++){
        for(int j = 0; j < string_size; j++){
            if((new_string[i] == new_string[j]) &&( i != j)){
                cont++;
            }
        }
        if(cont >= 1){
            encoder[i] = ')';
        }else if(cont == 0){
            encoder[i] = '(';
        }
        cont = 0;
    }
    return encoder;
}


int main(){
    char teste[] = "Q4&f3Tac<eT3`7Vf&`}gSlR4<=<WN`34U`k}&k=6O?091f&%Y0/ ?%/O^P)4h%9d7<a/d22>{k2YPO%P1Nf}c4lS<X/=M46V{hQ39`W65Z6V^{";
    char *retorno = DuplicateEncoder(teste);
    printf("%s\n",retorno);
}
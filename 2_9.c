#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define ALPHABET_RESTART ('a' - ('z' + 1))

bool isvowel(char v);
bool vowconvow_convowcon(char a, char b, char c);
bool isprime(int a);
void test(void);

//have to set a = 1 ... z = x 

int main(void)
{
    test();
    char char1 = 'a';
    char char2 = 'a';
    char char3 = 'a';
    int sumcharacters = char1 + char2 + char3;
        assert(sumcharacters == (3 * 'a'));
    int num = 1;

    for( ; char1 != 'z'; ){

        if(char3 == 'z' + 1){
            char3 = char3 + ALPHABET_RESTART;
            char2++;
        }

        if(char2 == 'z' + 1){
            char2 = char2 + ALPHABET_RESTART;
            char1++;
        }

        if(vowconvow_convowcon(char1, char2, char3) == true){
            
            printf("%i %c%c%c\n", num, char1, char2, char3);
            num++;
        }

        char3++;
    }
}

bool isvowel(char v)
{
    switch(v){
        case 'a': case 'e': case 'i': case 'o': case 'u': 
            return true;
            break;

        default:
            return false;

    }
}

bool vowconvow_convowcon(char a, char b, char c)
{
    if(isvowel(a) == true && isvowel(b) == false && isvowel(c) == true){
        return true;        
    }

    if(isvowel(a) == false && isvowel(b) == true && isvowel(c) == false){
        return true;        
    }

    else{
        return false;
    }
}

bool isprime(int a)
{
    int cnt = 2;
    int not_prime = 0;
    
    for(; cnt <= (a-1) && not_prime == 0; cnt ++){
        if(a % cnt == 0){
            not_prime++;
        }
    }
    if(not_prime > 0){
        return false;
    }
    else{
        return true;
    }
}


void test(void)
{
    //check vowels
    assert(isvowel('a') == true);
    assert(isvowel('e') == true);
    assert(isvowel('i') == true);
    assert(isvowel('o') == true);
    assert(isvowel('u') == true);

    //check consonant sample
    assert(isvowel('b') == false);
    assert(isvowel('f') == false);
    assert(isvowel('j') == false);
    assert(isvowel('p') == false);
    assert(isvowel('x') == false);

    //check vowconvow_convowcon

    assert(vowconvow_convowcon('a', 'b', 'a') == true);
    assert(vowconvow_convowcon('z', 'a', 'z') == true);
    assert(vowconvow_convowcon('a', 'a', 'a') == false);
    assert(vowconvow_convowcon('b', 'b', 'b') == false);
    assert(vowconvow_convowcon('a', 'a', 'k') == false);

}
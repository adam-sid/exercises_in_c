#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

//Q: is there a better way identifying vowels instead of current isvowel? Enumerated types or arrays?

//5 lower case, 5 upper case vowels
#define CAPS ('A' - 'a') 

void test(void);
bool isvowel(char v);

int main(void)
{
    test();
    printf("Type a lower case character: ");
    char x;
    do{
        char x = getchar();
        if(isvowel(x) == true && islower(x)){
            putchar(x + CAPS);
        }
        else if(isvowel(x) == false && isupper(x)){
            putchar(x - CAPS);
        }
        else{
            putchar(x);
        }
        
    } while(x != '!');
    putchar('\n');

    return 0;
}

bool isvowel(char v)
{
    int vowel = 0;
    switch(v){
        case 'a': case 'e': case 'i': case'o': case 'u': 
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
            break;

        default:
            return false;

    }
    
}

void test(void)
{
    //check vowels
    assert(isvowel('a') == 1);
    assert(isvowel('E') == 1);
    assert(isvowel('i') == 1);
    assert(isvowel('O') == 1);
    assert(isvowel('u') == 1);

    //check consonant sample
    assert(isvowel('b') == 0);
    assert(isvowel('F') == 0);
    assert(isvowel('j') == 0);
    assert(isvowel('P') == 0);
    assert(isvowel('x') == 0);
}

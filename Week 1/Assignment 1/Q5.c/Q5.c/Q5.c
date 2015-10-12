/* CS261- Assignment 1 - Q.5*/
/* Name: John R Toth
 * Date: 6/24/2015
 * Solution description: C program that converts a lower case letter to upper
 * case and an upper case letter to lower case. This is done by analyzing
 * each char and passing to the proper conversion function. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    if(ch >= 'a' && ch <= 'z')
    
        return ch-'a'+'A';
    else
        return ch;
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z')
    
        return ch-'A'+'a';
    else
        return ch;

}

void sticky(char* word){
    /*Convert to sticky caps*/
    for(int x = 0; x < strlen(word); x++ )
    {
        if(x % 2 == 0)
        {
            word[x] = toUpperCase(word[x]);
        }
        else
        {
            word[x] = toLowerCase(word[x]);
        }
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[100];
    char *input;
    
    input = word;
    
    printf("Type in a word and I'll convert the letters: ");
    scanf("%s", input);
    
    /*Call sticky*/
    
    sticky(input);
    
    /*Print the new word*/
    printf("Here is the new word: %s\n", input);
    
    int a;
    
    for(a = 0; a < strlen(input); a++)
    {
        if(input[a] == '\n')
            break; 
    }
    
    
    return 0;
}

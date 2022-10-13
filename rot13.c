#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc, char** argv)
{
    int i;
    
    for(i=0;i<strlen(argv[1]);i++)
    {
        if(isalpha(argv[1][i]))
        {
            if(islower(argv[1][i]))
            {
                int offset = argv[1][i] - 97;
                int newValue = (offset + 13)%26;
                printf("%c",(newValue + 97));
            }
            else 
            {
                int offset = argv[1][i] - 65;
                int newValue = (offset + 13)%26;
                printf("%c",(newValue + 65));
            }
        }
       
        else 
        {
            printf("%c",argv[1][i]);
        }
    }
    printf("\n");
}
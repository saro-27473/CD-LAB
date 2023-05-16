  #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"};
    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
        flag = 1;
        break;
        }
    }
    return flag;
}

int main()
{
    char ch, buffer[15],arr[15],operators[] = "+-*/%=";
    FILE *fp;
    void *ptr,*addr[15];
    int i,j=0,x=0;
    fp = fopen("symprogram.txt","r");
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    printf("\n \nSymbol Table\n\n");
    printf("\n-----------------------------");
    printf("\nSymbol   Address   Type");
    printf("\n-----------------------------");
    while((ch = fgetc(fp)) != EOF){
        for(i = 0; i < 6; ++i){
            if(ch == operators[i])
            {
            ptr=malloc(ch);
            addr[x]=ptr;
            arr[x]=ch;
            printf("\n %c\t %d    Operator",ch,ptr);
            x++;
            }
        }
        if(isdigit(ch))
        {
            ptr=malloc(ch);
            addr[x]=ptr;
            arr[x]=ch;
            printf("\n %c\t %d    Literals",ch,ptr);
            x++;
        }

        if(isalpha(ch)){
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n' || ch==';') && (j != 0)){
            buffer[j] = '\0';
            j = 0;
            if(isKeyword(buffer) == 1)
            {
            ptr=malloc(buffer);
            addr[x]=ptr;
            arr[x]=buffer;
            printf("\n %s\t %d   keyword",buffer,ptr);
            x++;

            }
            else
            {
            ptr=malloc(buffer);
            addr[x]=ptr;
            arr[x]=buffer;
            printf("\n %s\t %d   Identifier",buffer,ptr);
            x++;
            }
        }
    }
    printf("\n------------------------------\n\n");
    fclose(fp);
    return 0;
}

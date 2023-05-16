#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[]){
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

int main(){
char ch, buffer[15], operators[] = "+-*/%=";
FILE *fp;
int i,j=0;
int key=0,ide=0,ope=0,con=0;
fp = fopen("lexanaprogram.txt","r");
if(fp == NULL){
printf("error while opening the file\n");
exit(0);
}
while((ch = fgetc(fp)) != EOF){
   for(i = 0; i < 6; ++i){
   if(ch == operators[i])
   {
    printf(" %c is operator\n", ch);
    ope++;
   }
   }
   if(isdigit(ch))
   {
       printf(" %c is digit(constant)\n", ch);
       con++;
   }

   if(isalpha(ch)){
   buffer[j++] = ch;
   }
   else if((ch == ' ' || ch == '\n') && (j != 0)){
   buffer[j] = '\0';
   j = 0;
   if(isKeyword(buffer) == 1)
   {
    printf(" %s is keyword\n", buffer);
    key++;
   }
    else
    {
        printf(" %s is identifier\n", buffer);
        ide++;
    }
}
}
printf("\n No of operators: %d",ope);
printf("\n No of Constants: %d",con);
printf("\n No of Keywords : %d",key);
printf("\n No of Identifiers: %d\n",ide);
fclose(fp);
return 0;
}


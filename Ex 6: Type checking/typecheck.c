#include <stdio.h>
#include<stdlib.h>
int main(){
int n,i,k,flag=0;
char vari[25],typ[25],b[23],c;
printf("Enter the number of variables:");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Enter the variable[%d]:",i);
    scanf(" %c",&vari[i]);
    printf("Enter the variable type[%d](float-f,int-i):",i);
    scanf(" %c",&typ[i]);
    if(typ[i]=='f')
        flag=1;
}
printf("Enter the expression(end with $):");
i=0;
getchar();
while((c=getchar())!='$'){
    b[i]=c;
    i++;
}
k=i;
for(i=0;i<k;i++){
    if(b[i]=='/'){
        flag=1;
        break;
        getch();
    }
}
for(i=0;i<n;i++){
    if(b[0]==vari[i]){
        if(flag==1){
                if(typ[i]=='f'){
                    printf("datatype crtly defined");
                    break;
                    getch();
                }
                else{
                    printf("Identifier %c must be a float type",vari[i]);
                    break;
                    getch();
                }
        }
        else{
            printf("Datatype crtly defined");
            break;
            getch();
        }
    }
}
return 0;
}


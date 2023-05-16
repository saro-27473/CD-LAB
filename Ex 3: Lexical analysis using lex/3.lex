%{
#include <stdio.h>
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%

while|for|do|if|break|continue|switch|case|const|typedef|return|else|goto   { printf("\n KEYWORD: %s", yytext); }
int|float|char|double|void|long|struct   { printf("\n DATATYPE: %s", yytext); }

[ \t] { /* ignore whitespace */ }
\n { printf("\n NEWLINE\n\n"); }
; {printf("\n %s is a SEPARATOR",yytext);}
#.* {printf("\n %s is a PREPROCESSOR DIRECTIVE",yytext);}
"/*" {COMMENT=1; printf("\n %s is a COMMENT BEGINS",yytext);}
"*/" {COMMENT=0; printf("\n %s is a COMMENT ENDS",yytext);}
{identifier}\( {if(!COMMENT)printf("\n FUNCTION %s",yytext);}
\{ {if(!COMMENT)printf("\n BLOCK BEGINS");}
\} {if(!COMMENT)printf("\n BLOCK ENDS");}
{identifier}(\[[0-9]*\])? {if(!COMMENT)printf("\n %s IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n %s is a STRING",yytext);}
[0-9]+ {if(!COMMENT)printf("\n %s is a NUMBER",yytext);}
= {if(!COMMENT)printf("\n %s is an ASSIGNMENT OPERATOR",yytext);}
\+|\-|\*|\/|\% {if(!COMMENT)printf("\n %s is a OPERATOR",yytext);}
\<=|\>=|\<|==|\> {if(!COMMENT)printf("\n %s is a RELATIONAL OPERATOR",yytext);}


%%
int main()
{
FILE *file;
file=fopen("input.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
    yylex();
    return 0;
}
int yywrap()
{
return(1);
}

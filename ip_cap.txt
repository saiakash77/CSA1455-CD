%{
%}
%%
[a-z] printf("%c",yytext[0] - ('a' - 'A'));
%%
int yywrap(){}
int main()
{
printf("enter string : ");
yylex();
printf("\n");
return 0;
}

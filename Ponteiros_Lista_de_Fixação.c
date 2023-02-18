Questão 1) Quais serão os valores de x, y e p ao final do trecho de código abaixo:
int x, y, *p;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;
p=endereço de y;
y=4;
x=3;

Considere o trecho de código abaixo:
  int main(void) {
  int x, *p;
  x = 100;
  p = x;
  printf(“Valor de p = %p\tValor de *p = %d”, p, *p);
  }

Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos
fornece alguma mensagem? Se sim, responda:
a) Esta mensagem é de erro ou advertência? //Erro;
b) Por que o compilador emite tal mensagem? //porque p é um ponteiro e não está recebendo o endereço de x;
c) Compile e execute o programa. A execução foi bem sucedida? //não;
d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida
pelo compilador.
  
  /*int main(void) {
  int x, *p;
  x = 100;
  p = &x;
  printf(“Valor de p = %p\tValor de *p = %d”, p, *p);
  }*/
  
e) Compile e execute novamente o programa. A execução foi bem sucedida?//sim.

#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
  void limparBuffer(void);
  setlocale(LC_ALL,("Portuguese"));

  struct produto{
    char nome[1000];
  } p[1000];

  struct loja{
    char nome[1000];
  } l[1000];

  struct lojacre{
    char nome[1000];
  } lc[1000] ;
                                                      
  char escolha[50];
  int i=0,numprod,c;
  printf("= = FAÇA SUA LISTA DE COMPRAS E NO FINAL DIGITE [FIM] ==\n\n");
  do{

  //limparBuffer();

  printf("* ");

  struct produto;

  gets (p[i].nome);

  strcpy(escolha, p[i].nome);

  if(strcmp(escolha, "fim") != 0 && strcmp(escolha, "FIM") != 0){


  }

  printf("\n");

  i=i+1;

  }while(strcmp(escolha, "fim") != 0 && strcmp(escolha, "FIM") != 0);

  numprod=i-1;

  i=0;

  float valor[numprod][10000],valormult[numprod][10000];

  do{

  if(i==0){

  printf("\n= = = = DIGITE ENTER E O NOME DO COMÉRCIO A SER PESQUISADO = = = =\n\n");

  }else{

  printf("\n= = DIGITE O NOME DO PRÓXIMO COMÉRCIO A SER PESQUISADO OU [FIM] PARA FINALIZAR = =\n\n");

  }

  struct loja;

  limparBuffer();

  printf("> ");

  gets (l[i].nome) ;

  strcpy(escolha, l[i].nome);

  printf("\n");

  if(strcmp(escolha, "fim") != 0 && strcmp(escolha, "FIM") != 0){

  for(c=0;c<numprod;c++){

  printf("Digite o valor de ""%s"": R$ ",p[c].nome);

  scanf("%f",&valor[c][i]);

  }

  }

  i=i+1;

  }while(strcmp(escolha, "fim") != 0 && strcmp(escolha, "FIM") != 0);

  int nummer,j;

  nummer = i-1;

  float valormen[numprod*nummer];

  int posicao[numprod];

  for(i=0;i<numprod*nummer;i++){

  valormen[i]=1000000000;

  }

  // Identifica os menores valores por produto e a posicão.

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  if(valor[i][j]<valormen[i]&&valor[i][j]!=0){

  valormen[i]=valor[i][j];

  posicao[i]=j;

  }

  }

  }

  int comerrepete[100][100]={0};

  //Identifica se o menor preço de um produto se repete em mais de 1 estabelecimento.

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  if(valormult[i][j]==valormen[i]){

  comerrepete[i][j]=comerrepete[i][j]+1;

  }

  }

  }

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  if(comerrepete[i][j]>0){

  comerrepete[i][j]=1;

  }else

  {

  comerrepete[i][j]=0;

  }

  }
  }

  int somalin[1000]={0};

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  somalin[i]=comerrepete[i][j]+somalin[i];

  }

  }

  int somacol[1000]={0};

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  somacol[j]=comerrepete[i][j]+somacol[j];

  }

  }

  int maiorposi[100]={0};

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  if(somalin[i]>1&&comerrepete[i][j]>0){

  if(somacol[j]>maiorposi[i]){

  maiorposi[i]=somacol[j];

  posicao[i]=j;

  }

  }

  }

  }

  int contv[numprod];

  for(i=0;i<numprod;i++){

  contv[i]=0;

  }

  int contcomp=0;

  printf("####################################################\n\n");

  if(contcomp>1){

  printf("\t\t\t-RESULTADO MAIS ECONÔMICO -\n\n");

  printf("A opção mais econômica é a qual te recomendo a fazer suas compras em mais de um estabelecimento entre os que pesquisastes.\n");

  };

  contcomp=0;

  //Zera o contador de vezes em que é identificado uma oferta menor em cada comércio.

  for(i=0;i<nummer;i++){

  contv[i]=0;

  }

  //Mostra a lista dos comércios com seus respectivos produtos melhor ofertados.

  for(i=0;i<nummer;i++){

  for(j=0;j<numprod;j++){

  if(posicao[j]==i){

  if(contv[i]==0){

  printf("\n No comércio %s tu encontrará:\n\n",l[i].nome);

  contv[i]=contv[i]+1;

  contcomp=contcomp+1;

  }

  printf("* %s por R$ %.2f\n",p[j].nome,valormen[j]);

  }

  }

  }

  int contazero=0;
  float quantidade[100];

  printf("\nColoque seus produtos no carrinho:\n\n");

  for(i=0;i<numprod;i++)
  {
  printf("》%s - Unidade/kg: ",p[i].nome);
    scanf("%f",&quantidade[i]);
    if(quantidade[i]==0)
    {
      contazero=contazero+1;
    }
    }

  int x;  
  float guardavalormen,guardavalorm;
  char guardaprod[100];
    
    for(x=0;x<contazero;x++){
    for(i=0;i<numprod-1;i++){
    if(quantidade[i]==0)
    {
      for(j=i;j<numprod-1;j++){
        for(int m=0;m<nummer;m++)
        {
      guardavalorm=valor[j][m];
      valor[j][m]=valor[j+1][m];
      valor[j+1][m]=guardavalorm;
          
        }
      quantidade[j]=quantidade[j+1];
      quantidade[j+1]=0;  
      
      guardavalormen=valormen[j];
      valormen[j]=valormen[j+1];
      valormen[j+1]=guardavalormen;
      
      strcpy(guardaprod,p[j].nome);
      strcpy(p[j].nome,p[j+1].nome);
      strcpy(p[j+1].nome,guardaprod);
      }
      
    }
      }
    }
    
    numprod=numprod-contazero;
    
    float valormenmult[100];
    
    for(i=0;i<numprod;i++)
    {
      valormenmult[i]=valormen[i]*quantidade[i];
        }

    for(i=0;i<numprod;i++)
    {
      for(j=0;j<nummer;j++)
      {
        valormult[i][j]=valor[i][j]*quantidade[i];
      }
    }

  float somam1=0;

  // Faz a soma de todos os valores menores por produto.

  for(j=0;j<numprod;j++){

  somam1=somam1+valormenmult[j];

  }

  printf("\nO valor total das compras fica: R$ %.2f\n",somam1);

  //Para mostrar na tela a lista das possíveis ecônomias relacionadas a comparação dos totais de cada comércio com o total da supostas compras separadamente.

  float somapormer[100000]={0};

  float guardavalor=0;

  char guardanome[50];

  float valormulttrans[100][100]={0};

  // Verifica se existe algum produto em falta então o atribui o menor valor ofertado para que seja possível fazer o cálculo das possíveis porcentagens.

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  if(valormult[i][j]==0){

  valormulttrans[i][j]=valormen[i];

  }else

  {

  valormulttrans[i][j]=valormult[i][j];

  }

  }

  }

  //Faz a soma das compras em cada comércio.

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  somapormer[j]=somapormer[j]+valormulttrans[i][j];

  }

  }

  // Copia os nomes dos comércios em um novo vetor antes que o próximo passo troque a ordem.

  struct lojacre;

  for (i=0;i<nummer;i++){

  strcpy(lc[i].nome,l[i].nome);

  }

  //Coloca as somas e respectivamente o nome de cada comércio em ordem decrescente.

  for(i=0;i<nummer-1;i++){

  for(j=0;j<nummer-1;j++){

  if(somapormer[i+1]>somapormer[j]){

  guardavalor=somapormer[j];

  somapormer[j]=somapormer[i+1];

  somapormer[i+1]=guardavalor;

  strcpy(guardanome,l[j].nome);

  strcpy(l[j].nome,l[i+1].nome);

  strcpy(l[i+1].nome,guardanome);

  }

  }

  }


  printf("______\n\n");

  if(nummer>1){
  if(contcomp>1){

  printf("Economia em relação a possíveis compras em um único comércio:\n\n");

  }else{

  printf("Economia em relação a possíveis compras em outros comércios:\n\n");

  }

  }


  for(i=0;i<nummer;i++){

  if((somapormer[i])-(somam1)>0.00)

  {

  printf("Em relação ao %s tu tens %2.f%% / R$ %.2f\n\n",l[i].nome,100-((somam1*100)/somapormer[i]),(somapormer[i])-(somam1));

  }

  };

  printf("####################################################\n");

  //Para mostrar na tela lista dos comércios e seus respectivos totais caso os mesmos possuirem todos os produtos da lista:

  float somapormercre[10000]={0};

  //Faz a soma das compras em cada comércio e verifica em quais existem produtos em falta, sendo assim a soma do mesmo fica igual a zero.

  for(i=0;i<numprod;i++){

  for(j=0;j<nummer;j++){

  if(valormult[i][j]>0.00){

  somapormercre[j]=somapormercre[j]+valormult[i][j];

  }

  else{

  somapormercre[j]=0;

  valormult[i+1][j]=0;

  }

  }

  }

  //Coloca as somas e respectivamente o nome de cada comércio em ordem crescente.

  for(i=0;i<nummer-1;i++){

  for(j=0;j<nummer-1;j++){

  if(somapormercre[i+1]<=somapormercre[j]){

  guardavalor=somapormercre[j];

  somapormercre[j]=somapormercre[i+1];

  somapormercre[i+1]=guardavalor;

  strcpy(guardanome,lc[j].nome);

  strcpy(lc[j].nome,lc[i+1].nome);

  strcpy(lc[i+1].nome,guardanome);

  }

  }

  }

  int marcposi=0;

  // Faz a contagem de totais com o resultado zero, para saber o início do laço de repetição que vai mostrar os totais de cada comércio.

  if(somapormercre[0]==0){

  marcposi=1;

  for(i=1;i<nummer;i++){

  if(somapormer[i]==0){

  marcposi=marcposi+1;

  }

  }

  }

  if(contcomp>1){

  for(i=0;i<nummer;i++){

  if(somapormercre[i]>0.00){
  printf("Comprando apenas no %s o total fica R$ %.2f\n",lc[i].nome,somapormercre[i]);
  }

  }

  }

  else{

  for(i=marcposi+1;i<nummer;i++){

  printf("O total das compras no %s fica R$ %.2f\n",lc[i].nome,somapormercre[i]);

  }

  }

  for(i=0;i<nummer;i++){

  if(somapormercre[i]==0.00){
  printf("O %s não possui todos os produtos de sua lista.\n",lc[i].nome);

  printf("______\n\n");

  }

  }
  return 0;
  }

  void limparBuffer(void){
  char c;
  while((c=getchar()) != '\n'&& c !=EOF);
}
//abaixo estamos carregando a biblioteca Standard Input Output para usarmos
//os comandos de entrada (scanf) e saída (printf) de dados do usuario

#include <stdio.h>
//abaixo estamos definindo a estrutura do tipo Aluno, que possui os campos Nome, Idade, Sexo, Aprovado e Nota. Essa estrutura será utilizada para armazenar as informações de cada aluno.
struct Aluno
{
    char Nome[30];
    int Idade;
    char Sexo;
    bool Aprovado;
    float Nota[30];
};
//Dentro da função main, são declaradas variáveis para armazenar a quantidade de alunos, provas, contadores e acumuladores para cálculos de médias e percentuais.
int main() {

    int QtdAlunos, QtdProvas, QtdAlunosM=0, QtdAlunosF=0;
    int QtdaprovM=0, QtdaprovF=0, QtdreprovM=0, QtdreprovF=0;
    
    int somaIdadeAprov=0, somaIdadeReprov=0;
    int contAprov=0, contReprov=0;
    
    float Media, MediaAprov;
    float percAprovM, percAprovF, percReprovM, percReprovF;

    float mediaIdadeAprov, mediaIdadeReprov;
    struct Aluno Alunos[100]; 
    {

    };    
    //solicitando a quantidade de alunos e provas, e a media de aprovação
    printf("informe a quantidade de alunos: ");
    scanf("%i", &QtdAlunos);
    
    printf("informe a quantidade de provas: ");
    scanf("%i", &QtdProvas);
    do
    {
        printf("Informe a media de aprovacao: ");
        scanf("%f", &MediaAprov);
      if (MediaAprov < 5 or MediaAprov > 8)
      {
        printf("Media de aprovacao deve ser entre 5 e 8. Tente novamente.\n");
      }
      // O loop continuará solicitando a média de aprovação até que o usuário forneça um valor válido
      
    } while (MediaAprov < 5 or MediaAprov > 8);
      
      // O loop for abaixo é responsável por coletar os dados de cada aluno, incluindo nome, idade, sexo e notas.
    for (int i = 1; i <= QtdAlunos; i++) {
        Media = 0;
        printf("Informe o nome do aluno %d: ", i);
        scanf("%s", Alunos[i].Nome);
        printf("Informe a idade do aluno %s: ", Alunos[i].Nome);
        do  
        {
            scanf("%d", &Alunos[i].Idade);
            if (Alunos[i].Idade <= 16 || Alunos[i].Idade >= 90)
            {
                printf("Idade invalida. Por favor, informe uma idade entre 16 e 90.\n");
            }
        } while (Alunos[i].Idade <= 16 || Alunos[i].Idade >= 90);

        do
        {
            printf("Informe o sexo do aluno %s (M/F): ", Alunos[i].Nome);
            scanf(" %s", &Alunos[i].Sexo);
            if (Alunos[i].Sexo != 'M' and Alunos[i].Sexo != 'm' && Alunos[i].Sexo != 'F' and Alunos[i].Sexo != 'f')
            {
                printf("Sexo invalido. Por favor, informe M para masculino ou F para feminino.\n");
            }
            // O loop continuará solicitando o sexo do aluno até que o usuário forneça um valor válido (M/m/F/f)
          } while (Alunos[i].Sexo != 'M' and Alunos[i].Sexo != 'm' && Alunos[i].Sexo != 'F' and Alunos[i].Sexo != 'f');
    
          if (Alunos[1].Sexo=='M' or Alunos[1].Sexo=='m')
          {
            QtdAlunosM++;
          }
          else
          {
            QtdAlunosF++;
          }
          // O loop for abaixo é responsável por coletar as notas de cada prova para o aluno, garantindo que as notas sejam válidas (entre 0 e 10) e calculando a média para determinar se o aluno foi aprovado ou reprovado.
          for (int n = 0; n < QtdProvas; n++)
          {
            printf("Informe a nota da prova %d do aluno %s: ", n+1, Alunos[i].Nome);
            scanf("%f", &Alunos[i].Nota[n]);
            if (Alunos[i].Nota[n] < 0 or Alunos[i].Nota[n] > 10)
            {
                printf("Nota invalida. Por favor, informe uma nota entre 0 e 10.\n");
                n--; // Decrementa n para repetir a entrada da nota
            }
            Media = Media + Alunos[i].Nota[n];
          }
          Alunos[i].Aprovado = Media/QtdProvas >= MediaAprov;
          
          if (Alunos[i].Aprovado and (Alunos[i].Sexo=='F' or Alunos[i].Sexo=='f'))
          {
            QtdaprovF++;
          } 
          
          else if (Alunos[i].Aprovado and (Alunos[i].Sexo=='M' or Alunos[i].Sexo=='m'))
          {
            QtdaprovM++;
          }
          else if (!Alunos[i].Aprovado and (Alunos[i].Sexo=='M' or Alunos[i].Sexo=='m'))
          {
            QtdreprovM++;
          }
          else if (!Alunos[i].Aprovado and (Alunos[i].Sexo == 'F' or Alunos[i].Sexo=='f'))
          {
            QtdreprovF++;
          }
          if (Alunos[i].Aprovado) {
            somaIdadeAprov = somaIdadeAprov + Alunos[i].Idade;
            contAprov++;
          }else {
            somaIdadeReprov = somaIdadeReprov + Alunos[i].Idade;
            contReprov++;
          }
    } 
      // Cálculo dos percentuais de aprovação e reprovação por sexo
      percAprovM = (float)QtdaprovM / QtdAlunos*100;
      percAprovF = (float)QtdaprovF / QtdAlunos*100;
      percReprovM = (float)QtdreprovM / QtdAlunos*100;
      percReprovF = (float)QtdreprovF / QtdAlunos*100;

      printf("Percentual de alunos aprovados do sexo masculino: %.2f%%\n", percAprovM);
      printf("Percentual de alunos aprovados do sexo feminino: %.2f%%\n", percAprovF);
      printf("Percentual de alunos reprovados do sexo masculino: %.2f%%\n", percReprovM);
      printf("Percentual de alunos reprovados do sexo feminino: %.2f%%\n", percReprovF);
      // Cálculo da média de idade dos alunos aprovados e reprovados
      mediaIdadeAprov = (float)somaIdadeAprov / contAprov;
      mediaIdadeReprov = (float)somaIdadeReprov / contReprov;

    printf("Quantidade de alunos cadastrados na turma: %d\n", QtdAlunos);   

    printf("\nrelatorio dos alunos");
    // O loop for abaixo é responsável por gerar o relatório dos alunos, exibindo o nome e o status de aprovação de cada um.
    for (int  i = 1; i <= QtdAlunos; i++)
    {
        printf("\nAluno: %s", Alunos[i].Nome);
    // Verifica se o aluno foi aprovado ou reprovado e exibe a mensagem correspondente
    if (Alunos[i].Aprovado)
    {
      printf("\nAprovado");
    }else{
      printf("\nReprovado");
    }
  }
    
}
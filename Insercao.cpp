#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void introducao(int m, int f, string palavra){
    cout<<"Ola, BEM VINDO. Vamos juntos aprender"<<endl;
    cout<<"o metodo de insercao com string"<<endl<<endl;
    cout<<"O arquivo aberto e o 'dados.txt', lembre-se de"<<endl;
    cout<<"renomealo corretamente para evita o ERRO!"<<endl<<endl;
    cout<<"Iremos ordenar o seguinte: "<<endl;
    cout<<"A frase junta sem espacos:  "<<palavra<<endl;
    cout<<"Quantidade de memoria:      "<<m<<endl;
    cout<<"Numero de filas disponivel: "<<f<<endl;
    cout<<"Bom Aprendizado!"<<endl;
    system("pause");
    system("cls");
    cout<<"Primeiro iremos dividir as palavras no numero das memorias"<<endl;
    cout<<"temos "<<m<<" disponiveis  entao iremos comeca a joga nas filas disponiveis."<<endl;
    cout<<"Lembrando que usaremos metade das filas"<<endl;
    system("pause");
    system("cls");
}

void paragrafo(){
    cout<<"Agora iremos pega os blocos e ordenalos sendo todas as primeiras letras antes"<<endl;
    cout<<"De voltamos ao inicio exemplo: "<<endl;
    cout<<"b1  b2 "<<endl;
    cout<<"ABC DEF"<<endl;
    cout<<"BCC STU"<<endl;
    cout<<"DRU TUU"<<endl;
    cout<<"Assim iremos pega a primeira letra de cada bloco e seleciona a menor, e colocando na fila livre"<<endl;
    cout<<"pegamos A, B, D, a letra A por se menor ira para a fila, pegando a seguindo B, comparamos"<<endl;
    cout<<"as B, B, D, pegando B senod menor. assim ate termina o bloco b1. ATENCAo nao misture os blocos"<<endl;
    cout<<"b1 ficaria: ABBCCCDRU b2: DEFSTTUUU"<<endl;
    cout<<"caso chegamos no fim da fila e ainda tem blocos, voltamos ao inicio da fila e iremos descendo novamente"<<endl;
    system("pause");
    system("cls");
}

int main(){
    int m=0, f=0, i, j, acaba=0, soma=0, finalmente=0, meio, aux=0, num=0, max, terminou=1, help, troca, fim, rodou=0;
    string linha, palavra, mem="", compara="", tira="";

    ifstream inFile;
    inFile.open("dados.txt", ios::in);
    if (!inFile){
        cout<<"ERRO!"<<endl;
        abort();
    }

    while(inFile>>linha){
        if(m==0){
            m = stoi(linha);
        }else{
            if(f==0){
                f = stoi(linha);
            }else{
                palavra=linha;
            }
        }
    }

    meio=f/2;
    max=meio*m;
    troca=m;
    string fila[f];
    for(i=0; i<f; i++){
        fila[i]="";
    }
    int contador[m];
    int ultimo[m];
    int ativa[m];
    for(i=0; i<m; i++){
        contador[i]=0;
        ativa[i]=0;
    }

    string memoria[m];
    for(i=0; i<m; i++){
        memoria[i]="";
    }
    // introducao(m, f, palavra);
    for(i=0; i<palavra.length(); i++){
        if(aux<meio){
            //pega os dados na memoria
            mem+=palavra[i];
            aux++;
            if(aux==meio){
                //ordena e coloca na fila
                sort(mem.begin(), mem.end());
                fila[num]+=mem;
                mem="";
                num++;
                if(num==meio){
                    num=0;
                }
            aux=0;
            }
        }
    }

    // cout<<"A primeira divisao fica asim, contamos "<<m<<" e decemos para a fila de baiuxo"<<endl;
    // cout<<"quando chegamso na metade das filas começamos na primeira de novo ate acaba"<<endl;
    // cout<<"as palavras. usamos metade pois precisamos joga de um lado pro outro a ordenacao"<<endl;

    for(i=0; i<meio; i++){
        cout<<fila[i]<<endl;
    }
    system("pause");
    // paragrafo();
    cout<<"insercao 1"<<endl;
    
    soma=0;
    while(finalmente==0){
        rodou=0;

        while(terminou==1){

            for(i=0; i<m; i++){
                contador[i]=0;
                ativa[i]=0;
                memoria[i]="";
            }
            compara="";
            soma=0;

            for(i=0; i<m; i++){
                soma+=fila[i].length();
                // cout<<soma<<" soma"<<endl;
            }
            if(soma>=max){
                for(i=0; i<m; i++){
                    ultimo[i]=meio;
                    // cout<<ultimo[i]<<endl;
                }
            }else{
                terminou=0;
                for(i=0; i<m; i++){
                    ultimo[i]=fila[i].length();
                }
            }
            
            for(i=0; i<max; i++){ 
                for(j=0; j<m; j++){
                    if(memoria[j]=="" && contador[j]!=ultimo[j] && ativa[j]==0){                   
                        memoria[j]=fila[j][contador[j]];
                        contador[j]+=1;
                    }
                    cout<<memoria[j]<<" ";
                }
                compara="";
                for(j=0; j<m; j++){
                    if(ativa[j]==0 && compara==""){
                        compara=memoria[j];
                        help=j;
                    }else{
                        if(memoria[j]<compara && ativa[j]==0){
                            compara=memoria[j]; 
                            help=j;
                        }
                    }
                }
                if(contador[help]==ultimo[help]){
                    ativa[help]=1;
                }
                cout<<compara<<endl;
                fila[troca]+=compara;
                compara="";
                memoria[help]="";
            }

            cout<<"sair   ";
            cout<<fila[troca]<<endl;
            system("pause");

            if(troca<f){
                troca++;
                if(troca==f){
                    troca=m;
                }
            }

            if(terminou==1){//corta as letras usadas
                for(i=0; i<meio; i++){
                    tira="";
                    for(j=0; j<fila[i].length(); j++){
                        if(j>=meio){
                            tira+=fila[i][j];
                        }
                    }
                    fila[i]=tira;
                    tira="";
                }
                for(i=0; i<m; i++){
                    cout<<fila[i]<<endl;
                }
            }

            rodou++;
        }//fim de termiou
    fim=m;

    for(i=0; i<m; i++){
        fila[i]=fila[fim];
        fim++;
    }
    for(i=m; i<f; i++){
        fila[i]="";
    }

    if(rodou==1){
        cout<<"PARABENS!"<<endl;
        break;
    }

    rodou=0;
    terminou=1;
    meio=max; 
    max*=m;

    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int m=0, f=0, i, j, max, troca, soma, meio, aux=0, num=0, filamax, mostra=0, help, fim, ordenou=0, simvoucriar=0;
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

    string fila[f];
    for(i=0; i<f; i++){
        fila[i]="";
    }

    string memoria[m];
    for(i=0; i<m; i++){
        memoria[i]="";
    }

    int contador[m];
    int ultimo[m];
    int ativa[m];
    for(i=0; i<m; i++){
        contador[i]=0;
        ativa[i]=0;
    }

    filamax=f/2;//max de fila 
    fim=filamax;//para troca as filas
    meio=m;//max que um bloco pode chegar em ua fila
    max=meio*filamax;//max de um bloco total
    troca=filamax;//para trocar

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

    for(;;){
        cout<<"\n\nIniciando Insercao"<<endl;
        for(i=0; i<filamax; i++){
            if(fila[i].length()>0){
                mostra=0;
                for(j=0; j<fila[i].length(); j++){
                    cout<<fila[i][j];
                    mostra++;
                    if(mostra==meio){
                        cout<<" ";
                        mostra=0;
                    }
                }
                cout<<endl;
            }
        }
        system("pause");

        for(;;){
            soma=0;
            for(i=0; i<filamax; i++){
                contador[i]=0;
                ativa[i]=0;
                memoria[i]="";
            }
            compara="";

            for(i=0; i<filamax; i++){
                soma+=fila[i].length();
            }
            if(soma==0){
                break;
            }
            if(soma>max){
                for(i=0; i<filamax; i++){
                    ultimo[i]=meio;
                }
            }else{
                for(i=0; i<filamax; i++){
                    ultimo[i]=fila[i].length();
                }
            }

            cout<<"Comparando Letras"<<endl;
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
                if(compara!=""){
                    cout<<compara<<endl;
                }
                fila[troca]+=compara;
                compara="";
                memoria[help]="";
            }

            cout<<"\nBloco: ";
            cout<<fila[troca]<<endl;
            system("pause");

            if(troca<f){
                troca++;
                if(troca==f){
                    troca=filamax;
                }
            }

            
            for(i=0; i<filamax; i++){
                tira="";
                if(fila[i].length()>0){
                    for(j=0; j<fila[i].length(); j++){
                            if(j>=meio){
                            tira+=fila[i][j];
                        }
                    }
                    fila[i]=tira;
                    tira="";
                }
            }
            simvoucriar=0;
            for(i=0; i<filamax; i++){
                if(fila[i].length()>0){
                    if(simvoucriar==0){
                        cout<<"Situacao da fila"<<endl;
                        simvoucriar=1;
                    }
                    mostra=0;
                    for(j=0; j<fila[i].length(); j++){
                        cout<<fila[i][j];
                        mostra++;
                        if(mostra==meio){
                            cout<<" ";
                            mostra=0;
                        }
                    }
                    cout<<endl;
                }
            }

        }//fim do segundo for

        num=fim;

        for(i=0; i<fim; i++){
            fila[i]=fila[num];    
            num++;
        }
        for(i=fim; i<f; i++){
            fila[i]="";
        }

        for(i=1; i<f; i++){
            if(fila[i].length()>0){
                ordenou=1;
            }
        }

        if(ordenou==0){
            break;
        }
        
        

        ordenou=0;

        troca=filamax;
        meio=max;
        max*=filamax;
        
        
        }//ultimo for

        cout<<"\n\nFrase ordenada pelo metodo de insecao: ";
        cout<<fila[0]<<endl;

    return 0;
}
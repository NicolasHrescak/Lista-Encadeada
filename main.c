#include<stdio.h>
#include <assert.h>
#include<stdlib.h>

typedef struct ficha{
    int aluno;
    struct ficha *proximo;
}ficha;

ficha *alocaficha(ficha **ficha1){
    *ficha1= (ficha *)malloc(sizeof(ficha));

    return  *ficha1;
}

ficha *desalocaficha(ficha *ficha1){
    free( ficha1);

    return NULL;
}


void inserenoinicio(ficha **ficha1, ficha *ficha2){
    ficha *aux = (ficha*)malloc(sizeof(ficha));
    aux->aluno = ficha2->aluno;
    aux->proximo = *ficha1;
    *ficha1 = aux;

    return;
}

void inserenofinal(ficha **ficha1, ficha *ficha2){
    ficha *aux = *ficha1;
    if(aux == NULL){
        printf("A lista está vazia");
    }
    
    while( aux->proximo!= NULL){
        aux = aux->proximo;
    }
    aux->proximo = (ficha*)malloc(sizeof(ficha));
    aux=aux->proximo;
    aux->aluno = ficha2->aluno;
    aux->proximo = NULL;
}

void criaficha(ficha *ficha2){
    
    printf("Digite o numero do aluno: ");
    scanf("%d", &ficha2->aluno);
    
}

void desalocainicio(ficha **ficha2){
    assert(ficha2);
    
    ficha *aux = *ficha2;
    *ficha2 = (*ficha2)->proximo;
    free(aux);
    aux=NULL;	

}

void desaolcafinal(ficha **ficha2){
    assert(ficha2 && *ficha2);
    
    ficha *aux = *ficha2;
    if(aux==NULL){
        printf("A lista esta vazia");
        return;
    }
    
    while(aux->proximo!=NULL){
        aux=aux->proximo;
    }
    *ficha2=(*ficha2)->proximo;
    free(aux);
    aux=NULL;
    
}

int main(){
    ficha *ficha, *ficha1 =NULL, *ficha2 = NULL, *ficha3 = NULL, *ficha4 = NULL, *ficha5 = NULL, *ficha6 = NULL, *ficha7 = NULL;
       
    alocaficha(&ficha1);
    alocaficha(&ficha2);
    alocaficha(&ficha3);
    alocaficha(&ficha4);
    alocaficha(&ficha5);
    alocaficha(&ficha6);
    alocaficha(&ficha7);

    criaficha(ficha1);
    criaficha(ficha2);
    criaficha(ficha3);
    criaficha(ficha4);
    criaficha(ficha5);
    criaficha(ficha6);
    criaficha(ficha7);

    
    inserenoinicio(&ficha1, ficha2);
    inserenoinicio(&ficha1, ficha3);
    inserenoinicio(&ficha1, ficha4);
    inserenoinicio(&ficha1, ficha5);
    inserenofinal(&ficha1, ficha6);
    inserenofinal(&ficha1, ficha7);
    

    
    struct ficha *aux=ficha1;
    while( aux !=NULL){
        printf(" %d ->",aux->aluno);
        aux = aux->proximo;
    }
    
    printf(" NULL, fim da lista"); 
    
    printf(" \nLista com desalocas: ");
    
    //desalocainicio(&ficha1);
    desaolcafinal( &ficha1);
    
    aux = ficha1;
    while(aux!=NULL)
		{
			printf("%d->", aux->aluno);
			aux = aux->proximo;}

    desalocaficha(ficha1);
    desalocaficha(ficha2);
    desalocaficha(ficha3);
    desalocaficha(ficha4);
    desalocaficha(ficha6);
    desalocaficha(ficha7);
    


    return 0;

}








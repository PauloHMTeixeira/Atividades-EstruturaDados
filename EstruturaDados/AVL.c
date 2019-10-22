#include<stdio.h> 
#include<stdlib.h> 

 
struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int altura; 
}; 
 
int max(int a, int b); 

 int altura(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->altura; 
} 
 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    node->key = key; 
    node->left = NULL; 
    node->right = NULL; 
    node->altura = 1; // adicionado como folha 
    return(node); 
} 

// rotação para direita 
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
 
    x->right = y; 
    y->left = T2; 

    // altura 
    y->altura = max(altura(y->left), altura(y->right))+1; 
    x->altura = max(altura(x->left), altura(x->right))+1;

    return x; 
} 

// rotação para esquerda 
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
 
    y->left = x; 
    x->right = T2; 

    // altura 
    x->altura = max(altura(x->left), altura(x->right))+1; 
    y->altura = max(altura(y->left), altura(y->right))+1; 

    return y; 
} 

// balanceamento do nó
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return altura(N->left) - altura(N->right); 
} 

struct Node* insert(struct Node* node, int key) 
{ 
    // inserção acompanhada de rotação
    if (node == NULL) 
        return(newNode(key)); 

    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // não entram chaves iguais, não tem pra que
        return node; 

    // ajustando altura do pai do nó
    node->altura = 1 + max(altura(node->left), 
                        altura(node->right)); 

    // checando o balanceamento do pai do nó para ver se precisa balancear
    int balance = getBalance(node); 

    // se desbalanceou, temos 4 casos do que pode ser feito 

    // caso direita simples
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 

    // caso esquerda simples 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 

    // caso dupla direita 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 

    // caso dupla esquerda 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    return node; 
} 

/* quando a árvore não está vazia, deve ser retornado
o nó com o menor valor de key da árvore. A árvore não
precisa ser buscada até o fim.*/
struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 

    // loop descendo para achar a folha mais a esquerda
    while (current->left != NULL) 
        current = current->left; 

    return current; 
} 

// funçao para deletar o nó da key pedida.
// de uma sub árvore com a raiz dada. Retorna a sub árvore modificada.
struct Node* deleteNode(struct Node* root, int key) 
{ 
    // primeiro passo, deletar folhas

    if (root == NULL) 
        return root; 

    // se a chave a ser deletada for menor que a chave da raiz
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 

    // se a chave a ser deletada for maior que a chave da raiz
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 

    // se a chave tiver o mesmo tamanho, então ela prórpia é quem deve ser deletada 
    else
    { 
        // nó com apenas um filho ou nenhum filho 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct Node *temp = root->left ? root->left : 
                                            root->right; 

            // sem filho 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // um filho 
            *root = *temp; // pegando o conteúdo do filho não vazio para que não seja perdido 
            free(temp); 
        } 
        else
        { 
            // nó com dois filhos, pegando o menor da sub árvore da direita
            struct Node* temp = minValueNode(root->right); 

            // pegando o menor da sub árvore da direita 
            root->key = temp->key; 

            // deletando ele após ser armazenado 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 

    // se a árvore tiver apenas um nó 
    if (root == NULL) 
    return root; 

    // segundo passo, atualizar as alturas 
    root->altura = 1 + max(altura(root->left), 
                        altura(root->right)); 

    // terceiro passso, checar se o nó se tornou desbalanceado
    int balance = getBalance(root); 

    // novamente, se esse nó se tornar desbalanceado, temos 4 casos 
 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 

    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 

    return root; 
} 

// função para printar a árvore na pré ordem 
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

int main() 
{ 
struct Node *root = NULL; 
int teto, entrada, removeTeto, remove, decisao;
scanf("%i", &teto);

// construindo a árvore
for(int i = 0; i < teto; i++){
    scanf("%i %i", &decisao, &entrada);
    if(decisao == 1){
    root = insert(root, entrada);
    } else {
        
    }
    }
    printf("Pré ordem da árvore construida é \n"); 
    preOrder(root); 

    /*scanf("%i", &removeTeto);
    for(int i = 0; i < removeTeto; i++){
        scanf("%i", &remove);        
        root = deleteNode(root, remove);
    } 

    

    printf("\nPré ordem da árvore após serem deletados os números\n"); 
    preOrder(root); */

    return 0; 


} 
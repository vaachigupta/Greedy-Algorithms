#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define max 10
typedef struct node nodetype;

struct node{
    char data;
    int freq;
    nodetype* left;
    nodetype* right;
};

nodetype* create_node(char data, int freq){
    nodetype* new_node = (nodetype*)malloc(sizeof(nodetype));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void sort_nodes(nodetype* node[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(node[j]->freq > node[j+1]->freq){
                nodetype* temp = node[j];
                node[j] = node[j+1];
                node[j+1] = temp;
            }
        }
    }
}
nodetype* huffman_create(nodetype* nodes[],int n){
    while(n>1){
        nodetype* left = nodes[0];
        nodetype* right = nodes[1];
        nodetype* parent = create_node('$',left->freq+right->freq);
        parent->left = left;
        parent->right = right;
        for(int i=2;i<n;i++)
            nodes[i-2]=nodes[i];
        nodes[n-2]=parent;
        sort_nodes(nodes,--n);
    }
    return nodes[0];
}


void generate_codes(nodetype* root, char* code, int index) {
    if(root->left==NULL && root->right==NULL){
        code[index]='\0';
        printf("'%c': %s\n",root->data,code);
        return;
    }
    if(root->left!=NULL){
        code[index] = '0';
        generate_codes(root->left,code, index+1);
    }
    if(root->right!=NULL){
        code[index]='1';
        generate_codes(root->right,code,index+1);
    }
}

int main(){
    char chars[] = {'a', 'b', 'c', 'd', 'e'};
    int freqs[] = {50, 25, 15, 40, 75};
    int size = sizeof(chars) / sizeof(chars[0]);
    nodetype* nodes[max];
    for(int i=0;i<size;i++)
        nodes[i]=create_node(chars[i],freqs[i]);
    sort_nodes(nodes, size);
    nodetype* root= huffman_create(nodes,size);
    char code[max];
    printf("Huffman codes:\n");
    generate_codes(root,code,0);
    return 0;
}
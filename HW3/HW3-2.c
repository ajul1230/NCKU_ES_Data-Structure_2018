#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node_ {
    struct Node_* left;
    struct Node_* right;
    char* data;
    int cnt;
};

typedef struct Node_ Node;

int node_cmp(const void* a, const void* b) {
    Node* na = (Node*) a;
    Node* nb = (Node*) b;
    
    return ((na->cnt) - (nb->cnt));
}

Node* bst_insert(Node* p, const char* s) {
    if (p == NULL) {
        Node* q = (Node*) malloc (sizeof(Node));
        q->left = NULL;
        q->right = NULL;
        q->cnt = 1;
        q->data = (char*) malloc (sizeof(char) * (strlen(s)+1));
        strcpy(q->data, s);
        return q;
    }
    else {
        int flag = strcmp(s, p->data);
        if (flag < 0)
            p->left = bst_insert(p->left, s);
        else if (flag > 0)
            p->right = bst_insert(p->right, s);
        else
            (p->cnt)++;
        return p;
    }
}

Node* bst_find(Node* p, const char* s) {
    if (p == NULL) return NULL;
    int flag = strcmp(s, p->data);
    if (flag > 0)
        return bst_find(p->right, s);
    else if (flag < 0)
        return bst_find(p->left, s);
    else
        return p;
}

Node* bst_remove(Node* p, const char* s) {
    if (p == NULL) return NULL;
    
    int flag = strcmp(s, p->data);
    if (flag > 0)
        p->right = bst_remove(p->right, s);
    else if (flag < 0)
        p->left = bst_remove(p->left, s);
    else {
        if (p->cnt > 1) {
            (p->cnt)--;
            return p;
        }
        else if (p->left == NULL) {
            Node* q = p->right;
            free(p->data);
            free(p);
            return q;
        }
        else if (p->left->right == NULL) {
            Node* q = p->left;
            q->right = p->right;
            free(p->data);
            free(p);
            return q;
        }
        else {
            Node* q;
            for (q=p->left; q->right->right != NULL; q=q->right);
            Node* r = q->right;
            q->right = r->left;
            r->left = p->left;
            r->right = p->right;
            free(p->data);
            free(p);
            return r;
        }
    }
    
    return p;
}



int bst_build_list(Node* p, Node* list) {
    static int idx = 0;
    
    if (p == NULL) return 0;
    
    bst_build_list(p->left, list);
    list[idx++] = *p;
    bst_build_list(p->right, list);
    
    return idx;
}

void free_bst(Node* root) {
    if (root == NULL) return;
    
    free_bst(root->left);
    free_bst(root->right);
    
    free(root->data);
    free(root);
}

void bst_preorder(Node* p) {
    if (p == NULL) return;
    
    printf("%s %d\n", p->data, p->cnt);
    bst_preorder(p->left);
    bst_preorder(p->right);
}
int eof() {
    char a = getchar();
    while (a == '\0' || a == '\n') {
        a = getchar();
    }
    
    if (a != -1) {
        ungetc(a, stdin);
        return 1;
    }
    return 0;
}

int main() {
    
    Node* root = NULL;
    
    char input[1024];
    while (eof()) {
        scanf("%s", input);
        int len = strlen(input);
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
            len--;
        }
        
        if (input[0] == '+') {
            const char* s = input+1;
            root = bst_insert(root, s);
        }
        else if (input[0] == '-') {
            const char* s = input+1;
            if (bst_find(root, s) == NULL) {
                puts("Not exist");
                continue;
            }
            bst_remove(root, s);
        }
    }
    
    bst_preorder(root);
    return 0;
}

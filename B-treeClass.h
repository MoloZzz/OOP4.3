/**
 * @file B-treeClass.h
 * @brief Заголовочний файл для класів B-дерева
 */

#ifndef OOP4_3_B_TREECLASS_H
#define OOP4_3_B_TREECLASS_H

#include <iostream>
#include"comlexInt.h"
using namespace std;

/**
 * @class TreeNode
 * @brief Вузол B-дерева
 */
class TreeNode {
    Complex* keys; /**< Масив ключів вузла */
    int t; /**< Параметр B-дерева */
    TreeNode** C; /**< Масив покажчиків на дочірні вузли */
    int n; /**< Кількість ключів у вузлі */
    bool leaf; /**< Прапорець, що вказує, чи є вузол листком */

public:
    /**
     * @brief Конструктор класу TreeNode
     * @param temp Параметр B-дерева
     * @param bool_leaf Чи є вузол листком
     */
    TreeNode(int temp, bool bool_leaf);

    void insertNonFull(Complex k);
    void splitChild(int i, TreeNode* y);
    void traverse();

    TreeNode* search(Complex k);

    friend class BTree;
};

/**
 * @class BTree
 * @brief B-дерево
 */
class BTree {
    TreeNode* root; /**< Корінь B-дерева */
    int t; /**< Параметр B-дерева */

public:
    /**
     * @brief Конструктор класу BTree
     * @param temp Параметр B-дерева
     */
    BTree(int temp) {
        root = NULL;
        t = temp;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    TreeNode* search(Complex k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(Complex k);
};


TreeNode::TreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new Complex[2 * t - 1];
    C = new TreeNode * [2 * t];

    n = 0;
}

void TreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i].getString();
    }

    if (leaf == false)
        C[i]->traverse();
}

TreeNode* TreeNode::search(Complex k) {
    int i = 0;
    while (i < n && (k > keys[i]))
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}

void BTree::insert(Complex k) {
    if (root == NULL) {
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            TreeNode* s = new TreeNode(t, false);

            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void TreeNode::insertNonFull(Complex k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void TreeNode::splitChild(int i, TreeNode* y) {
    TreeNode* z = new TreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}
#endif //OOP4_3_B_TREECLASS_H

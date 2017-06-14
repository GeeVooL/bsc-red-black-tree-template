/*
* Name: RBTree.h
* Purpose: Single header file that contains template of Red-Black Tree
* @Author: Michał Dziewulski
* @Version: 1.0 03.05.2017
*/

#ifndef RBTREEINT_RBTREE_H
#define RBTREEINT_RBTREE_H

#include <iostream>
#include <vector>

///RBTNode
template <typename T> class RBTNode
{
    template <typename U> friend class RBTree;

public:
    RBTNode(T key);
    RBTNode();

private:
    RBTNode<T> *p;
    RBTNode<T> *left;
    RBTNode<T> *right;
    bool color; //0 = black, 1 = red
    T key;
};

///RBTree
template <typename T> class RBTree
{
    template <typename U> friend class RBTNode;

public:
    //Constructors and destructor
    RBTree();
    RBTree(const RBTree<T>& source);
    ~RBTree();

    //Methods
    void insert(T key);
    void insert(RBTNode<T> *z);

    void remove(T key);
    void remove(RBTNode<T> *z);
    void clear();

    void merge(const RBTree<T>& source);
    void subtract(const RBTree<T> &source);
    void copy(const RBTree<T>& source);

    bool exists(T key);
    bool compare(const RBTree<T> &source);
    long long unsigned size();
    int getKey(RBTNode<T> &x);
    void getValues(std::vector<T>& values) const;

    RBTNode<T>& search(RBTNode<T> *x, T key);

    RBTNode<T>& minimum(RBTNode<T> *x);
    RBTNode<T>& minimum();

    RBTNode<T>& maximum(RBTNode<T> *x);
    RBTNode<T>& maximum();

    RBTNode<T>& successor(RBTNode<T> *x);
    RBTNode<T>& predecessor(RBTNode<T> *x);

    void printTree(RBTNode<T> *x);
    RBTNode<T> *getRoot() const;

    //Operators
    RBTree<T>& operator += (const RBTree<T>& source);
    RBTree<T> operator + (const RBTree<T>& source);
    RBTree<T>& operator -= (const RBTree<T>& source);
    RBTree<T> operator - (const RBTree<T>& source);
    RBTree<T>& operator = (const RBTree<T>& source);
    bool operator == (const RBTree<T>& source);
    bool operator != (const RBTree<T>& source);

private:
    //Methods
    void leftRotate(RBTNode<T> *x);
    void rightRotate(RBTNode<T> *x);

    void insertFixup(RBTNode<T> *z);

    void transplant(RBTNode<T> *u, RBTNode<T> *v);
    void deleteFixup(RBTNode<T> *x);

    void insertAllToSource(RBTree<T> &src) const;
    void removeAllFromSource(RBTree<T> &source, RBTNode<T> *x) const;
    void copyContent(RBTNode<T> *first, RBTNode<T> *second);

    bool compareContent(RBTNode<T> *first, RBTNode<T> *second);

    void getValuesRec(std::vector<T>& values, const RBTNode<T>* x) const;

    //Fields
    RBTNode<T> *root;
    static RBTNode<T> NIL;
    long long unsigned n;
};

template<typename T> RBTNode<T> RBTree<T>::NIL;

///Node constructors
template<typename T> RBTNode<T>::RBTNode(T key)
{
    p = nullptr;
    left = nullptr;
    right = nullptr;
    this->color = true;
    this->key = key;
}

template<typename T> RBTNode<T>::RBTNode()
{
    p = nullptr;
    left = nullptr;
    right = nullptr;
    color = false;
}

///Constructors
template<typename T> RBTree<T>::RBTree()
{
    n = 0;
    root = &NIL;
}

template<typename T> RBTree<T>::RBTree(const RBTree<T> &source)
{
    n = 0;
    root = &NIL;
    this->copy(source);
}

///Destructor
template<typename T> RBTree<T>::~RBTree()
{
    clear();
}


///Methods
template<typename T> void RBTree<T>::insert(T key)
{
    RBTNode<T> *z = new RBTNode<T>(key);
    insert(z);
}
template<typename T> void RBTree<T>::insert(RBTNode<T> *z)
{
    RBTNode<T> *y = &NIL;
    RBTNode<T> *x = root;

    while(x != &NIL)
    {
        y = x;
        if(z->key < x->key) //Make sure int type of field 'key' has implemented '<' operators!
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;

    if(y == &NIL)
        root = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;

    z->left = &NIL;
    z->right = &NIL;
    z->color = true;

    n++;
    insertFixup(z);
}

template<typename T> void RBTree<T>::remove(T key)
{
    RBTNode<T> *x = &search(root, key);
    remove(x);
}

template<typename T> void RBTree<T>::remove(RBTNode<T> *z)
{
    RBTNode<T> *org = z;
    RBTNode<T> *x;
    RBTNode<T> *y = z;
    bool yOriginalColor = y->color;

    if(z->left == &NIL)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if(z->right == &NIL)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = &(minimum(z->right));
        yOriginalColor = y->color;
        x = y->right;

        if(y->p == z)
            x->p = y;
        else
        {
            transplant(y,y->right);
            y->right = z->right;
            y->right->p = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }

    n--;
    if(!yOriginalColor)
        deleteFixup(x);
    delete org;
}

template<typename T> void RBTree<T>::clear()
{
    while (root != &NIL)
        remove(root);
}

template<typename T> void RBTree<T>::merge(const RBTree<T> &source)
{
    source.insertAllToSource(*this);
}

template<typename T> void RBTree<T>::subtract(const RBTree<T> &source)
{
    source.removeAllFromSource(*this, source.root);
}

template<typename T> void RBTree<T>::copy(const RBTree<T> &source)
{
    if(source.root == &NIL)
        return;
    root = new RBTNode<T>(source.root->key);
    root->color = source.root->color;
    root->p = &NIL;
    copyContent(source.root, root);
}

template<typename T> bool RBTree<T>::exists(T key)
{
    return &search(root, key) != &NIL;
}

template<typename T> bool RBTree<T>::compare(const RBTree<T> &source)
{
    return compareContent(root, source.root);
}

template<typename T> long long unsigned RBTree<T>::size()
{
    return n;
}

template<typename T> int RBTree<T>::getKey(RBTNode<T> &x)
{
    return x.key;
}

template<typename T> void RBTree<T>::getValues(std::vector<T>& values) const
{
    getValuesRec(values, root);
}


template<typename T> RBTNode<T>& RBTree<T>::search(RBTNode<T> *x, T key)
{
    while(x != &NIL && key != x->key)
    {
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return *x;
}

template<typename T> RBTNode<T>& RBTree<T>::minimum(RBTNode<T> *x)
{
    while(x->left != &NIL)
        x = x->left;
    return *x;
}

template<typename T> RBTNode<T>& RBTree<T>::minimum()
{
    return minimum(root);
}

template<typename T> RBTNode<T>& RBTree<T>::maximum(RBTNode<T> *x)
{
    while(x->right != &NIL)
        x = x->right;
    return *x;
}

template<typename T> RBTNode<T>& RBTree<T>::maximum()
{
    return maximum(root);
}

template<typename T> RBTNode<T>& RBTree<T>::successor(RBTNode<T> *x)
{
    if (x->right != &NIL)
        return minimum(x->right);

    RBTNode<T> *y = x->p;
    while (y != &NIL && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return *y;
}

template<typename T> RBTNode<T>& RBTree<T>::predecessor(RBTNode<T> *x)
{
    if (x->left != &NIL)
        return minimum(x->left);

    RBTNode<T> *y = x->p;
    while (y != &NIL && x == y->left)
    {
        x = y;
        y = y->p;
    }
    return *y;
}

template<typename T> void RBTree<T>::printTree(RBTNode<T> *x)
{
    if(x != &NIL)
    {
        printTree(x->left);
        std::cout << x->key << " ";
        printTree(x->right);
    }
}

template<typename T> RBTNode<T>* RBTree<T>::getRoot() const
{
    return root;
}

///Operators
template<typename T> RBTree<T>& RBTree<T>::operator+=(const RBTree<T> &source)
{
    this->merge(source);
    return *this;
}

template<typename T> RBTree<T> RBTree<T>::operator+(const RBTree<T> &source)
{
    RBTree<T> output(*this);
    output.merge(source);
    return output;
}

template<typename T> RBTree<T>& RBTree<T>::operator-=(const RBTree<T> &source)
{
    this->subtract(source);
    return *this;
}

template<typename T> RBTree<T> RBTree<T>::operator-(const RBTree<T> &source)
{
    RBTree<T> output(*this);
    output.subtract(source);
    return output;
}

template<typename T> RBTree<T>& RBTree<T>::operator=(const RBTree<T> &source)
{
    if(this == &source)
        return *this;

    this->clear();
    //this->merge(source);
    this->copy(source);
    return *this;
}

template<typename T> bool RBTree<T>::operator==(const RBTree<T> &source)
{
    return this->compare(source);
}

template<typename T> bool RBTree<T>::operator!=(const RBTree<T> &source)
{
    return !(this->compare(source));
}

///PRIVATE
///Methods
template<typename T> void RBTree<T>::leftRotate(RBTNode<T> *x)
{
    RBTNode<T> *y = x->right;
    x->right = y->left;

    if(y->left != &NIL)
        y->left->p = x;

    y->p = x->p;

    if(x->p == &NIL)
        root = y;
    else if(x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    y->left = x;
    x->p = y;
}

template<typename T> void RBTree<T>::rightRotate(RBTNode<T> *x)
{
    RBTNode<T> *y = x->left;
    x->left = y->right;

    if(y->right != &NIL)
        y->right->p = x;

    y->p = x->p;

    if(x->p == &NIL)
        root = y;
    else if(x == x->p->right)
        x->p->right = y;
    else
        x->p->left = y;
    y->right = x;
    x->p = y;
}

template<typename T> void RBTree<T>::insertFixup(RBTNode<T> *z)
{
    RBTNode<T> *y;

    while(z->p->color)
    {
        if(z->p == z->p->p->left)
        {
            y = z->p->p->right;
            if(y->color)
            {
                z->p->color = false;
                y->color = false;
                z->p->p->color = true;
                z = z->p->p;
            }
            else
            {
                if(z == z->p->right)
                {
                    z = z->p;
                    leftRotate(z);
                }
                z->p->color = false;
                z->p->p->color = true;
                rightRotate(z->p->p);
            }
        }
        else
        {
            y = z->p->p->left;
            if(y->color)
            {
                z->p->color = false;
                y->color = false;
                z->p->p->color = true;
                z = z->p->p;
            }
            else
            {
                if(z == z->p->left)
                {
                    z = z->p;
                    rightRotate(z);
                }
                z->p->color = false;
                z->p->p->color = true;
                leftRotate(z->p->p);
            }
        }
    }

    root->color = false;
}

template<typename T> void RBTree<T>::transplant(RBTNode<T> *u, RBTNode<T> *v)
{
    if(u->p == &NIL)
        root = v;
    else if(u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    v->p = u->p;
}

template<typename T> void RBTree<T>::deleteFixup(RBTNode<T> *x)
{
    RBTNode<T> *w;
    while(x != root && !x->color)
    {
        if(x == x->p->left)
        {
            w = x->p->right;
            if(w->color)
            {
                w->color = false;
                x->p->color = true;
                leftRotate(x->p);
                w = x->p->right;
            }
            if(!w->left->color && !w->right->color)
            {
                w->color = true;
                x = x->p;
            }
            else
            {
                if(!w->right->color)
                {
                    w->left->color = false;
                    w->color = true;
                    rightRotate(w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = false;
                w->right->color = false;
                leftRotate(x->p);
                x = root;
            }
        }
        else
        {
            w = x->p->left;
            if(w->color)
            {
                w->color = false;
                x->p->color = true;
                rightRotate(x->p);
                w = x->p->left;
            }
            if(!w->right->color && !w->left->color)
            {
                w->color = true;
                x = x->p;
            }
            else
            {
                if(!w->left->color)
                {
                    w->right->color = false;
                    w->color = true;
                    leftRotate(w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = false;
                w->left->color = false;
                rightRotate(x->p);
                x = root;
            }
        }
    }

    x->color = false;
}

template<typename T> void RBTree<T>::insertAllToSource(RBTree<T> &src) const
{
    std::vector<T> values;
    getValues(values);
    for(long long unsigned i = 0; i < values.size(); i++)
        src.insert(values[i]);
}

template<typename T> void RBTree<T>::removeAllFromSource(RBTree<T> &source, RBTNode<T> *x) const
{
    if(x != &NIL)
    {
        removeAllFromSource(source, x->left);
        source.exists(x->key);
        source.remove(x->key);
        removeAllFromSource(source, x->right);
    }
}

template<typename T> void RBTree<T>::copyContent(RBTNode<T> *first, RBTNode<T> *second)
{
    if(first != &NIL)
    {
        //left
        if (first->left != &NIL)
        {
            RBTNode<T> *newLeftNode = new RBTNode<T>(first->left->key);
            newLeftNode->color = first->left->color;
            newLeftNode->p = second;
            second->left = newLeftNode;
        }
        else
            second->left = &NIL;
        copyContent(first->left, second->left);

        //right
        if (first->right != &NIL)
        {
            RBTNode<T> *newRightNode = new RBTNode<T>(first->right->key);
            newRightNode->color = first->right->color;
            newRightNode->p = second;
            second->right = newRightNode;
        }
        else
            second->right = &NIL;
        copyContent(first->right, second->right);
    }
}

template<typename T> bool RBTree<T>::compareContent(RBTNode<T> *first, RBTNode<T> *second)
{
    if (first == &NIL && second == &NIL) return true;
    if (first == &NIL && second != &NIL) return false;
    if (first != &NIL && second == &NIL) return false;

    if (first->key != second->key) return false;

    return compareContent(first->left, second->left) && compareContent(first->right, second->right);
}

template<typename T> void RBTree<T>::getValuesRec(std::vector<T>& values, const RBTNode<T> *x) const
{
    if(x != &NIL)
    {
        values.push_back(x->key);
        getValuesRec(values, x->left);
        getValuesRec(values, x->right);
    }
}

#endif //RBTREEINT_RBTREE_H

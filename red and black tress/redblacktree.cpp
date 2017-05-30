//
//  redbacktree.cpp
//  Assignment4
//
//  Created by manpreet kaur on 2016-03-13.
//  Copyright © 2016 manpreet kaur. All rights reserved.
//

#include "redblacktree.h"

#define _REDBLACKTREE_H_

// some of member functions consulted from codershub.com and stackoverflow.

#include<iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
using namespace std;


template<class T>
Node<T>* RedBlackTree<T>::BSTInsert(T item)
{
    Node<T>* refnode; // will be pointer to parent of inserted node
    Node<T>* newnode; // will be pointer to inserted node
    // special case: empty tree
    if (size <= 0)
    {
        root = new Node<T>(item);
        newnode = root;
    }
    else // general case: non-empty tree
    {
        refnode = root;
        // find the insertion location
        while (((item < refnode->data) && (refnode->left != NULL)) || ((item > refnode->data)&& (refnode->right != NULL)))
        {
            if (item < refnode->data)
                refnode = refnode->left;
            else if (item > refnode->data)
                refnode = refnode->right;
        }
        // exited while loop, refnode points to the parent of the insertion location and has a null location to insert
        newnode = new Node<T>(item);
        newnode->p = refnode;
        if (item < refnode->data)
            refnode->left = newnode;
        else
            refnode->right = newnode;
    }
    
    return newnode;
}
template<class T>
void RedBlackTree<T>::InOrder(const Node<T>* node, T* arr, int arrsize, int& index) const
{
    if (node != NULL)
    {
        // recurse on left child
        if (node->left != NULL)
            InOrder(node->left, arr, arrsize, index);
        
        // visit current node
        arr[index] = node->data;
        index++;
        
        // recurse on right child
        if (node->right != NULL)
            InOrder(node->right, arr, arrsize, index);
    }
}

template <class T>
void RedBlackTree<T>::RemoveAll(Node<T>* node)
{   //post order traversal of tree, and then deleting each  node one by one.
    if(node==NULL)
    {
        return;
    }
    if(node->left!=NULL)
        RemoveAll(node->left);
    if(node->right!=NULL)
        RemoveAll(node->right);
    delete node;
    
    
    size=0;
}


template <class T>
void RedBlackTree<T>::LeftRotate(Node<T>* node)
{
    if (node != NULL)
    {
        // if root
        if (node == root)
        {
            // case: no right child (no child or left child only)
            if (node->right == NULL)
            {
                // do nothing, do not allow the rotation
            }
            else
            {
                Node<T>* rc = node->right; // right child
                Node<T>* rclc = node->right->left; // right child's left child
                rc->p = NULL;
                rc->left = node;
                node->p = rc;
                node->right = rclc;
                if (rclc != NULL)
                    rclc->p = node;
                
                root = rc;
            }
        }
        // if elsewhere
        else
        {
            // case: no right child (no child or left child only)
            if (node->right == NULL)
            {
                // do nothing, do not allow the rotation
            }
            else
            {
                Node<T>* parent = node->p; // parent
                Node<T>* rc = node->right; // right child
                Node<T>* rclc = node->right->left; // right child's left child
                
                if (node == node->p->left)
                    node->p->left = rc;
                else
                    node->p->right = rc;
                
                rc->p = parent;
                rc->left = node;
                node->p = rc;
                node->right = rclc;
                if (rclc != NULL)
                    rclc->p = node;
            }
        }
    }
}

template <class T>
void RedBlackTree<T>::RightRotate(Node<T>* node)
{
    if (node != NULL)
    {
        // if root
        if (node == root)
        {
            // case: no left child (no child or right child only)
            if (node->left == NULL)
            {
                // do nothing, do not allow the rotation
            }
            else
            {
                Node<T>* lc = node->left; // left child
                Node<T>* lcrc = node->left->right; // left child's right child
                lc->p = NULL;
                lc->right = node;
                node->p = lc;
                node->left = lcrc;
                if (lcrc != NULL)
                    lcrc->p = node;
                
                root = lc;
            }
        }
        // if elsewhere
        else
        {
            // case: no left child (no child or right child only)
            if (node->left == NULL)
            {
                // do nothing, do not allow the rotation
            }
            else
            {
                Node<T>* parent = node->p; // parent
                Node<T>* lc = node->left; // left child
                Node<T>* lcrc = node->left->right; // left child's right child
                
                if (node == node->p->left)
                    node->p->left = lc;
                else
                    node->p->right = lc;
                
                lc->p = parent;
                lc->right = node;
                node->p = lc;
                node->left = lcrc;
                if (lcrc != NULL)
                    lcrc->p = node;
            }
        }
    }
}

template <class T>
Node<T>* RedBlackTree<T>::Predecessor(Node<T>* node)
{
    Node<T>* pre = NULL;
    // do not allow operation on a null node
    if (node != NULL)
    {
        // case: node has no left child
        if (node->left == NULL)
            pre = NULL;
        else
        {
            // go left once, then follow right pointers until no more right pointers found
            pre = node->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }
            //while loop exited, pre contains the predecessor or NULL
        }
    }
    return pre;
}

template<class T>
int RedBlackTree<T>::maxHeight(int x, int y)
{
    if(x>=y)
    {
        return x;
    }
    else
        return y;
}


template<class T>
int RedBlackTree<T>::CalculateHeight(Node<T>* node) const
{
    int heightleft, heightright;
    if(node==NULL)
    {
        return 0;
    }
    /*calculate right and left height of each node, and then return the largest height to the root, 
     since height is the maximum height of right and left subtrees.*/
    heightleft=CalculateHeight(node->left);
    heightright=CalculateHeight(node->right);
    if(heightright>=heightleft)
        
    {
        return heightright+1;
    }
    else
        return heightleft+1;
    
}

template<class T>
RedBlackTree<T>::RedBlackTree()
{
    root=NULL;
    size=0;
}
template<class T>
Node<T>* RedBlackTree<T>::CopyTree(Node<T>* sourcenode, Node<T>* parentnode)
{
    Node<T>* copyNode = NULL; //creating a new pointer ofnode.
    
    if(sourcenode==NULL)
        return NULL;
    //will create a new node with same data and color as the sourcenode corresponding node
    //right and left node will also be created by recursive fucntion.
    copyNode=new Node<T>(sourcenode->data);
    copyNode->is_black=sourcenode->is_black;
    
    copyNode->left=CopyTree(sourcenode->left, copyNode);
    if(copyNode->left!=NULL)
        copyNode->left->p=parentnode;
    copyNode->right=CopyTree(sourcenode->right, copyNode);
    if(copyNode->right!=NULL)
        copyNode->right->p=parentnode;
    
    return copyNode;
    
}
template<class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& rbtree)
{
    Node<T>* parent=NULL;//pointer to pass as parameter in CopyTree to copy the exact same tree.
    Node<T>* temp;
    //temp will store address of newly created copied tree. and then storing that adress in root of this tree.
    temp=CopyTree(rbtree.root, parent);
    root=temp;
    
    
}
template<class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree<T>& rbtree)
{
    //if(*this!= &rbtree)
    //{
       Node<T>* parent = NULL;
       Node<T>* temp;
       //deallocating memory of current tree, and copying rbtree by calling copytree function.
       RemoveAll();
       temp= CopyTree(rbtree.root, parent);
       root=temp;
    //}
       return *this;
}


template<class T>
RedBlackTree<T>::~RedBlackTree()
{
    RemoveAll(root);
    
}

template<class T>
bool RedBlackTree<T>::Insert(T item)
{
    

    if(Search(item)==false)//if item to be inserted is not in the tree, then insert it.
    {
        Node<T>* newnode;
        Node<T> *uncle;
        newnode=BSTInsert(item); //performing BSTinsert first and then balancing it using red black tree properties.
        size+=1;
        if(root==newnode)//case1: if new node inserted is root of tree
        {
            root->is_black=true;
            return true;
            
        }
        while(newnode->p!=NULL && newnode->p->is_black==false)
        {
            Node<T> *grandparent=newnode->p->p;
            // case2; if newnode is left child, and parent is red and uncle is red and uncle is right child

            if(grandparent->left==newnode->p)
            {
                if(grandparent->right!=NULL)
                {
                    uncle=grandparent->right;
                    if(uncle->is_black==false)
                    {
                        newnode->p->is_black=true;
                        uncle->is_black=true;
                        grandparent->is_black=true;
                        newnode=grandparent;
                    }
                }
                else
                {
                    if(newnode->p->right==newnode)
                    {
                        newnode=newnode->p;
                        LeftRotate(newnode);
                    }
                    newnode->p->is_black=true;
                    grandparent->is_black=false;
                    RightRotate(grandparent);
                }
            }
            else
                // case2; if newnode is left child, and parent is red and uncle is red and uncle is left child.
            {
                if(grandparent->left!=NULL)
                {
                    uncle=grandparent->left;
                    if(uncle->is_black==false)
                    {
                
                        newnode->p->is_black=true;
                        uncle->is_black=true;
                        grandparent->is_black=false;
                        newnode=grandparent;
                    }
                }
                else
                {
                    if(newnode->p->left==newnode)
                    {
                        newnode=newnode->p;
                        RightRotate(newnode);
                    }
                    newnode->p->is_black=true;
                    grandparent->is_black=false;
                    LeftRotate(grandparent);
                }
            }
            root->is_black=true; //root of tree should always be black.
        }
        return true;
    }
    return false;
    
}

template<class T>
bool RedBlackTree<T>::Search(T item) const
{
    T* array=new T;//making a new array
    int p=0;
    int found =0;
    
    if (root==NULL)
    {
        return false;
    }
    InOrder(root, array, size, p);//array will contain all the data values of tree,
    for(int i=0;i<size; i++)
    {
        if(array[i]==item)//if item is equal to any value of tree, then return true.
        {
            found=1;
        }
    }
    delete array;
    if(found ==1)
    {
        return true;
    }
    return false;
}


template <class T>
T* RedBlackTree<T>::Retrieve(T item)
{
    T* value = NULL;
    
    // search for the item
    Node<T>* node = root;
    
    while (node != NULL)
    {
        if (item == node->data)
        {
            value = &(node->data);
            break; // item has been found, exit while loop
        }
        else if (item < node->data)
            node = node->left;
        else
            node = node->right;
    }
    // if exit while loop without breaking, item is not found
    return value;
}

template<class T>
void RedBlackTree<T>::RemoveAll()
{
    RemoveAll(root);
    root=NULL;
    
}

template <class T>
T* RedBlackTree<T>::Dump(int& arrsize) const
{
    int index = 0;
    arrsize = size;
    T* contents = new T[size];
    InOrder(this->root, contents, size, index);
    
    return contents;
}

template<class T>
int RedBlackTree<T>::Size() const
{
    return size;
}

template<class T>
int RedBlackTree<T>::Height()const
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return CalculateHeight(root);
    }
}


//consulted from codershub.com and stackoverflow

template <class T>
bool RedBlackTree<T>::Remove(T item)
{
    if(Search(item)==false) //if item to be removed is not in the tree
    {
        return false;
    }
    Node<T>* node;
    int found=0;
    Node<T>* temp;
    temp=root; // temp will be pointing to root of tree. loop is used to find the pointer node that consists the item to be removed.
    while( temp!=NULL && found==0 )
    {
        if(temp->data==item)
        {
            found=1;
            node=temp;
        }
        else
        {
            if(item> temp->data)
                temp=temp->right;
            else
                temp=temp->left;
        }
        
    }
    Node<T>* y;
    
    if (node->left ==NULL || node->right == NULL)//if one of child of node is null,
    {
        y = node;
    }
    else
    {
        y = Predecessor(node); //if no child is null, then find predecessor of node and then replace the predecessor value with node's value.
    }
    Node<T>* x;//to pint child of y.
    bool xLeft = false; //if x is a left child.
    
    if (y->left != NULL)
    {
        x = y->left;
        xLeft = true;
    }
    else
    {
        x = y->right;
        xLeft = false;
    }
    if (x != NULL)
    {
        x->p = y->p;
    }
    Node<T>* xParent = y->p;
    
    if (y->p == NULL) {
        root = x;
    }
    else if (y == y->p->left)//if y is left child of parent, then set the left child of parent as x.
    {
        y->p->left = x;
        
    }
    else
    {
        y->p->right = x;
            }
    
    if (y != node) {
        node->data = y->data;
    }
    
    
    
    if (y->is_black==true)//if the node to be deleted has color black, then call the function RBdeleteFixup.
    {
        
        if(x==NULL) //if is null, we cannot pass it like this to deletefixup
        {
            x= new Node<T>(item);
            x->p=xParent;
        }
            RBDeleteFixUp(x, xParent, xLeft);
    }
    
    return true;
}
//consulted from codershub.com and stackoverflow
template<class T>
void RedBlackTree<T>::RBDeleteFixUp(Node<T>* x, Node<T>* xparent, bool xisleftchild)
{
    
    
    while (root!=x && x->is_black==true)  //if the node is not root and its black
    {
        Node<T>* uncle;
        if (xisleftchild==true)
        {
            uncle = x->p->right; //if child is left, then.
            if (uncle->is_black==false)
            {
                uncle->is_black = true;
                x->p->is_black = false;
                LeftRotate(xparent);
                uncle = x->p->right;
            }
            
            if (uncle->left->is_black && uncle->right->is_black) //if children of uncle are both black
            {
                uncle->is_black = false;
                x = xparent;
                xparent = x->p;
                xisleftchild = (x == xparent->left);
            }
            else
            {
                if (uncle->right->is_black)//if left is red and right child is black
                {
                    uncle->left->is_black = true; //make color of left child and uncle and rotate the uncle
                    uncle->is_black = false;
                    RightRotate(uncle);
                    uncle = xparent->right;
                }
                
                uncle->is_black = xparent->is_black; //changing the color of uncle to its node's parent colour
                xparent->is_black= true;
                if (uncle->right != NULL)
                {
                    uncle->right->is_black = true;
                }
                LeftRotate(xparent);
                x = root;
                xparent = NULL;
            }
        }
        else
        {   //if node is not a left child
            uncle = xparent->left;
            if (uncle->is_black==false)
            {
                uncle->is_black = true;
                xparent->is_black = false;
                RightRotate(xparent);
                uncle = xparent->left;
            }
            
            if (uncle->right->is_black && uncle->left->is_black) //if both of uncle's children are black
            
            {
                uncle->is_black = false;
                x = xparent;
                xparent = x->p;
                xisleftchild = (x == xparent->left);
            } else
            {
                if (uncle->left->is_black)//right child is red and left is black
                {
                    uncle->right->is_black = true;
                    uncle->is_black = false;
                    LeftRotate(uncle);
                    uncle = xparent->left;
                }
                
                uncle->is_black = xparent->is_black;
                xparent->is_black = true;
                if (uncle->left != NULL)
                {
                    uncle->left->is_black = true;
                }
                RightRotate(xparent);
                x = root;
                xparent = NULL;
            }
        }
    }
    
    x->is_black = true; // make the colour of node black.
    size-=1; //a node is removed, so size decreases.
}







    
#include "Tree.hpp"
#include <iostream>
template<typename T>
int Tree<T>::insertNode(T **start,int data,T* ancester){
    if((*start)==nullptr){
        *start=new T(data);
        (*start)->ancester=ancester;
        return 0;
    }
    if(data>(*start)->data){
        insertNode(&(*start)->LeftChild,data,*start);
    }
    if(data<(*start)->data)
        insertNode(&(*start)->RightChild,data,*start);
}
template<typename T>
int Tree<T>::insertNode(T** start, T** data, T* ancester) {

    if (*start == nullptr) {
        *start = *data;
        (*start)->ancester = ancester;
        return 0;
    }
    if ((*data)->data <=(*start)->data) {
        insertNode(&(*start)->LeftChild, data, *start);
    }
    if ((*data)->data > (*start)->data)
        insertNode(&(*start)->RightChild, data, *start);
}
template<typename T>
Tree<T>& Tree<T>::operator+(int data) {
    insertNode(&root, data, nullptr);
    return *this;
}
template<typename T>
void Tree<T>::operator-(int data) {
    remove(data);
}
template<typename T>
T& Tree<T>::operator[](int number) {
    return GetNumber(number);

}
template<typename T>
void Tree<T>::operator*(Tree<T>& operand) {
    vector<int> arry;
    arry = getArray(operand);
    int n = arry.size();
    for (int i = 0; i < n; i++) {
        *this + arry[i];
    }
}
template<typename T>
void Tree<T>::operator/(Tree<T>& operand) {
    vector<int> arry;
    arry = getArray(operand);
    int n = arry.size();
    for (int i = 0; i < n; i++) {
        *this - arry[i];
    }
}
template<typename T>
void Tree<T>::preorderVector(T* start) {
    if (start) {
        arry.push_back(start->data);
        preorderVector(start->LeftChild);
        preorderVector(start->RightChild);
    }
}
template<typename T>
void Tree<T>::inorderVector(T* start) {
    if (start) {
        inorderVector(start->LeftChild);
        arry.push_back(start->data);
        inorderVector(start->RightChild);
    }
}
template<typename T>
void Tree<T>::postorderVector(T* start) {
    if (start) {
        postorderVector(start->LeftChild);
        postorderVector(start->RightChild);
        arry.push_back(start->data);
    }
}
template<typename T>
void Tree<T>::preorder() {
    RefreshArry(1);
    int n = arry.size();
    for (int i = 0; i < n; i++)
        cout << arry[i] << ' ';
    cout << endl;
}
template<typename T>
void Tree<T>::inorder() {
    RefreshArry(2);
    int n = arry.size();
    for (int i = 0; i < n; i++)
        cout << arry[i] << ' ';
    cout << endl;
}
template<typename T>
void Tree<T>::postorder() {
    RefreshArry(3);
    int n = arry.size();
    for (int i = 0; i < n; i++)
        cout << arry[i] << ' ';
    cout << endl;
}
template<typename T>
void Tree<T>::RefreshArry(int s) {
    arry = {};
    switch (s) {
    case 1:
        preorderVector(root);
        break;
    case 2:
        inorderVector(root);
        break;
    case 3:
        postorderVector(root);
        break;
    }
}
template<typename T>
vector<int>& Tree<T>::getArray(Tree<T>& operand) {
    return operand.ReturnArray();
}
template<typename T>
vector<int>& Tree<T>::ReturnArray() {
    RefreshArry(2);
    return arry;
}
template<typename T>
T& Tree<T>::GetNumber(int number) {
    RefreshArry(2);
    return *search(arry[number]);
}
template<typename T>
void Tree<T>::remove(int data) {
    T* tmp = nullptr;
     tmp = search(data);
    if (tmp->ancester == nullptr) {
        if (tmp->RightChild != nullptr && tmp->LeftChild == nullptr) {
            root = tmp->RightChild;
            delete tmp;
        }
        if (tmp->RightChild == nullptr && tmp->LeftChild != nullptr) {
            root = tmp->LeftChild;
            delete tmp;
        }
        if (tmp->RightChild != nullptr && tmp->LeftChild != nullptr) {
            root = tmp->RightChild;
            insertNode(&root, tmp->data, nullptr);
            delete tmp;
        }
        if (tmp->RightChild == nullptr && tmp->LeftChild == nullptr) {
            root = nullptr;
        }
    }
    else {
        if (tmp == tmp->ancester->LeftChild) {
            if (tmp->LeftChild == nullptr && tmp->RightChild == nullptr) {
                tmp->ancester->LeftChild = nullptr;
                delete tmp;
            }
            else if (tmp->LeftChild != nullptr && tmp->RightChild == nullptr) {
                tmp->ancester->LeftChild = tmp->LeftChild;
                tmp->LeftChild->ancester = tmp->ancester;
                delete tmp;
            }
            else if (tmp->LeftChild == nullptr && tmp->RightChild != nullptr) {
                tmp->ancester->LeftChild = tmp->RightChild;
                tmp->RightChild->ancester = tmp->ancester;
                delete tmp;
            }
            else {
                tmp->ancester->LeftChild = tmp->RightChild;
                tmp->ancester->LeftChild->ancester = tmp->ancester;
                insertNode(&(tmp->RightChild), &(tmp->LeftChild), tmp->ancester);
                delete tmp;
            }
        }
        else {
            if (tmp->LeftChild == nullptr && tmp->RightChild == nullptr) {
                tmp->ancester->RightChild = nullptr;
                delete tmp;
            }
            else if (tmp->LeftChild != nullptr && tmp->RightChild == nullptr) {
                tmp->ancester->RightChild = tmp->LeftChild;
                tmp->LeftChild->ancester = tmp->ancester;
                delete tmp;
            }
            else if (tmp->LeftChild == nullptr && tmp->RightChild != nullptr) {
                tmp->ancester->RightChild = tmp->RightChild;
                tmp->RightChild->ancester = tmp->ancester;
                delete tmp;
            }
            else {
                tmp->ancester->RightChild = tmp->LeftChild;
                tmp->ancester->RightChild->ancester = tmp->ancester;
                insertNode(&(tmp->RightChild), &(tmp->LeftChild), tmp->ancester);
                delete tmp;
            }
        }
    }

}
template<typename T>
T* Tree<T>::search(int data) {
    T* tmp = root;
    while (tmp != nullptr) {
        if (data > tmp->data)
            tmp = tmp->RightChild;
        else if (data < tmp->data)
            tmp = tmp->LeftChild;
        else
            return tmp;
    }
}
template<typename T>
void Tree<T>::deleteTree() {
    RefreshArry(2);
    int n = arry.size();
    for (int i = 0; i < n; i++)
        remove(arry[i]);
}
template<typename T>
void Tree<T>::LeftRotation(int data) {
    T* tmp = nullptr;
    tmp = search(data);
    if (tmp->ancester == tmp->ancester->ancester->LeftChild) {
        if (tmp != nullptr && tmp == tmp->ancester->RightChild) {
            T* regi = tmp->ancester->ancester;
            tmp->ancester->RightChild = nullptr;
            insertNode(&(tmp->LeftChild), &(tmp->ancester), tmp);
            tmp->ancester = regi;
            tmp->ancester->LeftChild = tmp;

        }
    }
    else if (tmp->ancester == tmp->ancester->ancester->RightChild)
    {
        if (tmp != nullptr && tmp == tmp->ancester->RightChild) {
            T* regi = tmp->ancester->ancester;
            tmp->ancester->RightChild = nullptr;
            insertNode(&(tmp->LeftChild), &(tmp->ancester), tmp);
            tmp->ancester = regi;
            tmp->ancester->RightChild = tmp;

        }
    }
}
template<typename T>
void Tree<T>::RightRotation(int data) {
    T* tmp = nullptr;
    tmp = search(data);
    if (tmp->ancester == tmp->ancester->ancester->LeftChild) {
        if (tmp != nullptr && tmp == tmp->ancester->LeftChild) {
            T* regi = tmp->ancester->ancester;
            tmp->ancester->LeftChild = nullptr;
            insertNode(&(tmp->RightChild), &(tmp->ancester), tmp);
            tmp->ancester = regi;
            tmp->ancester->LeftChild = tmp;

        }
    }
    else if (tmp->ancester == tmp->ancester->ancester->RightChild)
    {
        if (tmp != nullptr && tmp == tmp->ancester->LeftChild) {
            T* regi = tmp->ancester->ancester;
            tmp->ancester->LeftChild = nullptr;
            insertNode(&(tmp->RightChild), &(tmp->ancester), tmp);
            tmp->ancester = regi;
            tmp->ancester->RightChild = tmp;

        }
    }
}
template class Tree<TreeNode>;
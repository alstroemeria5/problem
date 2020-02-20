#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED
#include <iostream>
#include <vector>
#if !defined(nullptr)
#define nullptr NULL
#endif
using namespace std;
class TreeNode{
    public:
        TreeNode* LeftChild;
        TreeNode* RightChild;
        TreeNode* ancester;
        int data;
        TreeNode(int data):data(data),LeftChild(nullptr),RightChild(nullptr),ancester(nullptr){};
        bool operator>(TreeNode& tmp){
        return this->data>tmp.data;
        }
        bool operator<(TreeNode& tmp){
        return this->data<tmp.data;
        }
        bool operator==(TreeNode& tmp){
        return this->data=tmp.data;
        }
        bool operator>=(TreeNode& tmp){
        return this->data>=tmp.data;
        }
        bool operator<=(TreeNode& tmp){
        return this->data<=tmp.data;
        }
         bool operator>(TreeNode* tmp){
        return this->data>tmp->data;
        }
        bool operator<(TreeNode* tmp){
        return this->data<tmp->data;
        }
        bool operator==(TreeNode* tmp){
        return this->data=tmp->data;
        }
        bool operator>=(TreeNode* tmp){
        return this->data>=tmp->data;
        }
        bool operator<=(TreeNode* tmp){
        return this->data<=tmp->data;
        }

};
template<typename T>
class Tree{
    public:
        T* root;
        int insertNode(T **start,int data,T* ancester);
        int insertNode(T** start, T** data, T* ancester);

        
        Tree& operator+(int data);
        void operator-(int data);
        T& operator[](int number);
        void operator*(Tree& operand);
        void operator/(Tree& operand);
        
        Tree():root(nullptr){};
        ~Tree() {
            deleteTree();
        }

        T& GetNumber(int number);
        vector<int>& getArray(Tree& operand);
        vector<int>& ReturnArray();

        void preorder();
        void inorder();
        void postorder();

        void remove(int data);
        void deleteTree();
        T* search(int data);

        void LeftRotation(int data);
        void RightRotation(int data);
    private:
        void preorderVector(T* start);
        void inorderVector(T* start);
        void postorderVector(T* start);
        void RefreshArry(int s);
        vector<int> arry;
};

#endif // TREE_HPP_INCLUDED

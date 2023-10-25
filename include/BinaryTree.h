/**
 * @file BinaryTree.h
 * 
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * 
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <string>

class BinaryTree {
    
    private:
        struct TreeNode {
            std::string entry;
            TreeNode* leftSubTree;
            TreeNode* rightSubTree;

            TreeNode(std::string nodeValue): entry(nodeValue) {}
            void setSubsequentSubTrees(std::string leftSubTree, std::string rightSubTree);
        };
        typedef TreeNode* TreePointer;
        TreePointer root;

    public:
        
        [[deprecated("Not implemented")]]
        ~BinaryTree();

        [[deprecated("Not implemented")]]
        static BinaryTree& readTreeFromFile(std::string&& filepath);
        
        [[deprecated("Not implemented")]]
        void showTreeInformations();

        [[deprecated("Debugging method")]]
        void printTree();

    private:

        BinaryTree();

        BinaryTree& withInitialNode(std::string initialNode, std::string leftSubTree, std::string rightSubTree);

        void printTree(TreePointer &t, int s);
};

#endif
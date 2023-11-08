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

            TreeNode(std::string nodeValue);
            static TreeNode* createNode(std::string nodeValue);
            void setSubsequentSubTrees(std::string leftSubTree, std::string rightSubTree);
        };
        typedef TreeNode* TreePointer;
        TreePointer root;
        
    public:
        
        ~BinaryTree();

        static BinaryTree* readTreeFromFile(std::string&& filepath);
        
        BinaryTree* showTreeInformations();

        [[deprecated("Used only for testing")]]
        void printTree();

    private:

        BinaryTree();

        void destroyTree(TreePointer node);

        BinaryTree* withInitialNode(std::string initialNode, std::string leftSubTree, std::string rightSubTree);

        BinaryTree* followedBy(std::ifstream&& treeFile);

        void findPositionThenSetSubtrees(TreePointer currentNode, std::string nodeValue, std::string leftSubTreeValue, std::string rightSubTreeValue);

        void printTree(TreePointer &t, int s);

        void printNode(TreePointer &node, int &totalDeFilhos);
        
        void showTreeInformations(TreePointer &r, int &totalDeNos, int &totalDeFilhos);
};

#endif
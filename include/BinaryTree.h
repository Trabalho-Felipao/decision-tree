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
            TreeNode* leftNode;
            TreeNode* rightNode;

            // TreeNode()
        };
        typedef TreeNode* TreePointer;
        TreeNode root;

    public:
        
        [[deprecated("Not implemented")]]
        static BinaryTree& readTreeFromFile(std::string&& filepath);
        
        [[deprecated("Not implemented")]]
        void showTreeInformations();
};

#endif
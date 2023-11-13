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

// TODO: Documentar
class BinaryTree {
    
    private:

        // TODO: Documentar
        struct TreeNode {

            std::string entry;
            TreeNode* leftSubTree;
            TreeNode* rightSubTree;

            /**
             * @brief Constrói uma nova struct do tipo TreeNode.
             * 
             * @param nodeValue Valor de chave do nó.
             */
            TreeNode(std::string nodeValue);
            
            /**
             * @brief Aloca um TreeNode e verifica se a alocação ocorreu com sucesso.
             *  Caso ocorra falha na alocação, o programa é abortado.
             * 
             * @param nodeValue Valor de chave do nó a ser alocado.
             * @return TreeNode* Ponteiro para o nó alocado.
             */
            static TreeNode* createNode(std::string nodeValue);
            
            // TODO: Documentar
            void setSubsequentSubTrees(std::string leftSubTree, std::string rightSubTree);
        };
        typedef TreeNode* TreePointer;
        TreePointer root;
        
    public:
        
        /**
         * @brief Destrói o objeto BinaryTree.
         * 
         */
        ~BinaryTree();

        static BinaryTree* readTreeFromFile(std::string&& filepath);
        
        BinaryTree* showTreeInformations();

    private:

        BinaryTree();

        void destroyTree(TreePointer node);

        BinaryTree* withInitialNode(std::string initialNode, std::string leftSubTree, std::string rightSubTree);

        BinaryTree* followedBy(std::ifstream&& treeFile);

        void findPositionThenSetSubtrees(TreePointer currentNode, std::string nodeValue, std::string leftSubTreeValue, std::string rightSubTreeValue);

        void showTreeInformations(TreePointer &r, int &totalDeNos, int &totalDeFilhos);
        
        void printNode(TreePointer &node, int &totalDeFilhos);
};

#endif
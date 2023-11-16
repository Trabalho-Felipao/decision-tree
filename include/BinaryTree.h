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

/**
 * @brief Classe que representa uma arvore binaria
 * 
 * Implementa a arvore, seu construtor e destrutor e seus nós.
*/
class BinaryTree {
    
    private:

        /**
         * @brief Estrutura que implementa os nós da arvore.
        */
        struct TreeNode {

            std::string entry;
            TreeNode* leftSubTree;
            TreeNode* rightSubTree;

            /**
             * @brief Constrói uma nova struct do tipo TreeNode.
             * 
             * @param nodeValue Valor de chave do nó.
             */
            TreeNode(const std::string nodeValue);
            
            /**
             * @brief Aloca um TreeNode e verifica se a alocação ocorreu com sucesso.
             *  Caso ocorra falha na alocação, o programa é abortado.
             * 
             * @param nodeValue Valor de chave do nó a ser alocado.
             * @return TreeNode* Ponteiro para o nó alocado.
             */
            static TreeNode* createNode(const std::string nodeValue);
            
            // TODO: Documentar
            void setSubsequentSubTrees(const std::string leftSubTree, const std::string rightSubTree);
        };
        
        typedef TreeNode* TreePointer;
        TreePointer root;
        
    public:
        
        /**
         * @brief Destrói o objeto BinaryTree.
         * 
         */
        ~BinaryTree();

        /**
         * @brief Cria uma estrutura de árvore binária à partir de um arquivo de
         *  texto contendo seus dados.
         * 
         * @param filepath Caminho do arquivo que contém os dados.
         * @return BinaryTree* Ponteiro para o objeto árvore instanciado e populado.
         */
        static BinaryTree* readTreeFromFile(const std::string&& filepath);
        
        BinaryTree* showTreeInformations();

    private:

        BinaryTree();

        void destroyTree(TreePointer node);

        /**
         * @brief Aloca o nó raiz e os nós de suas subárvores com seus valores já
         *  inicializados. Esses valores são lidos da primeira linha do arquivo.
         * 
         * @param initialNode Valor do nó raiz.
         * @param leftSubTree Valor do nó raiz da subárvore esquerda.
         * @param rightSubTree Valor do nó raiz da subárvore direita.
         * @return BinaryTree* Ponteiro para o próprio objeto.
         */
        BinaryTree* withInitialNode(const std::string initialNode, const std::string leftSubTree, const std::string rightSubTree);

        /**
         * @brief Aloca o restante dos nós das árvores a partir do arquivo. Lê todo
         *  o arquivo até encontrar uma linha escrito "X X X".
         * 
         * @param treeFile Arquivo contendo os dados da árvore.
         * @return BinaryTree* Ponteiro para o próprio objeto.
         */
        BinaryTree* followedBy(std::ifstream&& treeFile);

        /**
         * @brief Procura recursivamente na árvore o nó já alocado e, assim que o
         *  encontra, aloca os nós raízes de suas subárvores.
         * 
         * @param currentNode Nó atual em que o método está processando. 
         * @param nodeValue Valor do nó a ser encontrado.
         * @param leftSubTree Valor do nó raiz da subárvore esquerda.
         * @param rightSubTree Valor do nó raiz da subárvore direita.
         */
        void findPositionThenSetSubtrees(TreePointer currentNode, const std::string nodeValue, const std::string leftSubTreeValue, const std::string rightSubTreeValue);

        void showTreeInformations(TreePointer &r, int &totalDeNos, int &totalDeFilhos);
        
        void printNode(TreePointer &node, int &totalDeFilhos) const;
};

#endif
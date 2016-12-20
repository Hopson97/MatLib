#ifndef TREE_MAP_H
#define TREE_MAP_H

#include <cstdint>
#include <iostream>

namespace MatLib
{
    template<typename Key, typename Value>
    class Tree_Map
    {
        struct Node
        {
            Node(const Key& key, Value value)
            :   key     (key)
            ,   value   (value)
            { }

            Node* left  = nullptr;
            Node* right = nullptr;

            const Key   key;
            Value value;
        };

        public:
            ~Binary_Tree_Map()
            {
                destroy(m_root);
            }

            void insert(Key key, Value value)
            {
                insert(&m_root, key, value);
            }

            Value& get(Key key)
            {
                return get(m_root, key);
            }

            void erase(const Key& key)
            {

            }

            uint64_t getSize() const
            {
                return m_size;
            }

        private:
            void destroy(Node* node)
            {
                if (node)
                {
                    destroy(node->left);
                    destroy(node->right);
                    delete node;
                }
            }

            //Search the tree until a node is found with the same key as
            //the one passed into the function
            Value& get(Node* node, Key key)
            {
                if (node->key == key)
                {
                    return node->value;
                }
                else if (key < node->key)
                {
                    get(node->left, key);
                }
                else if (key > node->key)
                {
                    get(node->right, key);
                }
            }

            //Insert
            void insert(Node** node, Key key, Value value)
            {
                if (!*node)  //Node is null? Create a node.
                {
                    *node = new Node(key, value);
                    m_size++;
                }
                else if (key < (*node)->key)  //Else, we must search the tree until a node is found to be null in order to insert
                {
                    insert(&(*node)->left, key, value);
                }
                else
                {
                    insert(&(*node)->right, key, value);
                }
            }

            Node* m_root = nullptr;
            uint64_t m_size = 0;
    };

}

#endif // TREE_MAP_H

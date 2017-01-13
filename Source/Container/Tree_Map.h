#ifndef TREE_MAP_H_INC
#define TREE_MAP_H_INC

#include <cstdint>
#include <iostream>

//This is a non-self balancing tree.
//So it is very simple and not very good, but it is my first tree I have made
namespace MatLib
{
    template<typename Key, typename Value>
    class Tree_Map
    {
        struct Node
        {
            template<typename... Args>
            Node(const Key& key, Args&&... args)
            :   key     (key)
            ,   value   (std::forward<Args>(args)...)
            { }

            Node* left  = nullptr;
            Node* right = nullptr;

            const Key   key;
            Value value;
        };

        public:
            ~Tree_Map()
            {
                destroy(m_root);
            }

            void insert(Key key, Value value)
            {
                insert(key, value);
            }

            template<typename... Args>
            void insert(Key key, Args&&... args)
            {
                insert(&m_root, key, std::forward<Args>(args)...);
            }

            Value& get(Key key)
            {
                return getNode(m_root, key)->value;
            }

            void erase(Key key)
            {

            }

            void clear()
            {
                destroy(m_root);
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
            Node* getNode(Node* base, Key key)
            {
                //std::cout << key << " " << base->key << std::endl;
                if (base->key == key)
                {
                    return base;
                }
                else if (key < base->key)
                {
                    getNode(base->left, key);
                }
                else
                {
                    getNode(base->right, key);
                }
            }

            //Insert
            template<typename... Args>
            void insert(Node** base, Key key, Args&&... args)
            {
                if (!*base)  //Node is null? Create a node.
                {
                    *base = new Node(key, std::forward<Args>(args)...);
                    m_size++;
                }
                else if (key < (*base)->key)  //Else, we must search the tree until a node is found to be null in order to insert
                {
                    insert(&(*base)->left, key, std::forward<Args>(args)...);
                }
                else
                {
                    insert(&(*base)->right, key, std::forward<Args>(args)...);
                }
            }


            Node* m_root = nullptr;
            uint64_t m_size = 0;
    };

}

#endif // TREE_MAP_H_INC

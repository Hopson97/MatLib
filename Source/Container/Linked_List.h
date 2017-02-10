#ifndef DOUBLE_LINKED_LIST_H_INCLUDED
#define DOUBLE_LINKED_LIST_H_INCLUDED

#include <cstdlib>
#include <utility>

namespace MatLib
{

template <typename T>
class Linked_List
{
    struct Node;

    Node*   m_first     = nullptr;
    Node*   m_last      = nullptr;
    size_t  m_count     = 0;

    struct Node
    {
        T       data;
        Node*   prev = nullptr;
        Node*   next = nullptr;

        template<typename... Args>
        Node (Args&&... data)
        :   data (std::forward<Args>(data)...)
        { }
    };

    public:
        class Iterator
        {
            friend class Linked_List;

            public:
                Iterator(Node* node)
                :   node      (node)
                { }


                friend bool operator!=(typename Linked_List<T>::Iterator left, typename Linked_List<T>::Iterator right)
                {
                    return left.node != right.node;
                }

                T& operator *() const
                {
                    return node->data;
                }

                Iterator& operator++()
                {
                    node = node->next;
                    return *this;
                }

                Iterator& operator++(int)
                {
                    node = node->next;
                    return *this;
                }

                Iterator& operator--()
                {
                    node = node->prev;
                    return *this;
                }

                Iterator& operator--(int)
                {
                    node = node->prev;
                    return *this;
                }

                Iterator& operator+ (int x)
                {
                    for (int i = 0 ; i < x ; i++)
                    {
                        node = node->next;
                    }

                    return *this;
                }

            private:
                Node* node;
            };


        //Default
        Linked_List () = default;

        //Move constructor
        Linked_List (Linked_List&& other)
        : m_first   (other.m_first)
        , m_last    (other.m_last)
        , m_count   (other.m_count)
        {
            other.m_first = nullptr;
            other.m_last = nullptr;
            other.m_count = 0;
        }

        //Copy constructor
        Linked_List (Linked_List& other)
        {
            *this = other; //Uses the copy assignment for this class
        }

        //Copy assignment
        Linked_List& operator= (const Linked_List& other)
        {
            clear();

            Node* conductor = other.m_first;

            while ( conductor->next )
            {
                push_back( conductor->data );

                conductor = conductor->next;
            }

            return *this;
        }

        //Move assignment
        Linked_List& operator= (Linked_List&& other)
        {
            clear();

            m_first     = other.m_first;
            m_last      = other.m_last;
            m_count     = other.m_count;

            other.m_first = nullptr;
            other.m_last = nullptr;
            other.m_count = 0;

            return *this;
        }

        ~Linked_List()
        {
            clear();
        }

        void clear ()
        {
            while (!empty())
                erase(begin());
        }

        void erase (Iterator it)
        {
            if (it.node == m_first)
            {
                Node* temp = it.node;

                m_first = temp->next;
                m_count--;

                delete temp;
                return;
            }
            if (it.node == m_last)
            {
                Node* temp = m_last;

                m_last = temp->prev;
                m_count--;

                delete temp;
                return;
            }
            if ( it.node->next )
                it.node->next->prev = it.node->prev;
            if ( it.node->prev )
                it.node->prev->next = it.node->next;

            delete it.node;
            m_count--;
        }

        void push_back (const T& data)
        {
            emplace_back(data);
        }

        void push_front(const T& data)
        {
            emplace_front(data);
        }

        void push_back (const T&& data)
        {
            emplace_back(data);
        }

        void push_front(const T&& data)
        {
            emplace_front(data);
        }

        template <typename... Args>
        void emplace_back ( Args&&... data )
        {
            Node* node = new Node( std::forward<Args>(data)... );

            if (tryInsertIfEmpty( node ) ) return;

            m_last->next = node;
            node->prev = m_last;
            m_last = node;

            m_count++;
        }

        template <typename... Args>
        void emplace_front (Args&&... data)
        {
            Node* node = new Node( std::forward<Args>(data)... );

            if ( tryInsertIfEmpty(node)) return;

            m_first->prev = node;
            node->next = m_first;
            m_first = node;

            m_count++;
        }

        void insert(Iterator iterator, T&& value)
        {

        }

        void insert(Iterator iterator, T& value)
        {

        }

        bool empty ()
        {
            return m_count == 0;
        }
/*
        T&  operator [] (const size_t where)
        {
            Node* conductor = getToNode( where );

            return conductor->data;
        }

        const T& operator [] (const size_t where) const
        {
            Node* conductor = getToNode(where);

            return conductor->data;
        }
*/
        const T& front  () const    { return m_first->data; }

        const T& back   () const    { return m_last->data;}


        T& front    ()  { return m_first->data; }

        T& back     ()  { return m_last->data; }


        Iterator begin  ()  { return {m_first}; }

        Iterator end    ()  { return {nullptr}; }

        std::size_t size () const { return m_count; }

    private:
/*
        void erase(Node** nodeToErase, Node* node)
        {
            Node** temp = nodeToErase;

            node
        }
*/

        bool tryInsertIfEmpty (Node* node)
        {
            if (empty())
            {
                m_first = node;
                m_last = node;
                m_count++;
                return true;
            }
            return false;
        }
};

}//Namespace MatLib

#endif // DOUBLE_LINKED_LIST_H_INCLUDED

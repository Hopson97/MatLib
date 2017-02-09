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
            while (!empty()) erase(0);
        }

        void erase (const size_t where)
        {
            Node* conductor = getToNode( where);

            if ( where == 0 )
            {
                Node* temp = conductor;
                m_first = temp->next;
                decreaseNodeCount();
                delete temp;
                return;
            }
            if ( where == m_count - 1 )
            {
                Node* temp = conductor;
                m_last = temp->prev;
                decreaseNodeCount();
                delete temp;
                return;
            }
            if ( conductor->next )
                conductor->next->prev = conductor->prev;
            if ( conductor->prev )
                conductor->prev->next = conductor->next;

            delete conductor;
            decreaseNodeCount();
        }

        void push_back (T& data)
        {
            addToBack(std::move(data));
        }

        template <typename... Args>
        void push_back ( Args&&... data )
        {
            Node* node = new Node( std::forward<Args>(data)... );

            if (tryInsertIfEmpty( node ) ) return;

            m_last->next = node;
            node->prev = m_last;
            m_last = node;

            increaseNodeCount();
        }

        template <typename... Args>
        void push_front (Args&&... data)
        {
            Node* node = new Node( std::forward<Args>(data)... );

            if ( tryInsertIfEmpty(node)) return;

            m_first->prev = node;
            node->next = m_first;
            m_first = node;

            increaseNodeCount();
        }

        bool empty ()
        {
            return m_count == 0;
        }

        T&  operator [] ( const size_t where )
        {
            Node* conductor = getToNode( where );

            return conductor->data;
        }

        const T& operator [] (const size_t where) const
        {
            Node* conductor = getToNode(where);

            return conductor->data;
        }

        const T& front () const
        {
            return m_first->data;
        }

        const T& back () const
        {
            return m_last->data;
        }

        std::size_t size ()
        {
            return m_count;
        }

    private:
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

        void increaseNodeCount ()
        {
            m_count++;
        }

        void decreaseNodeCount ()
        {
            m_count--;
        }

        Node* getToNode (size_t where)
        {
            Node* conductor = nullptr;

            if (where <= m_count / 2)
            {
                conductor = m_first;
                for (size_t i = 0 ; i < where ; i ++)
                {
                    conductor = conductor->next;
                }
            }
            else
            {
                where = m_count - where;
                conductor = m_last;
                for (size_t i = 0 ; i < where - 1 ; i ++)
                {
                    conductor = conductor->prev;
                }
            }


            return conductor;
        }
};

}//Namespace MatLib

#endif // DOUBLE_LINKED_LIST_H_INCLUDED

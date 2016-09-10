#pragma once

/***
    A linked list is a liner collection of data in the form of a list.

    It was invented in the 1950's when some programmers needed
    a data structure to hold information in a new programming language "IPL"
    Source: https://en.wikipedia.org/wiki/Linked_list#History

    It has the form:

     ________            ________            ________            ________
    |  Node  |          |  Node  |          |  Node  |          |  Node  |
    |--------|          |--------|          |--------|          |--------|
    | T Data |          | T Data |          | T Data |          | T Data |
    |--------|          |--------|          |--------|          |--------|
    | Node*  |          | Node*  |          | Node*  |          | Node*  |
    |   next |--------->|   next |--------->|   next |--------->|   next |
    |--------|          |--------|          |--------|          |--------|

    This allows quick and easy insertion and deletion of elements of the list,
    as all you have to do is change where the Node* of the lists point to, though
    it is prefered to use an array-type (such a std::vector) because a linked list
    is slower as the linked list has nodes scattered around memory, while an array
    has the data stored directly next to each other.

*/

namespace MatLib
{

template <typename T>
class Forward_List
{
    class Node
    {
        public:
            /*****************************************************************************************************
            *   Node()              :   Just a constructor for a Node
            *   "const T& value"    :   The value the Node will hold
            *****************************************************************************************************/
            template<typename... Args>
            Node( Args&&... data )
            :   data    ( std::forward<Args>( data ) ... )
            ,   next    ( nullptr )
            { }

            T data;
            Node* next;
    };

    public:

        Forward_List()
        :   nodeCount   ( 0 )
        ,   first       ( nullptr )
        ,   last        ( nullptr )
        { }

        /*****************************************************************************************************
        *   push_front()        :   Adds a new node to the front of the list
        *   "Args&& args    "   :   Arguments to create the object
        *****************************************************************************************************/
        template<typename... Args>
        void
        push_front ( Args&&... data )
        {
            Node* node = new Node( ( std::forward<Args>( data ) )... ); //"Perfect forwarding" the nodes data into its constructor

            if ( !last ) {              //If the last node is a null pointer, it means the list is empty
                last = node;            //So the last node is pointed to the new node in the list straight away
            }
            if ( first ) {              //If the list is not empty, it means I need to change the first pointer in the list
                node->next = first;     //Because I are pushing to the front, I set the new nodes next to point at the current first node
            }
            first = node;               //...and then I set the first node to point to the new first node in the list
            nodeCount++;
        }

        /*****************************************************************************************************
        *   push_back()         :   Adds a new node to the back of the list
        *   "Args&& args    "   :   Arguments to create the object
        *****************************************************************************************************/
        template<typename... Args>
        void
        emplace_back ( Args&&... data )
        {
            Node* node = new Node( ( std::forward<Args>( data ) )... ); //"Perfect forwarding" the nodes data into its constructor

            if ( !first ) {             //If the first node is a null pointer, it means the list is empty
                first = node;           //So the first node is pointed to the new node in the list straight away
            }
            if ( last ) {               //If the list is not empty, it means I need to change the last pointer in the list
                last->next = node;      //Because I are pushing to the back, so I set the next node after the last node to point at the new node
            }
            last = node;                //...and then I set the last node to point to the new last node in the list
            nodeCount++;
        }

        /*****************************************************************************************************
        *   insert()            :   Inserts a node into the list at a specified location
        *   "const size_t index"   :   index in the list to insert the node (index the first element's "index" = 0).
        *   "Args&&... data"    :   The value that the new node will hold.
        *****************************************************************************************************/
        template<typename... Args>
        void
        insert ( Args&&... data, const size_t index )
        {
            if ( index == 0 ) {
                push_front ( ( std::forward<Args>( data ) )... );           //"Perfect forwarding" the nodes data into a function
                return;
            }
            if ( index == nodeCount ) {
                push_back ( ( std::forward<Args>( data ) )... );            //"Perfect forwarding" the nodes data into a function
                return;
            }

            Node* conductor = first;                    //We use a pointer to a node to iterate through the list
            Node* node = new Node( ( std::forward<Args>( data ) )... );     //"Perfect forwarding" the nodes data into its constructor
            for ( int i = 0; i < index - 1 ; i++ ) {
                conductor = conductor->next;            //Get to the node before where we are inserting
            }
            node->next = conductor->next;
            conductor->next = node;
            nodeCount++;
        }

        /*****************************************************************************************************
        *   erase()             :   Erases a node in the list at a specified location
        *   "const int index"   :   index in the list to erase the node (note the first element's "index" = 0).
        *****************************************************************************************************/
        void
        erase ( const size_t index )
        {
            if ( index == 0 ) {
                eraseNode( &first, &first->next );  //Special case for the first node
                return;
            }

            Node* conductor = first;                     //We use a pointer to a node to iterate through the list
            for ( size_t i = 0; i < index - 1 ; i++) {
                conductor = conductor->next;
            }
            if( index == nodeCount - 1 ) {      //Special case for the last node
                last = conductor;
            }
            eraseNode( &conductor->next, &conductor->next->next);
        }

        /*****************************************************************************************************
        *   operator[]()        :   Returns the value of a node at a specified location
        *   "const size_t index"   :   Which node's value in the list to return (where the first element's "index" = 0).
        *****************************************************************************************************/
        T&
        operator[]( const size_t index )
        {
            Node* conductor = first;                //We use a pointer to a node to iterate through the list
            for ( size_t i = 0; i < index ; i++) {
                conductor = conductor->next;
            }
            return conductor->data;
        }

        /*****************************************************************************************************
        *   clear() Completely clear the list of all nodes
        *****************************************************************************************************/
        void
        clear()
        {
            while ( first ) {
                erase( 0 );
            }
        }

        /*****************************************************************************************************
        *   size()  :   Returns the number of elements in the list
        *****************************************************************************************************/
        size_t size()
        const
        {
            return nodeCount;
        }

        ~Forward_List()
        {
            clear();
        }

    private:
        size_t nodeCount;

        Node* first;
        Node* last;

        /*****************************************************************************************************
        *   eraseNode ()    :   Erases a specific node in the linked list
        *   Node**  toErase :   A pointer to the node that will be erased
        *   Node**  next
        *****************************************************************************************************/
        void
        eraseNode (Node** toErase, Node** next)
        {
            Node* temp = *toErase;  //Because I immediatly point the node to be erased to the next node, I need
            *toErase = *next;       //to have a pointer to that node or else it would have a memory leak
            delete temp;
            nodeCount--;
        }
};

}//Namespace MatLib

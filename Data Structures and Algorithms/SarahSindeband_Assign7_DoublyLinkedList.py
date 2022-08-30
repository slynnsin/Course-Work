# COP3410 - Assignment 7
# Chapter 7 - Data Structures and Functions
# Name: Sarah Sindeband
# Date: 4/17/2022
# Doubly Linked List

'''
Doubly Linked List Base and Deque Implementation
'''


class DoublyLinkedBase:
    '''A base class providing a doubly linked list representation. This class should not be used publicly'''

    class Node:
        '''Lightweight, nonpublic class for storing a doubly linked node.'''

        def __init__(self, element, prev, next): # initialize node’s field

            self.element = element   # user’s element
            self.prev = prev         # previous node reference
            self.next = next         # next node reference

    def __init__ (self):
        self.header = self.Node(None, None, None)
        self.trailer = self.Node(None, None, None)
        self.header.next = self.trailer # trailer is after header
        self.trailer.prev = self.header # header is before trailer
        self.size = 0 # number of elements]

    def len (self):
        '''Return the number of elements in the list.'''
        return self.size

    def is_empty(self):
        return self.size == 0

    def insert_between(self, e, predecessor, successor):
        '''Add element e between two existing nodes and return new node.'''
        newest = self.Node(e, predecessor, successor) # linked to neighbors
        predecessor.next = newest # header
        successor.prev = newest # trailer
        self.size += 1
        return newest

    def delete_node(self, node):
        '''Delete nonsentinel node from the list and return its element.'''
        # break links, reconnect
        predecessor = node.prev # head
        successor = node.next # trailer
        predecessor.next = successor 
        successor.prev = predecessor 
        self.size -= 1
        # reset node
        element = node.element      # record deleted element
        node.prev = node.next = node.element = None   # deprecate node
        return element

class Empty(Exception):
    '''Error attempting to access an element from an empty container.'''
    pass

# USING THE DOUBLY LINK BASE CLASS FOR IMPLEMENTAION OF DEQUES

class LinkedDeque( DoublyLinkedBase): # note the use of inheritance                         Create test casese
    '''Double-ended queue implementation based on a doubly linked list.'''
    
    
    def first(self):
        '''Return (but do not remove) the element at the front of the deque.'''
        if self.is_empty( ):
           raise Empty("Deque is empty")
        return self.header.next.element # real item just after header
    
    def last(self):
        '''Return (but do not remove) the element at the back of the deque.'''
        if self.is_empty( ):
          raise Empty("Deque is empty")
        return self.trailer.prev.element # real item just before trailer
   
    def insert_first(self, e):
        '''Add an element to the front of the deque.'''
        self.insert_between(e, self.header, self.header.next) # after header
        
    def insert_last(self, e):
        '''Add an element to the back of the deque.'''
        self.insert_between(e, self.trailer.prev, self.trailer) # before trailer

    def delete_first(self):
        '''Remove and return the element from the front of the deque.
    
        Raise Empty exception if the deque is empty.
        '''
        if self.is_empty( ):
            raise Empty("Deque is empty")
        return self.delete_node(self.header.next) # use inherited method
 
    def delete_last(self):
            '''Remove and return the element from the back of the deque.
            Raise Empty exception if the deque is empty.
            '''
            if self.is_empty( ):
                raise Empty("Deque is empty")
            return self.delete_node(self.trailer.prev) # use inherited method



if __name__ == "__main__":
    # create nodes
    heart = "heart"
    spade = "spade"
    clover = "clover"
    diamond = "diamond"
    L = LinkedDeque()
    L.insert_first(heart)
    L.insert_last(spade)
    L.insert_first(clover)
    L.insert_last(diamond)

    print("\nThere are ", L.len(), " elements in the deque.")

    print("\nThe first card is a", L.first())

    print("\nThe last card is a", L.last())

    L.delete_last()
    L.delete_first()
    L.delete_first()
    L.delete_first()

    # showing empty error
    L.delete_first()
    






    

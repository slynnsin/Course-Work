# COP3410 - Assignment 7
# Chapter 7 - Data Structures and Functions
# Name: Sarah Sindeband
# Date: 4/17/2022
# Udemy Circular List

'''
Taken from the Udemy course: Python for Data Structures, Algorithms and Interviews
Problem: Given a singly linked list, write a function that takes a node for the linked list and determines if the linked list is cyclic
The fucntion returns a boolean value

'''


class Node(object):
    
    def __init__(self,value):
        
        self.value = value
        self.nextnode = None

def cycle_check(node):

    # Begin both markers at the first node
    marker1 = node
    marker2 = node

    # Go until end of list
    while marker2 != None and marker2.nextnode != None:
        
        # Note
        marker1 = marker1.nextnode
        marker2 = marker2.nextnode.nextnode

        # Check if the markers have matched
        if marker2 == marker1:
            return True

    # Case where marker ahead reaches the end of the list
    return False

# Implement a function that counts the number of nodes in a circularly linked list.
def node_count(node):
    if cycle_check(node) == True:
        """if the list is cyclic, it will count the nodes"""
        start = node
        current = node
        count = 1 # starting with 1 because we are accounting for the start/first node
        while(current.nextnode != start):
            # the loop will run until the end of the list when it circles back around to the beginning
            count +=1
            current = current.nextnode  # move to the next node
        return count


"""
RUN THIS CELL TO TEST YOUR SOLUTION
"""
if __name__ == "__main__":

    # CREATE CYCLE LIST
    a = Node(1)
    b = Node(2)
    c = Node(3)

    a.nextnode = b
    b.nextnode = c
    c.nextnode = a # Cycle Here!


    # CREATE NON CYCLE LIST
    x = Node(1)
    y = Node(2)
    z = Node(3)

    x.nextnode = y
    y.nextnode = z

    #RUN A CYCLE CHECK
    print(cycle_check(a))
    print(cycle_check(x))

    print(node_count(a))

    # creating a new cycle list to test
    g = Node(1)
    h = Node(2)
    i = Node(3)
    j = Node(4)
    k = Node(5)
    l = Node(6)
    m = Node(7)
    n = Node(8)
    o = Node(9)
    p = Node(10)

    # linking the nodes
    g.nextnode = h
    h.nextnode = i
    i.nextnode = j
    j.nextnode = k
    k.nextnode = l
    l.nextnode = m
    m.nextnode = n
    n.nextnode = o
    o.nextnode = p
    p.nextnode = g # connect to first node

    print(cycle_check(g))
    print(node_count(g))

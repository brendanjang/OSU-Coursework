'''
Skeleton library class
'''


max = 0

def create(container, maxelements):
    global max
    max = maxelements
    container = container[:max]     

def add(n, container):
    if len(container) < max:
        container.append(n)
        return 1
    else:
        return 0

def inList(n, container):
    if n in container:
        return 1
    else:
        return 0

def remove(n, container):
    if inList(n, container) == 1:
        container.remove(n)
        return 1
    else:
        return 0

def removeAll(n, container):
    count = 0
    while inList(n, container) == 1:
        count += remove(n, container)
    return count

def size(container):
    return len(container)

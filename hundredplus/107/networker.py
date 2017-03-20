from bisect import *

class Edge:
    def __init__(self,wght,vtx1,vtx2):
        self.wght = wght
        self.vtx1 = vtx1
        self.vtx2 = vtx2

def equal(listing,ref):
    br = bisect_right(listing,ref)
    if br:
        return ref==listing[br-1]
    return False

def main():
    # Read edges into a list
    edges = []
    trees = []
    with open("p107_network.txt", "r") as fstream:
        for row,line in enumerate(fstream):
            trees.append([row])
            for col,val in enumerate(line.split(',')):
                val = val.strip()
                if val!="-" and val!="" and row<col:
                    edges.append(Edge(int(val),row,col))
    edges.sort(key=lambda edge: edge.wght)

    edgecount = 0
    total = sum([int(edge.wght) for edge in edges])
    while len(trees)>1:
        tree1=-1
        tree2=-1
        edge = edges.pop(0)
        for treeind,tree in enumerate(trees):
            if tree1<0 and equal(tree,edge.vtx1):
                tree1=treeind
            if tree2<0 and equal(tree,edge.vtx2):
                tree2=treeind
            if tree1>-1 and tree2>-1:
                break
        if tree1<0 or tree2<0:
            print "Erroneus tree indices"

        if tree1!=tree2:
            trees[tree1] += trees[tree2]
            trees[tree1].sort()
            trees.pop(tree2)
            edgecount += edge.wght
    print edgecount, total-edgecount

if __name__ == "__main__":
    main()

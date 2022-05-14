from random import *

def InitTest(namefile, endFileInput, endFileOutput):
    try:
        numberNodes = (int)(randrange(1, 20))
        Nodes = [0] * (numberNodes + 1)
        print(numberNodes)
        for i in range(1, numberNodes + 1):
            Nodes[i] = randrange(1, 300)
            print(Nodes[i], end = ' ')
        print()
        test = randrange(1, 10)
        print(test)
        for i in range(1, test + 1):
            firstnode = randrange(0, numberNodes)
            firstnode = firstnode + 1
            secondnode = randrange(0, numberNodes - firstnode + 1) + firstnode
            print(firstnode, secondnode)
    except NameError:
        print(NameError)



    
    



def main():
    namefile = 'IntervalTree'
    endFileInput = '.in'
    endFileOuput = '.out'
    numberTest = 1
    for  i in range(1, numberTest + 1):
        InitTest(namefile, endFileInput, endFileOuput)
        print('success')

main()

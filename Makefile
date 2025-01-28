bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h ../PRA_2425_P1/ListLinked.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp HashTable.h Dict.h TableEntry.h ../PRA_2425_P1/ListLinked.h

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp BSNode.h

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSNode.h BSTree.h Dict.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp BSTreeDict.h BSNode.h BSTree.h Dict.h TableEntry.h

clean:
	rm -rf *.o *.gch bin

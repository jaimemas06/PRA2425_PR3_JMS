#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {
	private:
		BSTree<TableEntry<V>>* tree;
	public:
		BSTreeDict(){
			tree = new BSTree<TableEntry<V>>();	
		}
		
		~BSTreeDict(){
			delete tree;
		}

		friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
			out << *(bs.tree);
			return out;
		}

		V operator[](std::string key){
			return search(key);
		}

		//Metodos de la interfaz Dict.h
		
		void insert(std::string key, V value) override{
			tree->insert(TableEntry<V>(key, value));
		}
		
		V search(std::string key) override{
			return tree->search(TableEntry<V>(key)).value;
		}

		V remove(std::string key) override{
			auto aux = tree->search(TableEntry<V>(key));
			tree->remove(aux.key);

			return aux.value;
		}

		int entries() override{
			return tree->size();
		}

};

#endif

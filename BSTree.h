#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
	private:
		//Atributos
		int nelem;
		BSNode<T> *root;


		//Metodos privados
		T search(BSNode<T>* n, T e) const{
			if (n == nullptr){
				throw std::runtime_error("Element not found!");
			} else if (e > n->elem){
				return search(n->right, e);
			} else if(e < n->elem){
				return search(n->left, e);
			} else{
				return n->elem;
			}
		}

		BSNode<T>* insert(BSNode<T>* n, T e){
			if (n == nullptr){
				return new BSNode<T>(e);
			} else if (e == n->elem){
				throw std::runtime_error("Duplicated element!");
			} else if (e < n->elem){
				n->left = insert(n->left, e);
			} else{
				n->right = insert(n->right, e);
			}
			return n;
		}


		void print_inorder(std::ostream &out, BSNode<T>* n) const{
			if (n != nullptr) {
				print_inorder(out, n->left);
				out << n->elem << " ";
				if (n->right != nullptr){
					print_inorder(out, n->right);
				}
			}
		}

		BSNode<T>* remove(BSNode<T>* n, T e){
			if (n == nullptr){
				throw std::runtime_error("Element not found!");
			} else if (e > n->elem){
				n->right = remove(n->right, e);
			} else if(e < n->elem){
				n->left = remove(n->left, e);
			} else {
				if (n->left != nullptr && n->right != nullptr){
					n->elem = max(n->left);
					n->left = remove_max(n->left);
				} else{
					n = (n->left != nullptr) ? n->left : n->right;
				}
			}
			return n;
		}

		T max(BSNode<T>* n) const{
			if (n == nullptr){
				throw std::runtime_error("Rama Vacia");
			} else if (n->right != nullptr){
				return max(n->right);
			} else{
				return n->elem;
			}
		}


		BSNode<T> *remove_max(BSNode<T>* n){
			if (n->right == nullptr){
				return n->left;
			} else{
				n->right = remove_max(n->right);
				return n;
			}
		}

		void delete_cascade(BSNode<T>* n){
			while(root != nullptr){
				root = remove_max(root);
			}
		}

	public:
		BSTree(){
			root = nullptr;
			nelem = 0;
		}
		int size() const{
			return nelem;
		}

		T search(T e) const{
			return search(root, e);
		}
		T operator[](T e) const{
			return search(e);
		}

		void insert(T e){
			root = insert(root, e);
			nelem++;
		}

		friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
			bst.print_inorder(out, bst.root);
			return out;
		}

		void remove(T e){
			root = remove(root, e);
			nelem--;
		}

		~BSTree(){
			delete_cascade(root);
		}
};

#endif


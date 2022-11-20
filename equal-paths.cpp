#include "equal-paths.h"
using namespace std;

int height(Node * root){
	if(root == nullptr){
		return 0;
	}
	else{
		if(height(root->left) >= height(root->right)){
			return 1 + height(root->left); 
		}
		else{
			return 1 + height(root->right);
		}
	}
}

bool equalPaths(Node * root)
{
		if(root == nullptr){
			return true;
		}
		else if(root->left == nullptr && root->right != nullptr){
			root = root->right;
			equalPaths(root);
		}
		else if(root->right == nullptr && root->left != nullptr){
			root = root->left;
			equalPaths(root);
		}
		else if(height(root->left) == height(root->right)){
			return true;
		}
		else{
			return false;
		}
}


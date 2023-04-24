//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree
#define nullptr NULL

#include <iostream>

using namespace std; 
 
    //Definition of the Node
template <class elemType>
struct nodeType
{
    elemType info;
    elemType key;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};
	
    //Definition of the class
template <class elemType>
class binaryTreeType
{
public:
 void insertLeft () const;// input code
 void insertRight() const;
 void getRoot() const;

  void traversal() const;
    void search() const;
    void updateNode() const;
    void addNode() const;
    void findOutcome() const;

    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&); 
      //Overload the assignment operator.

    bool isEmpty() const;
      //Function to determine whether the binary tree is empty.
      //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.

    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: Nodes are printed in inorder sequence.

    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
      //Postcondition: Nodes are printed in preorder sequence.

    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
      //Postcondition: Nodes are printed in postorder sequence.

    int treeHeight() const;
      //Function to determine the height of a binary tree.
      //Postcondition: Returns the height of the binary tree.

    int treeNodeCount() const;
      //Function to determine the number of nodes in a 
      //binary tree.
      //Postcondition: Returns the number of nodes in the 
      //               binary tree.

    int treeLeavesCount() const;
      //Function to determine the number of leaves in a 
      //binary tree.
      //Postcondition: Returns the number of leaves in the 
      //               binary tree.

    void destroyTree();
      //Function to destroy the binary tree.
      //Postcondition: Memory space occupied by each node 
      //               is deallocated.
      //               root = nullptr;

    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //Copy constructor

    binaryTreeType();   
      //Default constructor

		binaryTreeType(const elemType& item);


    ~binaryTreeType();   
      //Destructor

    void add_decision(const elemType& parent_decision, string position, const elemType& new_decision); 
    void addadecision(nodeType<elemType> *node, const elemType& parent_decision, string position, const elemType& new_decision); 


protected:
    nodeType<elemType>  *root;

private:

    void insertLeft(binaryTreeNode<elemType>*& parent, const elemType& key, const elemType& info) const;
    void insertRight(binaryTreeNode<elemType>*& parent, const elemType& key, const elemType& info) const;
    binaryTreeNode<elemType>* getRoot() const; /// input code
    void search(binaryTreeType<elemType>* p , elemType key);
    void updateNode(nodeType<elemType> *p) const;
    void traversal(binaryTreeType<elemType>* p);
    void addNode(binaryTreeType<elemType>* p);
    void findOutcome(binaryTreeType<elemType>*p);


    void copyTree(nodeType<elemType>* &copiedTreeRoot,nodeType<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. 
      //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.

    void destroy(nodeType<elemType>* &p);
      //Function to destroy the binary tree to which p points.
      //Postcondition: Memory space occupied by each node, in 
      //               the binary tree to which p points, is 
      //               deallocated.
      //               p = nullptr;

    void inorder(nodeType<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in inorder sequence.

    void preorder(nodeType<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in preorder 
      //               sequence.

    void postorder(nodeType<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in postorder 
      //               sequence.

    int height(nodeType<elemType> *p) const;
      //Function to determine the height of the binary tree
      //to which p points. 
      //Postcondition: Height of the binary tree to which 
      //               p points is returned.

    int max(int x, int y) const;
      //Function to determine the larger of x and y.
      //Postcondition: Returns the larger of x and y.

    int nodeCount(nodeType<elemType> *p) const;
      //Function to determine the number of nodes in 
      //the binary tree to which p points. 
      //Postcondition: The number of nodes in the binary 
      //               tree to which p points is returned.

    int leavesCount(nodeType<elemType> *p) const;
      //Function to determine the number of leaves in  
      //the binary tree to which p points 
      //Postcondition: The number of leaves in the binary 
      //               tree to which p points is returned.


};

	//Definition of member functions

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const elemType& item)
{
    root = new nodeType<elemType>;
		root->info = item;
		root->lLink = nullptr;
		root->rLink = nullptr;
}
template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }		
}

template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
        operator=(const binaryTreeType<elemType>& otherTree)
{ 
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)   //if the binary tree is not empty,
                            //destroy the binary tree
            destroy(root);

        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
                (const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

    //Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
    if (p == nullptr) { // Base case: empty tree
        return 0;
    } else {
        int leftCount = nodeCount(p->lLink);   // Recursively count nodes in left subtree
        int rightCount = nodeCount(p->rLink); // Recursively count nodes in right subtree
        return 1 + leftCount + rightCount;    // Count root node and combine counts from both subtrees
    }
}


template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
// If the node is null, there are no leaves
    if (p == nullptr) {
        return 0;
    }
    // If the node is a leaf, return 1
    if (p->lLink == nullptr && p->rLink == nullptr) {
        return 1;
    }
    // Recursively count the leaves in the left and right subtrees
    return leavesCount(p->lLink) + leavesCount(p->rLink);
}

template <class elemType>
void binaryTreeType<elemType>::addadecision(nodeType<elemType> *node, const elemType& parent_decision, string position, const elemType& new_decision)
{
    if (node == nullptr) {
        return;
    }

    if (node->info == parent_decision) {
        
        nodeType<elemType> *new_node = new nodeType<elemType>;
       
		new_node->info = new_decision;
		new_node->lLink = nullptr;
		new_node->rLink = nullptr;

        if (position == "left") {
            node->lLink = new_node;
        } else if (position == "right")   {
    
            node->rLink = new_node;
        } else {

            delete new_node;
        }

        return;
    }
    addadecision(node->lLink, parent_decision, position, new_decision);
    addadecision(node->rLink, parent_decision, position, new_decision);
}

template <class elemType>
void binaryTreeType<elemType>::add_decision(const elemType& parent_decision, string position, const elemType& new_decision)
{
   addadecision(root,parent_decision, position, new_decision);

}
/// input code
template<class elemType>
void binaryTreeType<elemType>::insertLeft(binaryTreeNode<elemType>*& parent, const elemType& key, const elemType& info) const {
    binaryTreeNode<elemType>* newNode = new binaryTreeNode<elemType>;
    newNode->key = key;
    newNode->info = info;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    parent->lLink = newNode;
}

template<class elemType>
void binaryTreeType<elemType>::insertRight(binaryTreeNode<elemType>*& parent, const elemType& key, const elemType& info) const {
    binaryTreeNode<elemType>* newNode = new binaryTreeNode<elemType>;
    newNode->key = key;
    newNode->info = info;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    parent->rLink = newNode;
}

template<class elemType>
binaryTreeNode<elemType>* binaryTreeType<elemType>::getRoot() const {
    return root;
}
template <class elemType>
void binaryTreeType<elemType>::search() const
{
    string key;
    bool found = false;
    cout << "Enter the question to search: ";
    cin.ignore();
    getline(cin, key);
    search(root, key, found);
    if (found) {
        cout << key << " was found in the tree." << endl;
    } else {
        cout << key << " was not found in the tree." << endl;
    }
}

template <class elemType>
void binaryTreeType<elemType>::traversal() const
{
    cout << "Traversal type: preorder, inorder or postorder" << endl;
    string type;
    cin >> type;
    if(type == "preorder"){
        preorderTraversal();
    }
    else if(type == "inorder"){
        inorderTraversal();
    }
    else if(type == "postorder"){
        postorderTraversal();
    }
    else {
        cout << "Invalid traversal type. Please try again." << endl;
    }
}

template <class elemType>
void binaryTreeType<elemType>::updateNode() const
{
    string key;
    string newInfo;
    cout << "Enter the key to update: ";
    cin >> key;

    bool found = false;
    search(key, found);

    if (found) {
        cout << "Enter the new information: ";
        cin >> newInfo;
        updateNode(key, newInfo);
        cout << "Node updated." << endl;
    } else {
        cout << key << " is not in the tree." << endl;
    }
}

template <class elemType>
void binaryTreeType<elemType>::addNode() const
{
    string parent;
    string side;
    string key;
    string info;
    cout << "Enter the parent node: ";
    cin >> parent;
    cout << "Enter the side (left or right): ";
    cin >> side;
    cout << "Enter the key for the new node: ";
    cin >> key;
    cout << "Enter the information for the new node: ";
    cin >> info;

    bool found = false;
    search(parent, found);

    if (found) {
        if (side == "left") {
            insertLeft(parent, key, info);
        } else if (side == "right") {
            insertRight(parent, key, info);
        } else {
            cout << "Invalid side. Please try again." << endl;
        }
    } else {
        cout << parent << " is not in the tree." << endl;
    }
}

template <class elemType>
void binaryTreeType<elemType>::findOutcome() const
{
    binaryTreeType<string>* node = getRoot();
    while (node->lLink != nullptr && node->rLink != nullptr) {
        string response;
        cout << node->info << "? (y/n): ";
        cin >> response;
        if (response == "y") {
            node = node->lLink;
        } else if (response == "n") {
            node = node->rLink;
        } else {
            cout << "Invalid response. Please try again." << endl;
        }
    }
    cout << "Outcome: " << node->info << endl;
}
#endif

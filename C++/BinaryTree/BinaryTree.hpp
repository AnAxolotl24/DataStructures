#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

class TreeNode{
    private:
        int val;
        TreeNode* left;
        TreeNode* right;

    friend class BinaryTree;

    public:
        TreeNode(int value);
        ~TreeNode();
};

class BinaryTree{
    private:
        TreeNode* root;
        int height;
        int size;

        void print_n_spaces(int n);
    public:
        BinaryTree();
        ~BinaryTree();
        BinaryTree(const BinaryTree& other);
        void add_value(int value);
        bool search(int value);
        void clear();
        void display();
        bool is_empty() const;
        int get_height() const;
        int get_size() const;
        int get_root() const;
        int get_max() const;
        int get_min() const;
        int count_leaves() const;
        int count_internal_nodes() const;
        int count_nodes_at_level(int n);
        bool is_full();
        int get_level(int value);
};

#endif
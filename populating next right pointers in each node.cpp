class Solution {
public:
    void connectRecursive(Node *root)
    {
        if (root == NULL)
        {
            return ;
        }
        
        /* Find the same level next node from right sub-tree */
        Node *tmpNext = root->next;
        while (tmpNext)
        {
            if (tmpNext->left)
            {
                tmpNext = tmpNext->left;
                break;
            } else if (tmpNext->right)
            {
                tmpNext = tmpNext->right;
                break;
            } else
            {
                tmpNext = tmpNext->next;
            }
        }

        if (root->left)
        {
            if (root->right)
            {
                root->left->next = root->right;
            } else
            {
                root->left->next = tmpNext;
            }
        }
        if (root->right)
        {
            root->right->next = tmpNext;
        }
        
        /* Must check right sub-tree first */
        connectRecursive(root->right);
        connectRecursive(root->left);
    }

    Node* connect(Node* root) 
    {
        if (root == NULL)
        {
            return NULL;
        }

        root->next = NULL;
        connectRecursive(root);
        return root;
    }
};

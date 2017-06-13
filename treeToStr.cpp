/*
    At first I want to implement it as the following form which get the original string:
    string trans(TreeNode* t){
        if (!t) return "()";
        return to_string(t->val)+'('+trans(t->left)+')'+')('+trans(t->right)+')';
    }
    Then try to trim it to the expected Solution
    However it won't work since the logic is really confusing when you try to remove only some of the '()'.
    So the final algorithm is modified to have nested logic decision while doing the preorder traversal


    GET INSPIRED!!!
*/

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = to_string(t->val);

        if (t->left) {
            s += "(" + tree2str(t->left) + ")";
        }
        else if (t->right) {
            s += "()";
        }

        if (t->right) {
            s += "(" + tree2str(t->right) + ")";
        }

        return s;
    }
};

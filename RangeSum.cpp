// Two different ways to build a segment tree, Tree structure is easy to understand and array structure is efficient
struct node{
    int start,end,sum;
    node* left;
    node* right;
    node(int s,int e):start(s),end(e),sum(0),left(NULL),right(NULL){}
};
class NumArray {
node* root;
public:
NumArray(vector<int> nums) {
    int n = nums.size()-1;
    root = buildtree(nums,0,n);
}

void update(int i, int val) {
    updateTree(i,val,root);
}

int sumRange(int i, int j) {
    return querySum(i,j,root);
}

node* buildtree(vector<int>& nums,int s,int e){
    if (s > e) return NULL;
    node* t = new node(s,e);
    if (s == e) {
        t->sum = nums[s];
        return t;
    }
    int mid = s+((e-s)>>1);
    t->left = buildtree(nums,s,mid);
    t->right = buildtree(nums,mid+1,e);
    t->sum = t->left->sum+t->right->sum;
    return t;
}
int updateTree(int idx,int val,node* root){
    if (!root) return 0;
    int differ;
    if (root->start ==idx && root->end == idx){
        differ = val-root->sum;
    }
    else {
        int m = root->start + ((root->end-root->start)>>1);
        if (idx <=m )differ = updateTree(idx,val,root->left);
        else differ = updateTree(idx,val,root->right);
    }
    root->sum += differ;
    return differ;
}
int querySum(int i,int j,node* root){
    if (!root) return 0;
    if (i == root->start && j == root->end) return root->sum;
    int m = root->start + ((root->end-root->start)>>1);
    if (j <=m) return querySum(i,j,root->left);
    if (i > m) return querySum(i,j,root->right);
    return querySum(i,m,root->left)+querySum(m+1,j,root->right);
}
};



class NumArray {
    int* tree;
    int n;
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        buildtree(nums);

    }

    void update(int i, int val) {
        updateTree(i,val);
    }

    int sumRange(int i, int j) {
        return querySum(i,j);
    }

    void buildtree(vector<int>& nums){
        if (n==0) return;
        tree = new int[2*n];
        for (int i =n;  i < 2*n;i++)tree[i]=nums[i-n];
        for (int i = n-1; i >=0;i--)tree[i]=tree[i*2]+tree[i*2+1];
    }
    void updateTree(int idx,int val){
        int d = idx+n;
        tree[d] = val;
        while(d){
            d >>= 1;
            tree[d] = tree[2*d]+tree[2*d+1];
        }
    }
    int querySum(int i,int j){
        int l = i+n;
        int r = j+n;
        int sum = 0;
        while (l <=r){
            if (l & 1)sum+=tree[l++];
            if (!(r & 1))sum += tree[r--];
            l >>= 1;
            r >>= 1;
        }
        return sum;
    }
};

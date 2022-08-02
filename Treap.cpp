mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
class Node{
public:
    int priority , sz; T val;
    Node *lf , *ri;
    Node(T _val){
        val = _val; sz = 1; priority = rng();
        lf = ri = NULL;
    }
};
template <class T>
class treap{
    typedef Node<T>* node;
    node Root = NULL;
    void combine(node parent){
        if (parent){
            parent->sz = size(parent->lf) + 1 + size(parent->ri);
        }
    }node createNode(T val){
        return new Node<T> (val);
    }
    void value_split(node t , node &lf , node &ri , T val){
        if ( !t ) lf = ri = NULL;
        else if ( t->val <= val ) value_split(t->ri , t->ri , ri , val) , lf = t;
        else value_split(t->lf , lf , t->lf , val) , ri = t;
        combine(t);
    }
    void size_split(node t , node &lf , node &ri , int leftSize){
        if ( !t ) lf = ri = NULL;
        else if ( size(t->lf) >= leftSize ) size_split(t->lf , lf , t->lf , leftSize) , ri = t;
        else if ( size(t->lf) + 1 == leftSize ){
            ri = t->ri; t->ri = NULL; lf = t;
        }
        else size_split(t->ri , t->ri , ri , leftSize - (size(t->lf) + 1)) , lf = t;
        combine(lf); combine(ri);
    }
    void merge( node &t , node &lf , node &ri ){
        if ( !lf or !ri ) t = (lf ? lf : ri);
        else if ( lf->priority > ri->priority ) merge(lf->ri , lf->ri , ri) , t = lf;
        else merge(ri->lf , lf , ri->lf) , t = ri;
        combine(t);}
    int size(node root){
        return (root ? root->sz : 0);
    }
    T ub(node &t , T val){
        if (!t) return -1;
        else if ( t->val <= val ) return ub(t->ri, val);
        else {
            T lf = ub(t->lf , val);
            return (lf > val ? lf : t->val);
        }
    }
    T kth(node &t , int k){
        if ( !t || k > size(t) ) return -1;
        else if ( k - size(t->lf) == 1 ) return t->val;
        else if ( k <= size(t->lf) ){
            return kth(t->lf , k);
        }
        else{
            return kth(t->ri , k - (size(t) - size(t->ri)) );
        }
    }void dfs(node &t){
        if (!t) return void();
// dfs(t->lf); cout << t->val << " "; dfs(t->ri);
        dfs(t->lf); printf("%d ", t->val); dfs(t->ri);
    }
public:
    int size(){
        return size(Root);
    }
    void insert(T val){
        if (!Root) return void(Root = createNode(val));
        node lf , mid = createNode(val) , ri;
        value_split(Root , lf , ri , val);
        merge(lf , lf , mid);
        merge(Root , lf , ri);
    }void insert(T val , int index){
        if (!Root) return void(Root = createNode(val));
        node lf , mid = createNode(val) , ri;
        size_split(Root , lf , ri , index);
        merge(lf , lf , mid);
        merge(Root , lf , ri);
    }
    void erase(T val , int freq = 1){
        node lf , mid , ri;
        value_split(Root , lf , ri , val);
        value_split(lf , lf , mid , val - 1);
        node del;
        size_split(mid , del , mid , min(freq , size(mid)));
        delete del;
        merge(lf , lf , mid);
        merge(Root , lf , ri);
    }void index_erase(int index){
        node lf , mid , ri;
        size_split(Root , lf , ri , index + 1);
        size_split(lf , lf , mid , index);
        delete mid;
        merge(Root , lf , ri);
    }
    int count(T val){
        if (val < 0){
            return 0;
        }
        node lf , mid , ri;
        value_split(Root , lf , ri , val);
//      value_split(lf , lf , mid , val - 1);
        int cnt = size(lf);
//      merge(lf , lf , mid);
        merge(Root , lf , ri);
        return cnt;
    }T kth(int k){
        return kth(Root , k);
    }
    T upper_bound(T val){
        return ub(Root , val);
    }
    T lower_bound(T val){
        return (count(val) > 0 ? val : ub(Root , val));
    }
    void print(){
        dfs(Root); puts("");
        fflush(stdout);
    }
};

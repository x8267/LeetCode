class Solution {
public:
    int find_root(int x, vector<int>& pre){
	    int x_root = x;
	    while (pre[x_root] != -1){
	        x_root = pre[x_root];
	    }
	    int i = x, j;
	    while (i != x_root){
	        j = pre[i];
	        pre[i] = x_root;
	        i = j;
	    }
	    return x_root;
	}
    int join(int x, int y, vector<int>& pre){
        int x_root = find_root(x, pre);
        int y_root = find_root(y, pre);
        if (x_root == y_root)
            return 0;
        pre[x_root] = y_root;
        return 1;
    }
    void dipart(vector<string>& equations, vector<int>& pre, vector<vector<int> >& diff) {
        for (auto& i : equations) {
            if (i[1] == '=') {
                join(i[0]-'a', i[3]-'a', pre);
            }
            else if (i[1] == '!') {
                vector<int> temp;
                temp.push_back(i[0] - 'a');
                temp.push_back(i[3] - 'a');
                diff.push_back(temp);
            }
        }
    }
    bool find(vector<int>& pre, vector<vector<int> >& diff) {
        for (auto& i : diff) {
            if (find_root(i[0], pre) == find_root(i[1], pre))
                return false;
        }
        return true;
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> pre(26, -1);
        vector<vector<int> > diff;
        dipart(equations, pre, diff);
        return find(pre, diff);
    }
};
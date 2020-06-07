class Solution {
public:
    bool is_transfer(string& word1, string& word2){
        int diff = 0;
        for (int i = 0; i < word1.length() && diff < 2; ++i){
            if (word1[i] != word2[i])
                ++diff;
        }
        return diff == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> wordid;
        vector<string> idword;
        vector<vector<int> > edges;
        int id = 0;
        for (int i = 0; i < wordList.size(); ++i){
            if (!wordid.count(wordList[i])){
                wordid[wordList[i]] = id;
                ++id;
                idword.push_back(wordList[i]);
            }
        }
        if (!wordid.count(endWord))
            return {};
        if (!wordid.count(beginWord)){
            wordid[beginWord] = id;
            ++id;
            idword.push_back(beginWord);
        }
        edges.resize(id);
        for (int i = 0; i < idword.size(); ++i){
            for (int j = i + 1; j < idword.size(); ++j){
                if (is_transfer(idword[i], idword[j])){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        int endword_id = wordid[endWord];
        vector<vector<string> > ans;
        queue<vector<int> > q;
        q.push(vector<int> {wordid[beginWord]});
        vector<int> cost(id, INT_MAX);
        cost[wordid[beginWord]] = 0;
        while(!q.empty()){
            vector<int> now_path = q.front();
            q.pop();
            int last_word_id = now_path.back();
            if (last_word_id == endword_id){
                vector<string> temp;
                for (int i = 0; i < now_path.size(); ++i){
                    temp.push_back(idword[now_path[i]]);
                }
                ans.push_back(temp);
            }
            else{
                for (int i = 0; i < edges[last_word_id].size(); ++i){
                    int next = edges[last_word_id][i];
                    if (cost[last_word_id] + 1 <= cost[next]){
                        cost[next] = cost[last_word_id] + 1;
                        vector<int> temp(now_path.begin(), now_path.end());
                        temp.push_back(next);
                        q.push(temp);
                    }
                }
            }
        }
        return ans;
    }
};
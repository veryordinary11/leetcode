class BrowserHistory {
public:

    vector<string> history;
    int cur_index;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur_index = 0;
    }
    
    void visit(string url) {
        history.resize(cur_index + 1);
        history.push_back(url);
        cur_index++;
    }
    
    string back(int steps) {
        int pre_index = max(0, cur_index - steps);
        cur_index = pre_index;
        return history[cur_index];
    }
    
    string forward(int steps) {
        int for_index = min((int)history.size() - cur_index - 1, steps);
        cur_index = for_index + cur_index;
        return history[cur_index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

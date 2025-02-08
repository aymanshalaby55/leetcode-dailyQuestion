class NumberContainers {
private:
map<int , set<int>> ind;
map<int , int> indp;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(indp[index]){
        cout << index << " " << number << endl;
        ind[indp[index]].erase(index);
       }
       
        ind[number].insert(index);
        indp[index] = number;
    }
    
    int find(int number) {
        auto val = *ind[number].begin();
        return (ind[number].size()) ? val : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
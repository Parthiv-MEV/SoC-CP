class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t posn=s.find(part);
        int part_size=part.size();
        while(posn!=-1){
            s.erase(posn, part_size);
            posn=s.find(part);
        }
        return s;
    }
};
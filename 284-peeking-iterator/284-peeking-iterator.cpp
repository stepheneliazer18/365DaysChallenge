class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {}
	
	int peek() {
        Iterator it= *this;
        return it.next();
	}
	
	int next() {
	    return Iterator ::next();
	}
	
	bool hasNext() const {
	   return Iterator:: hasNext();
	}
};
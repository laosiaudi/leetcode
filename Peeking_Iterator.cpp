/*********************************************************************************
*     File Name           :     Peeking_Iterator.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-23 20:02]
*     Last Modified       :     [2015-10-23 20:33]
*     Description         :
**********************************************************************************/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    public:
        bool hasPeeked;
        int peekEle;
	    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	        // Initialize any member here.
	        // **DO NOT** save a copy of nums and manipulate it directly.
	        // You should only use the Iterator interface methods.
            hasPeeked = false;
            peekEle = 0;
	    }

        // Returns the next element in the iteration without advancing the iterator.
	    int peek() {
           if (hasPeeked == false) {
               hasPeeked = true;
               peekEle = Iterator::next();
           }
           return peekEle;
	    }

	    // hasNext() and next() should behave the same as in the Iterator interface.
	    // Override them if needed.
	    int next() {
            if (!hasPeeked) {
                return Iterator::next();
            }
            hasPeeked = false;
            int tmp = peekEle;
            peekEle = 0;
            return tmp;
	    }

	    bool hasNext() const {
            return hasPeeked || Iterator::hasNext();
	    }
};



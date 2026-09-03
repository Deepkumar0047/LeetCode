class MyCalendar {
public:
vector<pair<int,int>> bookings;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        int left = 0,right = bookings.size();

        while(left<right){
            int mid = left + (right - left) / 2;

            if(bookings[mid].first < startTime)
            left = mid + 1;
            else
            right = mid;
        }
        if(left < bookings.size() && endTime>bookings[left].first){
            return false;
        }
        if(left > 0 && bookings[left - 1].second > startTime){
            return false;
        }
        bookings.insert(bookings.begin() + left,{startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
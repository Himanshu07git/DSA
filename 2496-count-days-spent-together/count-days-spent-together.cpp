class Solution {
public:
    int convert(string s, int days[]){
        int month= stoi(s.substr(0,2));
        int day= stoi(s.substr(3,2));

        for(int i=0; i<month; i++){
            day=day+days[i];
        }
        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
       int days[]= { 0, 31,28,31,30,31,30,31,31,30,31,30,31};

       int a1= convert(arriveAlice, days);
       int a2= convert(leaveAlice, days); 
       int a3= convert(arriveBob, days);
       int a4= convert(leaveBob, days);

       int start= max(a1, a3);
       int end= min(a2,a4);

       return max(0, end-start+1);
    }
};
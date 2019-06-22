int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n <= 1) return 1;
        
        int lower = 1, higher = n;
        int middle = lower + (higher - lower)/2;
        int temp = guess(middle);
        while((temp != 0) && lower != higher)
        {
            cout << "temp:" << temp << endl;
            cout << endl << middle << endl;
            if(temp == -1) 
            {
                higher = middle-1;
                cout << endl << "higher: " << higher << endl;
            }
            else if(temp == 1) 
            {
                lower = middle+1;
                cout << endl << "lower: " << lower << endl;
            }
            //middle = (lower + higher)/2;//lower+higher超出int界限了
            middle = lower + (higher - lower)/2;
            cout << "middle:" << middle << endl;
            temp = guess(middle);
            //if(middle == 0 || middle == n) break;
        }
        return middle;
        
    }
};

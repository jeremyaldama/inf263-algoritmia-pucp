//https://leetcode.com/problems/binary-watch/description/
//Técnica: Bin-Packing

class Solution {
public:

    void chromosome(int *chromo, int n, int num){
        for (int i=0; i<n; i++){
            chromo[n-i-1] = num&1;
            num >>= 1;
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        int hours[] = {8, 4, 2, 1};
        int n_hours = sizeof(hours)/sizeof(int);
        int hours_chromo[n_hours];
        int minutes[] = {32, 16, 8, 4, 2, 1};
        int n_minutes = sizeof(minutes)/sizeof(int);
        int minutes_chromo[n_minutes];
        int comb_hours = pow(2, n_hours);
        int comb_minutes = pow(2, n_minutes);

        int num_bin;
        int hours_time=0;
        int minutes_time=0;

        vector<string> string_hours;

        for (int i=0; i<comb_hours; i++){
            num_bin = 0;
            chromosome(hours_chromo, n_hours, i);

            hours_time = 0;
            for (int j=0; j<n_hours; j++){
                if (hours_chromo[j]){
                    num_bin++;
                    hours_time += hours[j];
                }
            }

            for (int j=0; j<comb_minutes; j++){
                chromosome(minutes_chromo, n_minutes, j);
                minutes_time = 0;
                int new_num_bin = num_bin;
                for (int k=0; k<n_minutes; k++){
                    if (minutes_chromo[k]){
                        new_num_bin++;
                        minutes_time += minutes[k];
                    }
                }

                if (new_num_bin==turnedOn && hours_time<=11 && minutes_time<=59){
                    char hC[4];
                    char minC[4];
                    string s;
                    sprintf(hC,"%d:",hours_time);
                    sprintf(minC,"%02d", minutes_time);
                    s="";
                    s+=hC;
                    s+=minC;
                    string_hours.emplace_back(s);
                }
            }
        }
        return string_hours;
    }
};
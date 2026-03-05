class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size() , n = bank.size();
        int recent = 0;

        int laserBeams = 0;
        for (auto& line : bank){
            int count = 0;
            for (auto& laser : line){
                if (laser == '1') count++;
            }

            if (recent == 0) {
                recent = count;
                continue;
            }

            laserBeams += (recent * count);

            if (count != 0)
                recent = count;

        }

        return laserBeams;
    }
};
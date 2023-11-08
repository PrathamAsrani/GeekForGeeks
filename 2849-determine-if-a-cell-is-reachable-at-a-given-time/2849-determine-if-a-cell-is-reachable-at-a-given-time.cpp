class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // if(fx == sx && sy == fy && t == 1) return false;
        // bool isX_Neg = false, isY_Neg = false;
        // if(fx < sx) isX_Neg = true;
        // if(fy < sy) isY_Neg = true;
        // while(sx != fx && sy != fy){
        //     t--;
        //     if(t < 0) return false;
        //     if(isX_Neg) sx--;
        //     else sx++;
        //     if(isY_Neg) sy--;
        //     else sy++;
        //     if(fx == sx && sy == fy) return true;
        // }
        // if(fx == sx) return (abs(sy - fy) <= t)? true:false;
        // if(fy == sy) return (abs(sx - fx) <= t)? true:false;
        // return false;
        
        int hor_dist = abs(sy-fy), ver_dist = abs(sx-fx), minTime = max(hor_dist, ver_dist);
        if(t < minTime) return false;
        else if(hor_dist == 0 && ver_dist == 0 && t == 1) return false;
        return true;
    }
};
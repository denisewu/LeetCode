//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxCount = 0;
        unordered_map<double, int> map;
        for(int i = 0; i < points.size(); i++)
        {
            map.clear();
            int duplicate = 1;
            Point p1 = points[i];
            int max = 0;
            for(int j = 0; j < points.size(); j++)
            {
                if(j == i)
                    continue;
                Point p2 = points[j];
                if(p2.x == p1.x && p2.y == p1.y)
                {
                    duplicate++;
                    continue;
                }
                double k;
                if(p1.x == p2.x)
                    k = INT_MAX;
                else
                    k = float(p2.y - p1.y) / float(p2.x - p1.x);
                if(map.find(k) == map.end())
                    map.insert(pair<double, int>(k, 1));
                else
                    map[k]++;
                if(map[k]> max)
                    max = map[k];
            }
            if(max + duplicate > maxCount)
                maxCount = max + duplicate;
        }
        return maxCount;
    }
};

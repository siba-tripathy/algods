#include<iostream>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>

using namespace std;
//https://www.codechef.com/submit/AMCS03
// Wrong answer dont know why

double calculateDistanceTravelled(double time, int speed, int startPosition) {
    return time*speed + startPosition;
}

// double gapAt(double time, vector<int>& speeds, vector<int>& startPositions) {
//     double maxDist = 0.0, minDist= DBL_MAX;
//     for(int i = 0; i<speeds.size(); i++) {
//         double distanceTravelled = calculateDistanceTravelled(time, speeds[i], startPositions[i]);
//         maxDist = max(maxDist, distanceTravelled);
//         minDist = min(minDist, distanceTravelled);
//     }
//     return maxDist - minDist;
// }

double gapAt(double time, vector<int>& speeds, vector<int>& startPositions) {
    int n = speeds.size();
    vector<double> dist(n, 0.0);
    for(int i = 0; i<n; i++) {
        dist[i] = speeds[i]*time + startPositions[i];
    }
    return (*max_element(dist.begin(), dist.end())) - (*min_element(dist.begin(), dist.end()));
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> speeds(n, 0);
    vector<int> startPositions(n, 0);

    for(int i=0; i<n; i++) {
        cin>>speeds[i]>>startPositions[i];
    }

    double timeStart = 0.0, ans=0.0, timeEnd = k;
    while(timeEnd - timeStart > 1e-10) {
        double m1 = timeStart + (timeEnd - timeStart)/3.0;
        double m2 = timeEnd - (timeEnd - timeStart)/3.0;

        if (gapAt(m1, speeds, startPositions) < gapAt(m2, speeds, startPositions)) 
            timeEnd = m2;
        else
            timeStart = m1;
    }
    ans = gapAt((timeEnd + timeStart)/2, speeds, startPositions); //make this 6 precision double
    cout<<fixed<<setprecision(6)<<ans<<endl;

}
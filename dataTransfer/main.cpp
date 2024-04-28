//
//  main.cpp
//  dataTransfer
//
//  Created by panqj on 3/17/24.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    // map data ids to stations that have the ids.
    unordered_map<int, unordered_set<int>> hash;
    int dataCenterNum = 0, dataCenterId = 1;
    cin >> dataCenterNum;
    while (dataCenterId <= dataCenterNum) {
        int dataSetNum = 0, dataSetId = 0;
        cin >> dataSetNum;
        while (dataSetNum > 0){
            cin >> dataSetId;
            hash[dataSetId].insert(dataCenterId);
            --dataSetNum;
        }
        ++dataCenterId;
    }
    
    // transfer data so that every station has a full copy of the data
    for (unordered_map<int, unordered_set<int>> :: iterator iter = hash.begin(); iter != hash.end(); iter++){
        for (int dataCenterId = 1; dataCenterId <= dataCenterNum; dataCenterId++){
            if (iter->second.find(dataCenterId) == iter->second.end()){
                cout << iter->first << " " << *(iter->second.begin()) << " " << dataCenterId << endl;
            }
        }
    }
    cout << "done" << endl;
    return 0;
}

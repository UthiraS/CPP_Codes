#include <iostream>
// #include <vector>



// int main()
// {

//     std::vector<std::vector<int>> queries;
//     queries = {{1, 2}, {3, 4}};
//     int l,r;
//     for(auto&q :queries)
//     {
//         std::cout<<"Q[O]"<<q[0]<<std::endl;
//         std::cout<<"Q[1]"<<q[1]<<std::endl;
//         l = q[0] - 1; // convert to 0-based index
//         r = q[1] - 1; // convert to 0-based index
//     }
//     std::cout<<"L : "<<l<<"R :"<<r<<std::endl;
//    return 0;

// }


#include <vector>
#include <unordered_map>

std::vector<int> countTeams(std::vector<int>& ratings, int n, std::vector<std::vector<int>>& queries) {
    std::vector<int> results;

    for (auto& q : queries) {
        int l = q[0] - 1; // convert to 0-based index
        int r = q[1] - 1; // convert to 0-based index
        std::cout<<"L : "<<l<<" R :"<<r<<std::endl;
        std::unordered_map<int, int> frequency;

        // Count the frequency of each rating between IDs l and r
        for (int i = l; i <= r; ++i) {
            frequency[ratings[i]]++;
        }

        // Count how many teams can be formed
        int count = 0;
        for (auto& pair : frequency) {
            int members = pair.second;
            // If there are more than one member with the same rating, a team can be formed
            if (members > 1) {
                count += members / 2; // each team consists of 2 members
            }
        }

        results.push_back(count);
    }

    return results;
}
 int main()
 {
    std::vector<int> ratings = {2,3,4,2};
    std::vector<std::vector<int>> queries;
    queries = {{1, 4}, {3, 4}};
    std::vector<int> results = countTeams(ratings,4,queries);
    for (auto& r : results ) 
    {
        std::cout<<r << " ";
    }
 }
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool isMangoSeller(string name)
{
    return name == "thom";
}

bool isPersonCheckedBefore(const unordered_set<string> &checked, string &person)
{
    return checked.find(person) != checked.end();
}


int main()
{

    // implementation of the graph as a hash table (unordered map)
    unordered_map<string, vector<string>> graph;
    graph["you"] = {"bob", "clarie", "alice"};
    graph["clarie"] = {"thom", "jonny"};
    graph["alice"] = {"peggy"};
    graph["bob"] = {"anuj", "peggy"};
    graph["thom"] = {};
    graph["anuj"] = {};
    graph["jonny"] = {};
    graph["peggy"] = {};

    // map to track the shortest path
    unordered_map<string, string> parent;

    // storing the fisrt-degree connections on queue
    queue<string> q;
    for (string person : graph["you"])
    {
        q.push(person);
        parent[person] = "you";
    }

    // set to store the actually checked persons
    unordered_set<string> checked;

    while (!q.empty())
    {
        string person = q.front();

        if (!isPersonCheckedBefore(checked, person))
        {
            checked.insert(person);

            if (isMangoSeller(person))
            {
                cout << person << " is a Mango Seller!" << endl;

                //display shortest path
                vector<string> path;
                string current = person;
                while(current != ""){
                    path.push_back(current);
                    current = parent[current];
                }

                for(int i = path.size()-1; i >= 0; i--){
                    cout << "-->" << path[i];
                }


                return 0;
            }
            else
            {
                for (string neighbor : graph[person])
                {
                    q.push(neighbor);
                    parent[neighbor] = person;
                }
            }
        }
        q.pop();
    }

    cout << "Mango Seller Not Found!" << endl;

    return 0;
}
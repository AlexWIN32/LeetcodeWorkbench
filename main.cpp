#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* ConvertToTree(const vector<string>& Values)
{
    //for more details see https://stackoverflow.com/questions/67324135/how-to-construct-a-binary-tree-from-leetcode-values-list

    if (Values.empty() == true || Values[0] == "null") {
        return nullptr;
    }

    auto* root = new TreeNode();
    root->val = stoi(Values[0]);

    queue<TreeNode*> bfs;
    bfs.push(root);

    int nodeInd = 0;

    while (bfs.empty() == false) {
        auto* node = bfs.front();
        bfs.pop();

        const auto leftInd = nodeInd * 2 + 1;
        if (leftInd < Values.size() && Values[leftInd] != "null") {
            node->left = new TreeNode(stoi(Values[leftInd]));
            bfs.push(node->left);
        }

        const auto rightInd = nodeInd * 2 + 2;
        if (rightInd < Values.size() && Values[rightInd] != "null") {
            node->right = new TreeNode(stoi(Values[rightInd]));
            bfs.push(node->right);
        }

        ++nodeInd;
    }

    return root;
}

int main(int argc, char** argv)
{
	return 0;
}

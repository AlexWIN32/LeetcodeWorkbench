#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* ConvertToList(std::vector<int> data)
{
    auto* head = new ListNode(data[0]);

    auto* n = head;
    for (int i = 1; i < data.size(); i++) {
        n->next = new ListNode(data[i]);
        n = n->next;
    }

    return head;
}

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

/* 2nd wariant of tree creation.
TreeNode* CreateTreeNode(const std::string& NodeString) {
    if (NodeString == "null") {
        return nullptr;
    } else {
        return new TreeNode(std::stoi(NodeString));
    }
}

TreeNode* ConvertToTree(const std::vector<std::string>& data) {
    if (data.empty() == true) {
        return nullptr;
    }

    auto* root = CreateTreeNode(data[0]);

    std::deque<TreeNode*> bfs;
    bfs.push_back(root);

    int i = 1;
    while (i < data.size()) {

        auto* node = bfs.front();
        bfs.pop_front();

        if (node == nullptr) {
            continue;
        }

        if (i < data.size()) {
            node->left = CreateTreeNode(data[i]);
            bfs.push_back(node->left);
            i++;
        }

        if (i < data.size()) {
            node->right = CreateTreeNode(data[i]);
            bfs.push_back(node->right);
            i++;
        }
    }

    return root;
}
*/

int main(int argc, char** argv)
{
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string>

typedef struct TreeNode {
    int val;     // 存放数据域
    struct TreeNode* left;   // 遍历左子树指针
    struct TreeNode* right;   // 遍历右子树指针

}TreeNode, * BitTree;

BitTree CreateLink()
{
    int data;
    int temp;
    BitTree T;

    scanf_s("%d", &data);  // 输入数据
    temp = getchar();   // 吸收空格

    if (data == -1) {   // 输入-1 代表此节点下子树不存数据，也就是不继续递归创建

        return NULL;

    }
    else {
        T = (BitTree)malloc(sizeof(TreeNode));   //  分配内存空间
        T->val = data;        //  把当前输入的数据存入当前节点指针的数据域中

        printf("请输入%d的左子树: ", data);
        T->left = CreateLink();     //  开始递归创建左子树
        printf("请输入%d的右子树: ", data);
        T->right = CreateLink();     //  开始到上一级节点的右边递归创建左右子树
        return T;       //  返回根节点
    }

}

void preOrder(BitTree root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void dfs(struct TreeNode* root, int targetSum, int** res, int* resSize, int* path, int pathSize, int** returnColumnSizes) {
    if (root == NULL) return;
    targetSum -= root->val;
    path[pathSize++] = root->val;
    if (root->left && root->right && targetSum == 0) {
        res[(*resSize)] = (int*)malloc(pathSize * sizeof(int));
        memcpy(res[(*resSize)], path, pathSize * sizeof(int));
        (*returnColumnSizes)[(*resSize)++] = pathSize;
    }
    dfs(root->left, targetSum, res, resSize, path, pathSize, returnColumnSizes);
    dfs(root->right, targetSum, res, resSize, path, pathSize, returnColumnSizes);
    return;
}

int** maxPathSum(struct TreeNode* root,int targetSum,int* returnSize,int** returnColumnSizes) {
    int** res = (int**)malloc(2001 * sizeof(int*));
    int* path = (int*)malloc(2001 * sizeof(int));
    *returnColumnSizes = (int*)malloc(2001 * sizeof(int));
    *returnSize = 0;
    dfs(root, targetSum, res, returnSize, path, 0, returnColumnSizes);
    return res;
}

int main()
{
    BitTree root;
    root = CreateLink();
    int nums[11] = { -10,9,-1,-1,20,15,-1,-1,7,-1,-1 };
    preOrder(root);
    printf("\n");
    int res = maxPathSum(root);
    printf("%d \n", res);

    return 0;
}
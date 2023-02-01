#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string>

typedef struct TreeNode {
    int val;     // ���������
    struct TreeNode* left;   // ����������ָ��
    struct TreeNode* right;   // ����������ָ��

}TreeNode, * BitTree;

BitTree CreateLink()
{
    int data;
    int temp;
    BitTree T;

    scanf_s("%d", &data);  // ��������
    temp = getchar();   // ���տո�

    if (data == -1) {   // ����-1 ����˽ڵ��������������ݣ�Ҳ���ǲ������ݹ鴴��

        return NULL;

    }
    else {
        T = (BitTree)malloc(sizeof(TreeNode));   //  �����ڴ�ռ�
        T->val = data;        //  �ѵ�ǰ��������ݴ��뵱ǰ�ڵ�ָ�����������

        printf("������%d��������: ", data);
        T->left = CreateLink();     //  ��ʼ�ݹ鴴��������
        printf("������%d��������: ", data);
        T->right = CreateLink();     //  ��ʼ����һ���ڵ���ұߵݹ鴴����������
        return T;       //  ���ظ��ڵ�
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
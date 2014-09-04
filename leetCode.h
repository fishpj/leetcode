/*
 * Filename:	leetCode.h
 * Author:		fishpj
 * Date:		08/31/2014
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};
#endif

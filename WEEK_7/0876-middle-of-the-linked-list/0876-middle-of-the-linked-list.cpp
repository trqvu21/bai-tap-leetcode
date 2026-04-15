/**
 * Định nghĩa cấu trúc của một Node trong danh sách liên kết (đề bài cho sẵn)
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=problem-list-v2&envId=w5zahxti
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* truoc = head;
        ListNode* sau = head;

    
        while (sau != nullptr && sau->next != nullptr) {
            
            truoc = truoc->next;      
            sau = sau->next->next; 
        }

       
        return truoc;
    }
};
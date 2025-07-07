/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        Node *middle, *aux, *aux2;
        
        if (head == NULL)
            return true;
        middle = head;
        aux = head;
        while (true)
        {
            aux = aux->next;
            if (aux == NULL)
                break;
            aux = aux->next;
            if (aux == NULL)
                break;
            middle = middle->next;
        }
        aux = middle->next;
        middle->next = NULL;
        middle = aux;
        if (middle == NULL)
            return true;
        aux = NULL;
        while (middle->next != NULL)
        {
            aux2 = middle->next;
            middle->next = aux;
            aux = middle;
            middle = aux2;
        }
        middle->next = aux;
        while (head != NULL && middle != NULL)
        {
            if (head->data != middle->data)
                return false;
            head = head->next;
            middle = middle->next;
        }
        return true;
    }
};
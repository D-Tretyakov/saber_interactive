#include <cstdio>
#include <string>

struct ListNode
{
    ListNode* prev;
    ListNode* next;
    ListNode* rand;
    std::string data;
};

class List
{
public:
    void Serialize(FILE* fp);
    void Deserialize(FILE* fp);

    List(ListNode* head); // Добавил конструктор
    List();

    // Методы для тестов
    ListNode* GetHead() { return m_head; }
    int GetCount() { return m_count; }

private:
    ListNode* m_head;
    ListNode* m_tail;
    int m_count;
};

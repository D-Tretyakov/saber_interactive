#include "LinkedList.hpp"
#include <unordered_map>
#include <vector>

namespace
{
    // Метод сериализации числа
    template <typename T>
    void write_number(std::FILE* fp, T n)
    {
        std::fwrite(reinterpret_cast<const char*>(&n), sizeof(char), sizeof(T), fp);
    }

    // Метод десериализации числа
    template <typename T>
    T read_number(std::FILE* fp)
    {
        const int size = sizeof(T);
        char bytes_in_number[size];
        std::fread(bytes_in_number, sizeof(char), size, fp);
        return *reinterpret_cast<T*>(bytes_in_number);
    }

    // Метод сериализации строчки
    void write_string(std::FILE* fp, std::string& str)
    {
        size_t str_len = str.length();
        // Пишем количество символов в строке
        write_number(fp, str_len);

        // Пишем саму строчку
        std::fwrite(str.data(), sizeof(char), str_len, fp);
    }

    // Метод десериализации строчки
    std::string read_string(std::FILE* fp)
    {
        // Считываем количество символов в строке
        size_t str_len = read_number<size_t>(fp);

        // Считываем непосредственно строку
        char str_char[str_len];
        std::fread(str_char, sizeof(char), str_len, fp);
        return std::string(str_char, str_len);
    }
}

void List::Serialize(FILE* fp)
{
    write_number(fp, m_count);
    for (ListNode* node = m_head; node != nullptr; node = node->next)
    {
        write_string(fp, node->data);
    }

    // Проходим по всем нодам и записываем их индексы
    std::unordered_map<ListNode*, int> indexes;
    int i = 0;
    for (ListNode* node = m_head; node != nullptr; node = node->next)
    {
        indexes[node] = i++;
    }

    // Запишем для каждой ноды номер ноды, на которую она ссылается через random
    for (ListNode* node = m_head; node != nullptr; node = node->next)
    {
        int index = (node->rand) ? indexes[node->rand] : -1;
        write_number(fp, index);
    }
}

void List::Deserialize(FILE* fp)
{
    int count = read_number<int>(fp);
    m_count = count;

    std::vector<ListNode*> nodes(count);

    // Отдельно обработаем первую ноду
    std::string data = read_string(fp);
    ListNode* current_node = new ListNode{ nullptr, nullptr, nullptr, data };
    nodes[0] = current_node;
    m_head = current_node;

    for (int i = 1; i < count; i++)
    {
        data = read_string(fp);
        ListNode* next_node = new ListNode{ nullptr, nullptr, nullptr, data };
        current_node->next = next_node;
        next_node->prev = current_node;

        current_node = next_node;
        nodes[i] = current_node;
    }

    m_tail = current_node;

    // Заполняем ссылки rand
    for (int i = 0; i < count; i++)
    {
        int index = read_number<int>(fp);
        if (index == -1)
            continue;

        nodes[i]->rand = nodes[index];
    }
}

List::List(ListNode* head)
    : m_head(head)
{
    // Не хочу загромождать решение еще проверкой head на nullptr
    // поэтому будем считать, что это на совести пользователя

    int count = 0;
    ListNode* node = m_head;
    while (node != nullptr && node->next != nullptr)
    {
        node = node->next;
        count++;
    }

    m_tail = node;
    m_count = count + 1;
}

List::List()
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_count(0)
{
}
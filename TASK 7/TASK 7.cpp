#include "Header.h"
#include "Header1.h"

template <typename T>
bool for_close(T res, string s)//возвращает номера в порядке возрастания номеров позиций закрывающих скобок

{
    T curr;
    int count_open = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            curr.push(i + 1);
            count_open++;
        }
        if (s[i] == ')' && count_open != 0)
        {
            for (int i = 0; i < count_open - 1; i++)
                curr.push(curr.pop());
            res.push(curr.pop());
            res.push(i + 1);
            count_open--;
        }
    }

    if (res.is_empty())
    {
        cout << "\nВ строке нет парных скобок." << endl;
        return false;
    }

    else
    {
        cout << "\nа) ";
        while (!res.is_empty())
        {
            cout << res.pop() << " ";
            cout << res.pop() << "; ";
        }
        return true;
    }

}

template <typename T> //выводит номера в порядке возрастания номеров позиций открывающих скобок
void for_open(T curr, string s)
{
    int count_open = 0, count_close = 0;
    cout << endl << "б) ";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            count_open++;
            curr.push(i + 1);
        }
        if (s[i] == ')')
        {
            count_close++;
            if (count_close == count_open)
            {
                cout << curr.pop() << " " << i + 1 << "; ";

                while (curr.is_empty() == false)
                {
                    cout << curr.pop() << " ";
                    cout << curr.pop() << "; ";
                }
                count_close = 0;
                count_open = 0;
            }
            else
                curr.push(i + 1);
        }
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №7 \"Применение стека/очереди.\" Тараканова Евгения." << endl << endl;
    int mode;
    cout << "\nПрограмма для каждой пары соответствующих открывающей и закрывающей скобок \nвыводит номера их позиций в тексте в порядке возрастания номеров позиций:\nа)закрывающих скобок\nб)открывающих скобок"
        << "\n\nВыберите реализацию класса \"Очередь\": \n1 - На основе массива\n2 - На основе однонаправленного списка\n--->";
    do
    {
        cin >> mode;
        if (mode < 1 || mode > 2) cout << "Реализации с таким номером нет. Введите корректный номер: ";
    } while (mode < 1 || mode > 2);
    string s;
    cout << "\nВведите выражение: ";
    cin >> s;
    switch (mode)
    {
    case 1:
    {
        Queue_arr res;
        if (for_close(res, s))
            for_open(res, s);
        break;
    }
    case 2:
    {
        Queue_list res;
        if (for_close(res, s))
            for_open(res, s);
        break;
    }
    }
}

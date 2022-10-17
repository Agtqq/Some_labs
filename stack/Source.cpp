#include <iostream>

using namespace std;

class stack2 {

    int data;
    stack2* next;
    int count;

    public:

    stack2* top;

        
    void push(stack2**top) {
       
        cout << "Количество элементов: ";
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            cout << "Введите элемент: ";
            stack2* q;
            q = new stack2();
            int i;
            cin >> i;
            q->data = i;

            q->next = *top;
            *top = q;
        }
    };

    void pop(stack2*top) {
       
        stack2* q = top;
        while (q) { 
            cout<<q->data;
            q = q->next;
        }
        
     };


    void del(stack2** top) {
        cout << "\nСколько элементов удалить: ";
        int kol;
        cin >> kol;
        count = count - kol;
        for(int i=0; i<kol; i++)
           {
            stack2* q = (*top)->next;
            delete(*top);
            *top = q;
           }
    }


    void clean(stack2** top)
    {
        stack2* q;
        do
        {
            q = (*top)->next;
            delete(*top);
            *top = q;
        } while (q);
        cout << "\nПамять очищена";
    }

};



int main() {
    setlocale(LC_ALL, "Russian");
    stack2 stack;
    stack2* top = NULL;
    stack.push(&top);
    cout << "Стек: ";
    stack.pop(top);
    stack.del(&top);
    cout << "Результат удаления: ";
    stack.pop(top);
    stack.clean(&top); 
   
    
    return 0;
}
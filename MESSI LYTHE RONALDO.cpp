#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value, Node* next, Node* prev) : data(value), next(next), prev(prev) {}
};

class List {
    Node* head;
    Node* tail;
    int size;
    int grow1;
    int vydileno;
public:
    List()
    {
        head = tail = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
          
          
        }
        head->prev = newNode;
        head = newNode;
        size++;
        if (vydileno < size)
        {
            vydileno += grow1;
        }
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr, tail);
        if (head == nullptr)
        {
            head = tail = newNode;
            size++;
            
        }
        else {
            tail->next = newNode;
            tail = newNode;
            size++;
           
  
        }

    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforeLast = tail->prev;
        beforeLast->next = nullptr;
        delete tail;
        tail = beforeLast;
        size--;
    }
    void DeleteFromHear()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforeLast = head->next;
        beforeLast->prev = nullptr;
        delete head;
        head = beforeLast;
        size--;
    }

    bool IsEmpty()const
    {
        return head == nullptr;
    }
    void Show()const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->data << " ";
        }cout << "\n";
    }
    void Clear() {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }
    int GetSize() {
        int count = 0;
        Node* oficiant = head;
        while(oficiant != nullptr){
            oficiant = oficiant->next;
            count++;
        }
        cout << count << endl;
        oficiant = nullptr;
        return count;
    }
    void SetSize(int newsize ,int grow = 1)
    {
        grow1 = grow;
      
        if (newsize > size)
        {
            for (int i = size; i < newsize; i++)
            {
                AddToTail(0);
                vydileno = newsize;
                size++;
                


                 
            }
        }
        else if (newsize == size) {
            vydileno = newsize;
            return;
        }
        else
        {
            for (int i = newsize; i <= size; i++)
            {
                DeleteFromTail();
                size--;
                vydileno = newsize;
          
            }
        }
      
    }
    void GetUpperBound() {
        int count = 0;
        Node* oficiant = head;
        while (oficiant->next->data != 0) {
            oficiant = oficiant->next;
            count++;
        }
        cout << "index:" << count << endl;
        oficiant = nullptr;
    }
    int  GetUpperreturn() {
        int count = 0;
        Node* oficiant = head;
        while (oficiant->next != nullptr) {
            oficiant = oficiant->next;
            count++;
        }
        
        return count;
    }
    void FreeExtra() {
  
        while (tail && tail->data == 0) {
            DeleteFromTail();
            size--;
      }
    

    }
    //List& operator=(int sk) {
    //    int count = 0;
    //    int value;

    //    Node* oficiant = head;
    //    oficiant->data = sk;
    //}
    void RemoveAll() {
        Clear();
    }
     int& operator[](int index) {
        int count = 0;
        int value = 0;
        Node* oficiant = head;
        while (index != count) {
            oficiant = oficiant->next;
            count++;
        }
        value= oficiant->data;
        cout << oficiant->data << "\n";
        return value;
       



    }
     void SetAt(int i,int value) {
         if (i > size)
         {
             return;
         }
         int count = 0;
      
         Node* oficiant = head;
         while (i - 1 != count) {
             oficiant = oficiant->next;
             count++;
         }
           oficiant->data = value  ;
        
        

     }
     void rsize()const {
         cout <<"size:" << size << endl;
     }
     void rvidileno()const {
         cout << "vydileno:" << vydileno << endl;
     }
     void  Append( List&arr1 , List& arr2) {

         this->head = arr1.head;
         this->tail = arr1.tail;


         this->tail->next = arr2.head;
         arr2.head->prev = this->tail;
         this->tail = arr2.tail;

    
         this->size = arr1.size + arr2.size;
         this->vydileno = arr1.vydileno + arr2.vydileno;
         arr1.head = nullptr;
         arr2.head = nullptr;
      
     } 
     void Clear2() {
         Node* current = head;
         while (current) {
             Node* next = current->next;
             delete current;
             current = next;
         }
         head = nullptr;
         tail = nullptr;
         size = 0;
         vydileno = 0;
     }




   List& operator =( List& ss) {
       
       if (this->head != nullptr)
       {
           this->Clear();
       }
       
       Node* current = ss.head;
       while (current != nullptr) {
           this->AddToTail(current->data);
           current = current->next;
       }
       return *this;

   }
  void  GetData() {
      cout <<"adresa:" << head << endl;
      
   }
  void InsertAt(int index, int value)
  {

      index--;
      if (index == 0)
      {
          Node* polise = new Node(value, head, nullptr);
          head->prev = polise;
          head = polise;
          size++;
      }
      else if(index >=  size)
      {
          Node* polise = new Node(value, nullptr, tail);
          tail->next = polise;
          tail = polise;
          size++;
      }
      else
      {
          Node* cavaler = head;
          Node* polise = new Node(value, cavaler, nullptr);
          int count = 0;
          while (count != index) {
              cavaler = cavaler->next;
              count++;
          }
          polise->prev = cavaler->prev;
          cavaler->prev->next = polise;
          cavaler->prev = polise;
          polise->next = cavaler;
          size++;
      }

     
  }
  void RemoveAt(int index)
  {
      index--;
      if (index == 0)
      {
          Node* cavaler = head;
          head = head->next;
          delete cavaler;
          size--;
      }
      else if(index == size)
      {
          Node* cavaler = tail;
          tail = tail->prev;
          tail->next = nullptr;
          delete cavaler;
          cavaler = nullptr;
          size--;
      }
      else 
      {
          Node* cavaler = head;
          int count = 0;
          while (count != index) {
              cavaler = cavaler->next;
              count++;
          }
          cavaler->next->prev = cavaler->prev->next;
          cavaler->prev->next = cavaler->next;
          delete cavaler;
          size--;
      }




  }
        
    ~List()
    {
        Clear();
    }
};

int main()
{
    List list;
    List list2;
    List list3;
    List list4;
    //Node sd(55, nullptr, nullptr);
    list.AddToHead(5);
    list.AddToHead(6);
    list.AddToHead(7);
    list.AddToHead(8);
    list2.AddToHead(9);
    list2.AddToHead(9);
    list.Show();
 
    list.SetSize(4, 5);
    list.Show();
    list.rsize();
    list.AddToHead(8);
    list.rsize();
    list.rvidileno();
    
    list4 = list2;
    list4.Show();
    list.GetData();
    list.GetSize();
    list.Show();
    list.RemoveAt(6);
    list.Show();




}
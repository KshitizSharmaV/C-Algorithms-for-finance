//
//  main.cpp
//  My C++ Projects
//
//  Created by Kshitiz Sharma on 16/03/18.
//  Copyright © 2018 Kshitiz Sharma. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class Order_Book{
    list<int> id_book;
    list<double> price_book;
    public:
    
        void Buy(int order_id, double price){
            id_book.push_back(order_id);
            price_book.push_back(price);
        }
    
        void Sell(int order_id){
            
            list<double>::iterator it1 = price_book.begin();
            list<int>::iterator it2 = id_book.begin();
            
            for(; it1 != price_book.end() && it2 != id_book.end(); ++it1, ++it2)
            {   cout << *it2 <<"\n";
                if(*it2 == order_id){
                    id_book.erase(it2);
                    price_book.erase(it1);
                }
            }
        }
    
        void ShowOrderBook(){
            cout << "Show Order Book \n";
            
            if(price_book.empty()){
                cout<<"The Order Book is empty \n";
                return;
            }
            
            list<double>::iterator it1 = price_book.begin();
            list<int>::iterator it2 = id_book.begin();
            cout << "ID" <<"\t"<< "Price" <<"\n";
            for(; it1 != price_book.end() && it2 != id_book.end(); ++it1, ++it2)
            {
                cout << *it2<<"\t"<< *it1 <<"\n";
            }
        }
    
        double MaxPrice(){
            double max=0;
            cout << max << "\n" ;
            return 0.0;
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int temp =0;
    int id_order=0;
    double price_order=0.0;
    char input;
    Order_Book ob;
    
    do{
        cout <<"Enter the order id \t";
        cin >> id_order;
        
        cout <<"Enter B(buy) or S(sell)";
        cin >> input;
        
        if(input == 'B') {
            cout <<"Enter the price of the order \t";
            cin >> price_order;
            ob.Buy(id_order,price_order);
        } else{
            ob.Sell(id_order);
        }
        ob.ShowOrderBook();
        cout<<"Want to execute a second order ? Enter 1 else 0 \n";
        cin >> temp;
        
    }while(temp == 1);
    
    return 0;
}





